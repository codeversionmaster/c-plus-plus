#include <iostream>
#include <thread>
#include <mutex>
#include <atomic>

std::mutex mtx;
std::atomic<int> count(0);

int main() {
    // Thread 1
    std::thread t1([&]() {
        std::lock_guard<std::mutex> lock(mtx);
        count++;
        std::cout << "Counter incremented by thread 1 to " << count << std::endl;
    });

    // Thread 2
    std::thread t2([&]() {
        std::lock_guard<std::mutex> lock(mtx);
        count++;
        std::cout << "Counter incremented by thread 2 to " << count << std::endl;
    });

    t1.join();
    t2.join();

    std::cout << "Final count value: " << count << std::endl;

    return 0;
}

