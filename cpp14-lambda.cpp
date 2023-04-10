#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    // lambda with auto
    auto generic_sum = [](const auto& a, const auto& b) { return a + b; };
    int int_sum = generic_sum(3, 4);
    double double_sum = generic_sum(3.5, 4.5);
    std::cout << "lambda - int sum: " << int_sum << ", double sum: " << double_sum << std::endl;

    // Lambda capture expression with initializer
    int x = 5;
    auto capture_lambda = [y = x * 2] { return y; };
    std::cout << "Lambda capture expression with initializer: " << capture_lambda() << std::endl;

    // Use lambda with STL algorithms
    std::vector<double> numbers = {5.5, 1.1, 4.4, 2.2, 3.3};
    std::sort(numbers.begin(), numbers.end(), [](const auto& a, const auto& b) { return a < b; });

    std::cout << std::endl;

    return 0;
}

