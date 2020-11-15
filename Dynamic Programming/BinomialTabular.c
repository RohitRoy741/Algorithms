#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10000
int Binomial(int n, int k)
{
    int t[MAX_SIZE + 1][MAX_SIZE + 1];
    for (int i = 0; i < n + 1; i++)
    {
        for (int j = 0; j < k + 1; j++)
        {
            if (j < i)
                t[i][j] = 0;
            else if (j == 0 || j == i)
                t[i][j] = 1;
            else
                t[i][j] = t[i - 1][j] + t[i - 1][j - 1];
        }
    }
}