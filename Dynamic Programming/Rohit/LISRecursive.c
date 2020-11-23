#include <stdio.h>
int LIS_AUX(int A[], int n, int *max_ref)
{
    int max_ending = 1;
    for (int i = 1; i < n; i++)
    {
        int res = LIS_AUX(A, i, max_ref);
        if (res + 1 > max_ending && A[i - 1] < A[n - 1])
            max_ending = res + 1;
    }
    if (*max_ref < max_ending)
        *max_ref = max_ending;
    return max_ending;
}
int LIS(int A[], int n)
{
    int max = 0;
    LIS_AUX(A, n, &max);
    return max;
}