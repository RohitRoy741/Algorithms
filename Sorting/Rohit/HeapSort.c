#include <stdio.h>
#include <stdlib.h>
// int Parent(i)
// {
//     return i / 2;
// }
int Left(int i)
{
    return 2 * i;
}
int Right(int i)
{
    return 2 * i + 1;
}
void MaxHeapify(int A[], int i, int size)
{
    int l = Left(i);
    int r = Right(i);
    int largest = i;
    if (l < size && A[l] > A[i])
        largest = l;
    if (r < size && A[r] > A[largest])
        largest = r;
    if (largest != i)
    {
        int temp = A[i];
        A[i] = A[largest];
        A[largest] = temp;
        MaxHeapify(A, largest, size);
    }
}
void BuildMaxHeap(int A[], int size)
{
    for (int i = (size - 1) / 2; i >= 0; i--)
    {
        MaxHeapify(A, i, size);
    }
}
void HeapSort(int A[], int size)
{
    BuildMaxHeap(A, size);
    for (int i = size - 1; i > 0; i--)
    {
        int temp = A[i];
        A[i] = A[0];
        A[0] = temp;
        MaxHeapify(A, 0, i);
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