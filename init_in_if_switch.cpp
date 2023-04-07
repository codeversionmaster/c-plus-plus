#include <iostream>

int valueone() {
    return 1;
}

int main() {
    // Using an init statement in an if statement
    if (auto it = valueone() * 2; it == 2) {
        std::cout << "it is 2" << std::endl;
    }

    // Using an init statement in a switch statement
    switch (int it = valueone() * 2; it) {
        case 2:
            std::cout << "it is 2" << std::endl;
            break;
        default:
            std::cout << "default" << std::endl;
            break;
    }

    return 0;
}

