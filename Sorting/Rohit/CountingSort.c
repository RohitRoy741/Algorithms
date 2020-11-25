#include <stdio.h>
#include <stdlib.h>
int Max(int A[], int n)
{
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}
void CountingSort(int A[], int size)
{
    int k = Max(A, size);
    int *C = (int *)malloc(sizeof(int) * (k + 1));
    int *B = (int *)malloc(sizeof(int) * size);
    for (int i = 0; i <= k; i++)
    {
        C[i] = 0;
    }
    for (int i = 0; i < size; i++)
    {
        C[A[i]]++;
    }
    for (int i = 1; i <= k; i++)
    {
        C[i] = C[i] + C[i - 1];
    }
    for (int i = size - 1; i >= 0; i--)
    {
        B[C[A[i]] - 1] = A[i];
        C[A[i]]--;
    }
    for (int i = 0; i < size; i++)
    {
        A[i] = B[i];
    }
}
int main()
{
    int size;
    printf("Enter the size of array: ");
    scanf("%d", &size);
    int *array = (int *)malloc(sizeof(int) * size);
    printf("Enter the elements of array\n");
    for (int i = 0; i < size; i++)
    {
        printf("Element %d: ", i + 1);
        scanf("%d", &array[i]);
    }
    printf("The array you entered:\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\nSorted Array:\n");
    CountingSort(array, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}