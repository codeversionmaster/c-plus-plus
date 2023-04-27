#include <iostream>
using namespace std;

/* 
 * Without this compiler would throw error as below
 * namespace-scope anonymous aggregates must be static
 * This is only for global ananymous union
 * This helps encapsulation as well as avoid clashes across
 * translation units (files) trying to same names by mistake
 */

static union {
    int i;
    float j;
};

int main()
{
    
    j = 1.2;
    cout << "j is " << j << endl;

    i = 3;
    cout << "i is " << i << endl;

    union {
        int ii;
	float jj;
    };

    jj = 1.2;
    cout << "jj is " << jj << endl;

    ii = 3;
    cout << "ii is " << ii << endl;

    return 0;
}
