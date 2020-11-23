#include <stdio.h>
#include <limits.h>
#define MAX 10000
int t[MAX + 1][MAX + 1];
void init()
{
    for (int i = 0; i < MAX + 1; i++)
    {
        for (int j = 0; j < MAX + 1; j++)
        {
            if (i >= j)
                t[i][j] = 0;
            else
            {
                t[i][j] = -1;
            }
        }
    }
}
int MCM(int arr[], int i, int j)
{
    if (t[i][j] != -1)
        return t[i][j];
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        t[i][j] = MCM(arr, i, k) + MCM(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        if (t[i][j] < ans)
            ans = t[i][j];
    }
    return ans;
}