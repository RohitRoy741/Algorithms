#include <stdio.h>
int max(int a, int b)
{
    return a > b ? a : b;
}
int LCS(int A[], int B[], int m, int n)
{
    if (n == 0 || m == 0)
        return 0;
    if (A[m - 1] == B[n - 1])
        return 1 + LCS(A, B, m - 1, n - 1);
    else
        return max(LCS(A, B, m - 1, n), LCS(A, B, m, n - 1));
}