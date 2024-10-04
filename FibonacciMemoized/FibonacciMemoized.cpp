#include "FibonacciMemoized.h"
#include <iostream>

void FibonacciMemoized::ini(int new_capacity)
{
    if (new_capacity > 0)
    {
        lookup_Table.reserve(new_capacity);
        for (; lookup_Table.size() < lookup_Table.capacity(); lookup_Table.push_back(0))
            ;
        if (initialized == false)
        {
            lookup_Table[1] = 1;
            lookup_Table[2] = 2;
            initialized = true;
        }
    }
}

FibonacciMemoized::FibonacciMemoized(int x)
{
    if (initialized == false || lookup_Table.capacity() <= x)
        ini(2 * (x + 1));

    if (x < 1)
        std::cout << "Fibonacci(" << x << ") is undefined" << std::endl;
    else
    {
        if (lookup_Table[x] == 0)
        {
            lookup_Table[x] = Recurssion(x - 1) + Recurssion(x - 2);
        }
        std::cout << "Fibonacci(" << x << ") = " << lookup_Table[x] << std::endl;
    }
}

FibonacciMemoized::~FibonacciMemoized() {}

int FibonacciMemoized::Recurssion(int x)
{
    if (x <= 2)
        return 1;
    else
    {
        if (lookup_Table[x] == 0)
        {
            lookup_Table[x] = Recurssion(x - 1) + Recurssion(x - 2);
        }
        return lookup_Table[x];
    }
}
