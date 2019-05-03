//  jpkc simple power moduli implementation
//  base^exp = X (Mod m)

#include <iostream>

using namespace std;

int Mod(int base, int exp, int m) {
    unsigned long int tmp = 1;
    for (unsigned int i = 0; i < exp; ++i) {
        tmp *= base;
        tmp %= m;
    }
    return tmp;
}

int main(int , char **)
{
    unsigned long int base, exp, m;

    base = 415;
    exp = 0;
    m = 517;

    cout << base << "^" << exp << " = X (mod " << m << ")\nX = " << Mod(base, exp, m) << endl;

    base = 415;
    exp = 1;
    m = 517;

    cout << base << "^" << exp << " = X (mod " << m << ")\nX = " << Mod(base, exp, m) << endl;

    base = 415;
    exp = 577;
    m = 517;

    cout << base << "^" << exp << " = X (mod " << m << ")\nX = " << Mod(base, exp, m) << endl;

    base = 2;
    exp = 8;
    m = 512;

    cout << base << "^" << exp << " = X (mod " << m << ")\nX = " << Mod(base, exp, m) << endl;

    base = 2;
    exp = 577;
    m = 512;

    cout << base << "^" << exp << " = X (mod " << m << ")\nX = " << Mod(base, exp, m) << endl;

    return 0;
}
