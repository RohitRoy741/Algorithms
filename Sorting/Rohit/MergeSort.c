#include <stdio.h>
#include <stdlib.h>
void PrintArray(int A[], int size)
{
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
void Merge(int A[], int p, int q, int r)
{
    int size1 = q - p + 1;
    int size2 = r - q;
    int *L = (int *)malloc(sizeof(int) * (size1 + 1));
    int *R = (int *)malloc(sizeof(int) * (size2 + 1));
    int i, j, index;
    for (i = 0; i < size1; i++)
    {
        L[i] = A[p + i];
    }
    L[i] = INT_MAX;
    for (i = 0; i < size2; i++)
    {
        R[i] = A[q + i + 1];
    }
    R[i] = INT_MAX;
    i = 0, j = 0, index = p;
    while (index <= r)
    {
        if (L[i] < R[j])
            A[index++] = L[i++];
        else
            A[index++] = R[j++];
    }
}
void MergeSort(int A[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        MergeSort(A, p, q);
        MergeSort(A, q + 1, r);
        Merge(A, p, q, r);
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
    MergeSort(array, 0, size - 1);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}