#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;

void sample_function(const vector<int>& numbers, const function<void(int)>& func) {
    for (int number : numbers) {
        func(number);
    }
}

int main() {
    vector<int> numbers = {3, 2, 4, 1, 5};

    // 1. As a function object
    auto printnum = [](int number) { cout << number << " "; };
    printnum(21);
    cout << endl;

    // 2. As an argument for another function, also taking variables from surrounding
    int multiplier = 2;
    sample_function(numbers, [multiplier](int number) { cout << number * multiplier << " "; });
    cout << endl;

    // 3. Using as comparator in STL algorithms
    sort(numbers.begin(), numbers.end(), [](int a, int b) { return a < b; });
    for (int number : numbers) {
        cout << number << " ";
    }
    cout << endl;

    return 0;
}

