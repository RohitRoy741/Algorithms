#include <stdio.h>
#define MAX_SIZE 10000
int t[MAX_SIZE + 1];
void init()
{
    t[0] = 0;
    t[1] = 1;
    for (int i = 1; i < MAX_SIZE + 1; i++)
    {
        t[i] = -1;
    }
}
int LIS_AUX(int A[], int n, int *max_ref)
{
    if (t[n] != -1)
        return t[n];
    t[n] = 1;
    for (int i = 1; i < n; i++)
    {
        int res = LIS_AUX(A, i, max_ref);
        if (A[i - 1] < A[n - 1] && res + 1 > t[n])
            t[n] = res + 1;
    }
    if (*max_ref < t[n])
        *max_ref = t[n];
    return t[n];
}
int LIS(int A[], int n)
{
    int max = 1;
    LIS_AUX(A, n, &max);
    return max;
}