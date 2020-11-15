#include <stdio.h>
#define MAX_SIZE 1000
int t[MAX_SIZE];
void init()
{
    for (int i = 0; i < 1000; i++)
        t[i] = -1;
    t[0] = 0;
    t[1] = 1;
}
int Fibonacci(int n)
{
    if (t[n] != -1)
        return t[n];
    return t[n] = Fibonacci(n - 1) + Fibonacci(n - 2);
}
