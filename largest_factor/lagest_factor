#include <iostream>
#include <cmath>

using namespace std;

unsigned long long LargestPrimeFactor(unsigned long long n) {
    unsigned long largest, n0, max;

    if(n == 0) {
        return 0;
    }

    n0 = n;
    largest = 1;
    while(n0%2 == 0) {
        largest = 2;
        n0 >>= 1;
    }

    max = sqrt(n0) + 1;
    for(unsigned long i = 3; i <= max; i += 2) {
        while(n0%i == 0) {
            largest = i;
            n0/=i;
            max = n0;
            max = sqrt(n0) + 1;
        }
    }
    if(largest == 1)
        return n;

    return (largest > n0) ? largest : n0;
}

int main(int , char **) {
    int cases;
    unsigned long long num;
    cin >> cases;
    while(cases--) {
        cin >> num;
        cout << LargestPrimeFactor(num) << endl;
    }
    return 0;
}

