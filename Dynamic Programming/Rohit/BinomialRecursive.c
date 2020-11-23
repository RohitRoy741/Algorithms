#include <stdio.h>
int Binomial(int n, int k)
{
    if (k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
    return Binomial(n - 1, k - 1) + Binomial(n - 1, k);
}