#include <iostream>
#include <string>
#include <functional>

int main() {
    std::hash<int> int_hash;
    int num = 21;
    std::size_t num_hash = int_hash(num);
    std::cout << "Hash value for " << num << " is: " << num_hash << std::endl;

    std::hash<std::string> string_hash;
    std::string word = "hello";
    std::size_t word_hash = string_hash(word);
    std::cout << "Hash value for \"" << word << "\" is: " << word_hash << std::endl;

    return 0;
}

