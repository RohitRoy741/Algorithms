#include <stdio.h>
#define MAX_SIZE 10000
int max(int a, int b)
{
    return a > b ? a : b;
}
int Knapsack(int v[], int w[], int W, int n)
{
    int t[MAX_SIZE + 1][MAX_SIZE + 1];
    for (int i = 0; i < MAX_SIZE + 1; i++)
    {
        for (int j = 0; j < MAX_SIZE + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else if (w[i - 1] <= j)
            {
                t[i][j] = max(v[i - 1] + t[i][j - w[i - 1]], t[i - 1][j]);
            }
            else
                t[i][j] = t[i - 1][j];
        }
    }
    return t[n][W];
}