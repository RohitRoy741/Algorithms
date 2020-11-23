#include <stdio.h>
int max(int a, int b)
{
    return a > b ? a : b;
}
int Knapsack(int v[], int w[], int W, int n)
{
    if (n == 0 || W == 0)
        return 0;
    if (w[n - 1] <= W)
        return max(v[n - 1] + Knapsack(v, w, W - w[n - 1], n - 1), Knapsack(v, w, W, n - 1));
    else
        return Knapsack(v, w, W, n - 1);
}