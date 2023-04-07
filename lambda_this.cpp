#include <iostream>
#include <future>
#include <thread>
#include <chrono>

class Increment {
    private:
        int count;

    public:
        Increment(int start_count) : count(start_count) {}

	void increment(int value) {
	    count += value;
	}

	// Here this would store the this pointer of object of current context
        void async_increment(int value) {
            auto task = [this, value] {
		this->increment(value);
            };
       
	    // Launch the async task 
            std::future<void> result = std::async(std::launch::async, std::move(task));
	    // Wait for the async task to complete
            result.wait();
            std::cout << "Incremented count: " << count << '\n';
    }
};

int main() {
    Increment counter(0);
    counter.async_increment(5);
    return 0;
}

