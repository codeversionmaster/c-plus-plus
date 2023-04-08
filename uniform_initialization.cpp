#include <iostream>
#include <vector>
#include <map>
#include <tuple>
#include <optional>
#include <variant>
#include <tuple>
#include <memory>
using namespace std;

class Sample {
public:
    Sample(int x, double y) : x_(x), y_(y) {}
    void print() { cout << "Sample: x=" << x_ << ", y=" << y_ << endl; }

private:
    int x_; double y_;
};

struct Point { int x; int y; };

// Function that takes an aggregate type as an argument using brace initialization
void print_point(const Point& p) {
    cout << "Point: x=" << p.x << ", y=" << p.y << endl;
}

// Function that returns an aggregate type using brace initialization
Point create_point(int x, int y) {
    return {x, y};
}

int main() {
    // Built-in types
    int a{42};
    double b{3.14};
    cout << "a: " << a << ", b: " << b << endl;

    // User-defined types
    Sample obj{10, 2.7};
    obj.print();

    // STL containers
    vector<int> vec{1, 2, 3, 4, 5};
    cout << "Vector: ";
    for (const auto& v : vec) {
        cout << v << " ";
    }
    cout << endl;

    map<string, int> mapping{
        {"one", 1},
        {"two", 2},
        {"three", 3},
    };
    cout << "Map: ";
    for (const auto& [key, value] : mapping) {
        cout << key << "=" << value << " ";
    }
    cout << endl;

    // Aggregate initialization
    Point p1{3, 4};
    print_point(p1);

    // Function argument and return value initialization
    Point p2 = create_point(7, 9);
    print_point(p2);

    // Initializer list
    auto sum = [](initializer_list<int> numbers) {
        int total = 0;
        for (const auto& num : numbers) {
            total += num;
        }
        return total;
    };

    int total = sum({1, 2, 3, 4, 5});
    cout << "Sum: " << total << endl;

    // Array initialization
    int arr[]{1, 2, 3, 4, 5};
    cout << "Array: ";
    for (const auto& v : arr) {
        cout << v << " ";
    }
    cout << endl;

    // pair and tuple initialization
    pair<int, string> my_pair{1, "one"};
    cout << "Pair: " << my_pair.first << ", " << my_pair.second << endl;

    tuple<int, double, string> my_tuple{1, 3.14, "hello"};
    cout << "Tuple: " << get<0>(my_tuple) << ", " << get<1>(my_tuple) << ", " << get<2>(my_tuple) << endl;

    // variant initialization with braces
    variant<int, double, string> my_variant{42};

    // brace initialization in std::optional
    optional<int> my_optional{42};

    // usage of braces in unique_ptr and shared_ptr initializations
    unique_ptr<int> my_unique_ptr{new int{42}};
    shared_ptr<int> my_shared_ptr{new int{42}};

    // initialization of array
    array<int, 5> my_array{1, 2, 3, 4, 5};

    // lambda captures using brace initialization
    int x = 42;
    auto my_lambda = [x{move(x)}]() { return x; };

    return 0;
}

