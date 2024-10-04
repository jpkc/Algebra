#ifndef FIBONACCIMEMOIZED_H
#define FIBONACCIMEMOIZED_H
#pragma once

#include <vector>

class FibonacciMemoized
{
public:
    FibonacciMemoized(int x = 0);
    ~FibonacciMemoized();

private:
    std::vector<int> lookup_Table;
    bool initialized = false;
    void ini(int new_capacity = 512);
    int Recurssion(int x);
};

#endif
