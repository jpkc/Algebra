#include "FibonacciMemoized.h"

int main(int argc, char **argv)
{
    for (int i = -10; i < 45; ++i)
        FibonacciMemoized f(i);

    return 1;
}
