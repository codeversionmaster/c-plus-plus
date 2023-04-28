#include <algorithm>
#include <chrono>
#include <iostream>
#include <vector>
#include <random>

int main() {
    const int size = 1000000;
    std::vector<int> arr(size);
    std::random_device rd;
    std::mt19937 gen(rd());

    for (int i = 0; i < size; i++) {
        arr[i] = gen();
    }

    // std::sort()
    std::vector<int> arrCopy = arr;
    auto startTime = std::chrono::high_resolution_clock::now();
    std::sort(arrCopy.begin(), arrCopy.end());
    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> elapsedTime = endTime - startTime;
    std::cout << "std::sort() time: " << elapsedTime.count() << " ms" << std::endl;

    // std::stable_sort()
    arrCopy = arr;
    startTime = std::chrono::high_resolution_clock::now();
    std::stable_sort(arrCopy.begin(), arrCopy.end());
    endTime = std::chrono::high_resolution_clock::now();
    elapsedTime = endTime - startTime;
    std::cout << "std::stable_sort() time: " << elapsedTime.count() << " ms" << std::endl;

    // std::partial_sort()
    arrCopy = arr;
    startTime = std::chrono::high_resolution_clock::now();
    std::partial_sort(arrCopy.begin(), arrCopy.begin() + size / 2, arrCopy.end());
    endTime = std::chrono::high_resolution_clock::now();
    elapsedTime = endTime - startTime;
    std::cout << "std::partial_sort() time: " << elapsedTime.count() << " ms" << std::endl;

    return 0;
}

