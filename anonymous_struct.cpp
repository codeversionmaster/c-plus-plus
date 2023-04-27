#include <iostream>
using namespace std;

/* 
 * Useful for readability when it is just onetime or within file use
 */

struct {
    int i;
    float j;
} s;

int main()
{
    
    s.i = 1;
    s.j = 1.2;

    cout << "s.i is " << s.i << " s.j is " << s.j << endl;

    struct {
        int i;
	float j;
    } k;

    k.i = 2;
    k.j = 2.2;

    cout << "k.i is " << k.i << " k.j is " << k.j << endl;

    return 0;
}
