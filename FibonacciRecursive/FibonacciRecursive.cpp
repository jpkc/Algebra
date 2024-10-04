#include <iostream>
#include "FibonacciRecursive.h"

FibonacciRecursive::FibonacciRecursive(int x)
{
    if (x < 1)
        std::cout << "Fibonacci(" << x << ") is undefined" << std::endl;
    else
        std::cout << "Fibonacci(" << x << ") = " << Recursion(x) << std::endl;
}

FibonacciRecursive::~FibonacciRecursive() {}

int FibonacciRecursive::Recursion(int x)
{
    if (x <= 2)
        return 1;
    else
        return Recursion(x - 1) + Recursion(x - 2);
}
