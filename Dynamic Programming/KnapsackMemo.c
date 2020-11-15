#include <stdio.h>
#define MAX_SIZE 10000
int t[MAX_SIZE + 1][MAX_SIZE + 1];
int max(int a, int b)
{
    return a > b ? a : b;
}
void init()
{
    for (int i = 0; i < MAX_SIZE + 1; i++)
    {
        for (int j = 0; j < MAX_SIZE + 1; j++)
        {
            if (i == 0 || j == 0)
                t[i][j] = 0;
            else
                t[i][j] = -1;
        }
    }
}
int Knapsack(int v[], int w[], int W, int n)
{
    if (t[n][W] != -1)
        return t[n][W];
    if (w[n - 1] <= W)
        return t[n][W] = max(v[n - 1] + Knapsack(v, w, W - w[n - 1], n - 1), Knapsack(v, w, W, n - 1));
    else
        return t[n][W] = Knapsack(v, w, W, n - 1);
}