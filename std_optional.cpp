#include <iostream>
#include <optional>
#include <vector>
using namespace std;

optional<int> first_negative(const vector<int>& numbers) {
    for (const auto& num : numbers) {
        if (num < 0) {
            return num;
        }
    }

    // If no negative number found, return nullopt
    return nullopt;
}

int main() {
    vector<int> numbers{-1, 2, 3, -4, 5};

    auto result = first_negative(numbers);

    // 1. Use operator* and operator-> to print value in the optional.
    cout << "Using operator*: " << *result << endl;

    // 2. Use operator bool() to check if result has meaningfule value
    if (result) {
        cout << "Optional contains a value." << endl;
    } else {
        cout << "Optional is empty." << endl;
    }

    // 3. has_value(): Check if the optional contains a value.
    if (result.has_value()) {
        cout << "Optional has a value using has_value(): " << *result << endl;
    } else {
        cout << "Optional is empty using has_value()." << endl;
    }

    // 4. value(): Access the value stored in the optional or throw an exception.
    try {
        cout << "Value using value(): " << result.value() << endl;
    } catch (const bad_optional_access& e) {
        cout << "Exception caught: " << e.what() << endl;
    }

    // 5. value_or(T): Access the value stored in the optional, or return the provided default value.
    cout << "Value using value_or(): " << result.value_or(0) << endl;

    return 0;
}

