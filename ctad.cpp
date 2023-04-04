/* Program to illustrate ctad concept of C++ 17 */

#include <iostream>
using namespace std;

template <class T, class U>
class Display {
    T first;
    U second;
    
    public:
    
        Display(T arg1, U arg2):first(arg1),second(arg2) {}
        
        void print() {
            cout << "first = " << first << " second = " << second << "\n";
        }
};

int main()
{
    //Display<int, float> display(1, 2.1); //Prior to C++ 17
    Display display(1, 2.1);  //From C++ 17
    display.print();
}
