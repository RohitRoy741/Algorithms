#include <stdio.h>
#include <stdlib.h>
int Parent(int i)
{
    return i / 2;
}
int Left(int i)
{
    return 2 * i;
}
int Right(int i)
{
    return 2 * i + 1;
}
void MinHeapify(int A[], int i, int size)
{
    int l = Left(i);
    int r = Right(i);
    int smallest = i;
    if (l < size && A[l] < A[i])
        smallest = l;
    if (r < size && A[r] < A[smallest])
        smallest = r;
    if (smallest != i)
    {
        int temp = A[i];
        A[i] = A[smallest];
        A[smallest] = temp;
        MinHeapify(A, smallest, size);
    }
}
void BuildMinHeap(int A[], int size)
{
    for (int i = (size - 1) / 2; i >= 0; i--)
        MinHeapify(A, i, size);
}
void HeapSort(int A[], int size)
{
    BuildMinHeap(A, size);
    for (int i = size - 1; i > 0; i--)
    {
        int temp = A[0];
        A[0] = A[i];
        A[i] = temp;
        MinHeapify(A, 0, i);
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
    HeapSort(array, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    return 0;
}