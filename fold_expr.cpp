#include <iostream>

template <typename... Args>
auto calculate_product(Args... args) {
    auto ret = (args * ...);
    return ret;
}

int main() {
    int product;
   
    product = calculate_product(2, 3, 4, 5);
    std::cout << "Product is " << product << std::endl;

    product = calculate_product(2, 3, 4, 5, 6);
    std::cout << "Product is " << product << std::endl;
    return 0;
}

