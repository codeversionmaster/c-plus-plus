#include <iostream>
#include <stdexcept>
#include <functional>

class Finally {
public:
    Finally(std::function<void()> func) : m_func(func) {}
    ~Finally() { m_func(); }

private:
    std::function<void()> m_func;
};

int main() {
    try {
        Finally onExit([] { std::cout << "This line will always be executed." << std::endl; });

        int numerator = 10;
        int denominator = 0;

        if (denominator == 0) {
            throw std::runtime_error("Division by zero");
        }

        int result = numerator / denominator;
        std::cout << "Result: " << result << std::endl;
    } catch (const std::exception &e) {
        std::cout << "Exception: " << e.what() << std::endl;
    }

    return 0;
}

