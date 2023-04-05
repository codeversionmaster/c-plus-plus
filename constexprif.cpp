/* Program to demonstrate constexpr if usage */
#include <iostream>
using namespace std;

template <typename T>
constexpr auto intdensify(T x) {
    // if constexpr (std::is_integral_v<T> && x == 0) { // will not compile
    if constexpr (std::is_integral_v<T>) { // this will compile as it is constant expression
        return x * x;
    } else {
        return x;
    }
}

int main() {
    int x;
    std::cout << "Enter x" << endl;
    std::cin >> x;
    // value of x is known at runtime, so code converts to return x * x at compile time
    std::cout << intdensify(x) << std::endl; 
    // keeps 16 at compile time itself  and prints 16
    std::cout << intdensify(4) << std::endl;
    // prints 1.5 and evaluates only at run time
    std::cout << intdensify(1.5) << std::endl;
    return 0;
}

