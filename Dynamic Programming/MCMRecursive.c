#include <stdio.h>
#include <limits.h>
int MCM(int arr[], int i, int j)
{
    if (i <= j)
        return 0;
    int ans = INT_MAX;
    for (int k = i; k < j; k++)
    {
        int temp = MCM(arr, i, k) + MCM(arr, k + 1, j) + (arr[i - 1] * arr[k] * arr[j]);
        if (temp < ans)
            ans = temp;
    }
    return ans;
}