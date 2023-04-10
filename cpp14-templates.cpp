#include <iostream>
#include <type_traits>

// Variable template for pi
template<typename T>
constexpr T pi = T(3.1415926535897932385);

// Function template with std::enable_if_t
template<typename T, std::enable_if_t<std::is_arithmetic<T>::value, int> = 0>
T multiply_pi(T value) {
    return value * pi<T>;
}

int main() {
    int int_val = 3;
    double double_val = 3.5;

    // Use variable template for pi
    std::cout << "Value of pi (float): " << pi<float> << std::endl;
    std::cout << "Value of pi (double): " << pi<double> << std::endl;

    // Use std::enable_if_t in a function template
    std::cout << "3 * pi (integer): " << multiply_pi(int_val) << std::endl;
    std::cout << "3.5 * pi (double): " << multiply_pi(double_val) << std::endl;

    return 0;
}

