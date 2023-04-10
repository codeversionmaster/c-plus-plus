#include <iostream>
#include <complex>
#include <thread>
#include <chrono>

int main() {
    // Binary literals
    int binary_literal = 0b101010;
    std::cout << "Binary literal: " << binary_literal << std::endl;

    // Digit separators
    int large_number = 1'234'567;
    std::cout << "Large number with digit separators: " << large_number << std::endl;

    // Standard user-defined literals for time
    using namespace std::literals::chrono_literals;
    auto duration = 500ms;
    std::cout << "Duration: " << duration.count() << " milliseconds" << std::endl;

    // Standard user-defined literals for complex numbers
    using namespace std::literals::complex_literals;
    auto complex_number = 3.0 + 4.0i;
    std::cout << "Complex number: " << complex_number << std::endl;

    // Sleep for the duration using std::this_thread::sleep_for
    std::cout << "Sleeping for " << duration.count() << " milliseconds..." << std::endl;
    std::this_thread::sleep_for(duration);
    std::cout << "After sleep!" << std::endl;

    return 0;
}

