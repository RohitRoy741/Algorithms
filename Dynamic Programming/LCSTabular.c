#include <stdio.h>
#define MAX_SIZE 10000
int max(int a, int b)
{
    return a > b ? a : b;
}
int LCS(int A[], int B[], int m, int n)
{
    int t[MAX_SIZE + 1][MAX_SIZE + 1];
    for (int i = 0; i < m + 1; i++)
    {
        for (int j = 0; j < n + 1; j++)
        {
            if (i == 0 || j == 0)
            {
                t[i][j] = 0;
            }
            else
            {
                if (A[i - 1] == B[j - 1])
                    t[i][j] = 1 + t[i - 1][j - 1];
                else
                {
                    t[i][j] = max(t[i - 1][j], t[i][j - 1]);
                }
            }
        }
    }
    return t[m][n];
}