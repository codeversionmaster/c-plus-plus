// inline_variables.cpp
#include <iostream>
#include "inline_variables.h"
using namespace std;

int main() {
    cout << "Static member variable is: " << IVClass::static_member_variable << endl;
    cout << "Global variable is: " << global_variable << endl;
    return 0;
}

