#include <stdio.h>
#define MAX_SIZE 10000
int LIS(int A[], int n)
{
    int max = 1;
    int t[MAX_SIZE + 1];
    t[0] = 0;
    for (int i = 1; i < n + 1; i++)
        t[i] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 1; j < i; j++)
        {
            if (t[j] + 1 > t[i] && A[j - 1] < A[i - 1])
                t[i] = t[j + 1];
        }
        max = max < t[i] ? t[i] : max;
    }
    return max;
}