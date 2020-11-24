#include <stdio.h>
#include <stdlib.h>
void InsertionSort(int A[], int size)
{
    for (int j = 1; j < size; j++)
    {
        int key = A[j];
        int i = j - 1;
        while (i >= 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            i--;
        }
        A[i + 1] = key;
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
    InsertionSort(array, size);
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}
