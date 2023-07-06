#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

class Semaphore
{
	std::mutex mutexval;
	std::condition_variable conditionval;
	int count;

	public:
		explicit Semaphore(int countval):count(countval) {}
	
		void acquire()
		{	
			unique_lock<mutex> lock(mutexval);
			conditionval.wait(lock, [this] { return count > 0; });
			count--;
			cout << "count is: " << count << endl;
		}

		void release()
		{
			lock_guard<mutex> lock(mutexval);
			count++;
			conditionval.notify_one();
		}
};

int sharedResource = 0;
Semaphore semaphore(3);

void workerThread()
{
	semaphore.acquire();
	
	++sharedResource;
	cout << "Thread ID: " << this_thread::get_id() << " sharedResource: " << sharedResource << endl;
	this_thread::sleep_for(2000ms);
	semaphore.release();
}

int main()
{
	const int numThreads = 5;
	std::thread threads[numThreads];

	for(int i = 0; i < numThreads; ++i)
	{
		threads[i] = std::thread(workerThread);
	}

	for(int i = 0; i < numThreads; ++i)
	{
		threads[i].join();
	}

	return 0;
}
