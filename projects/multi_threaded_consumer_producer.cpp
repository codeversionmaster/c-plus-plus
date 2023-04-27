#include <iostream>
#include <queue>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <atomic>
#include <chrono>

constexpr int MAX_BUFFER_SIZE = 10;
constexpr int NUM_PRODUCERS = 2;
constexpr int NUM_CONSUMERS = 2;
constexpr int NUM_ITERATIONS = 10;

std::queue<int> buffer;
std::mutex buffer_mutex;
std::condition_variable buffer_cv;
std::atomic<bool> done{false};

void producer(int id) {
    for (int i = 0; i < NUM_ITERATIONS; ++i) {
        std::unique_lock<std::mutex> lock(buffer_mutex);

        buffer_cv.wait(lock, [] { return buffer.size() < MAX_BUFFER_SIZE; });

        int value = id * NUM_ITERATIONS + i;
        buffer.push(value);
        std::cout << "Producer " << id << " produced: " << value << std::endl;

        lock.unlock();
        buffer_cv.notify_all();

        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void consumer(int id) {
    while (!done.load() || !buffer.empty()) {
        std::unique_lock<std::mutex> lock(buffer_mutex);

        buffer_cv.wait(lock, [] { return !buffer.empty() || done.load(); });

        if (!buffer.empty()) {
            int value = buffer.front();
            buffer.pop();
            std::cout << "Consumer " << id << " consumed: " << value << std::endl;

            lock.unlock();
            buffer_cv.notify_all();

            std::this_thread::sleep_for(std::chrono::milliseconds(10));
        }
    }
}

int main() {
    std::thread producers[NUM_PRODUCERS];
    std::thread consumers[NUM_CONSUMERS];

    for (int i = 0; i < NUM_PRODUCERS; ++i) {
        producers[i] = std::thread(producer, i);
    }

    for (int i = 0; i < NUM_CONSUMERS; ++i) {
        consumers[i] = std::thread(consumer, i);
    }

    for (auto &producer_thread : producers) {
        producer_thread.join();
    }

    done.store(true);
    buffer_cv.notify_all();

    for (auto &consumer_thread : consumers) {
        consumer_thread.join();
    }

    return 0;
}

