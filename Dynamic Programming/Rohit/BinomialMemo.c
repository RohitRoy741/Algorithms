#include <stdio.h>
#define MAX_SIZE 1000
int t[MAX_SIZE + 1][MAX_SIZE + 1];
void init()
{
    for (int i = 0; i < MAX_SIZE + 1; i++)
    {
        for (int j = 0; j < MAX_SIZE + 1; j++)
        {
            if (j > i)
                t[i][j] = 0;
            else if (j == 0 || j == i)
                t[i][j] = 1;
            else
                t[i][j] = -1;
        }
    }
}
int Binomial(int n, int k)
{
    if (t[n][k] != -1)
        return t[n][k];
    else
    {
        return t[n][k] = Binomial(n - 1, k) + Binomial(n - 1, k - 1);
    }
}