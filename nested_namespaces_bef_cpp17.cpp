#include <iostream>
using namespace std;

namespace A {
    int a = 1;

    namespace B {
        int b = 2;

        namespace C {
            int c = 3;
        }
    }
}

int main() {
    cout << "A::a: " << A::a << endl;
    cout << "A::B::b: " << A::B::b << endl;
    cout << "A::B::C::c: " << A::B::C::c << endl;

    return 0;
}

