#include <iostream>
using namespace std;

int globali;

int &sample_function()
{
    /* 
     * Reference to local variable not possible.
     * As the caller would need to use it 
     */

     /* 
      * int i = 2;
      * return i;
      */

     return globali;
}

int main()
{
    sample_function() = 10; 
    cout << "globali is " << globali << endl;

    return 0;
}
