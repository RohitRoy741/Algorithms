#include <stdio.h>
#include <stdlib.h>
int partition(int a[], int p, int r)
{
    int pivot = a[r];
    int j = p;
    int i = p - 1;
    while (j < r)
    {
        if (a[j] >= pivot)
        {
            i++;
            int temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
        j++;
    }
    int temp = a[i + 1];
    a[i + 1] = a[r];
    a[r] = temp;
    return i + 1;
}
int QuickSort(int a[], int p, int r)
{
    if (p < r)
    {
        int q = partition(a, p, r);
        QuickSort(a, p, q - 1);
        QuickSort(a, q + 1, r);
    }
}
int main()
{
    int n;
    printf("Enter the number of denominations: ");
    scanf("%d", &n);
    int *denominations = (int *)malloc(sizeof(int) * n);
    printf("Enter the denominations: ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &denominations[i]);
    }
    QuickSort(denominations, 0, n - 1);
    printf("\nSorted order:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", denominations[i]);
    }
    printf("\n");
    int v;
    printf("Enter the value: ");
    scanf("%d", &v);
    int *ans = (int *)malloc(sizeof(int) * v);
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        while (v >= denominations[i])
        {
            ans[index++] = denominations[i];
            v = v - denominations[i];
        }
    }
    if (v == 0)
    {
        printf("\nNumber of coins required = %d", index);
        printf("\nCoins:\n");
        for (int i = 0; i < index; i++)
            printf("%d ", ans[i]);
    }
    else
    {
        printf("Not Possible");
    }
    return 0;
}