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
            {
                t[i][j] = -1;
            }
        }
    }
}
int LCS(int A[], int B[], int m, int n)
{
    if (t[m][n] != -1)
        return t[m][n];
    if (A[m - 1] == B[n - 1])
        return t[m][n] = 1 + LCS(A, B, m - 1, n - 1);
    else
    {
        return t[m][n] = max(LCS(A, B, m - 1, n), LCS(A, B, m, n - 1));
    }
}