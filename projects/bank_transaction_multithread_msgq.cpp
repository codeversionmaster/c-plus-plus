#include <iostream>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>
#include <random>
#include <chrono>
#include <atomic>

constexpr int NUM_ACCOUNTS = 5;
constexpr int NUM_TRANSACTIONS = 10;
constexpr int NUM_THREADS = 2;

class Bank {
public:
    Bank(int num_accounts) : accounts(num_accounts, 1000) {}

    void transfer(int from, int to, int amount) {
        if (from != to && accounts[from] >= amount) {
            accounts[from] -= amount;
            accounts[to] += amount;
        }
    }

    void print_balances() {
        for (size_t i = 0; i < accounts.size(); ++i) {
            std::cout << "Account " << i << ": " << accounts[i] << std::endl;
        }
    }

private:
    std::vector<int> accounts;
};

struct Transaction {
    int from;
    int to;
    int amount;
};

std::queue<Transaction> transaction_queue;
std::mutex transaction_mutex;
std::condition_variable transaction_cv;
std::atomic<bool> done{false};

void process_transactions(Bank &bank) {
    while (!done.load() || !transaction_queue.empty()) {
        std::unique_lock<std::mutex> lock(transaction_mutex);
        transaction_cv.wait(lock, [] { return !transaction_queue.empty() || done.load(); });

        if (!transaction_queue.empty()) {
            Transaction transaction = transaction_queue.front();
            transaction_queue.pop();

            bank.transfer(transaction.from, transaction.to, transaction.amount);
            std::cout << "Transferred " << transaction.amount << " from account " << transaction.from << " to account " << transaction.to << std::endl;

            lock.unlock();
            transaction_cv.notify_all();
        }
    }
}

int main() {
    Bank bank(NUM_ACCOUNTS);
    std::thread workers[NUM_THREADS];

    for (int i = 0; i < NUM_THREADS; ++i) {
        workers[i] = std::thread(process_transactions, std::ref(bank));
    }

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> account_dist(0, NUM_ACCOUNTS - 1);
    std::uniform_int_distribution<> amount_dist(1, 100);

    for (int i = 0; i < NUM_TRANSACTIONS; ++i) {
        int from = account_dist(gen);
        int to = account_dist(gen);
        int amount = amount_dist(gen);

        std::unique_lock<std::mutex> lock(transaction_mutex);
        transaction_queue.push({from, to, amount});
        lock.unlock();
        transaction_cv.notify_all();

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    done.store(true);
    transaction_cv.notify_all();

    for (auto &worker : workers) {
        worker.join();
    }

    std::cout << "\nFinal account balances:\n";
    bank.print_balances();

    return 0;
}

