#include <stdio.h>
#include <stdlib.h>
typedef struct activity
{
    int id;
    int start;
    int finish;
} Activity;
int Partition(Activity a[], int p, int r)
{
    Activity pivot = a[r];
    int j = p;
    int i = p - 1;
    while (j < r)
    {
        if (a[j].finish <= pivot.finish)
        {
            i++;
            Activity temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
        j++;
    }
    Activity temp = a[i + 1];
    a[i + 1] = a[r];
    a[r] = temp;
    return i + 1;
}
void QuickSort(Activity a[], int p, int r)
{
    if (p < r)
    {
        int q = Partition(a, p, r);
        QuickSort(a, p, q - 1);
        QuickSort(a, q + 1, r);
    }
}
void ActivitySelector(Activity a[], int m, int n, Activity result[], int *k)
{
    while (m < n && a[m].start < result[*k].finish)
    {
        m++;
    }
    if (m < n)
    {
        result[*k + 1] = a[m];
        *k = *k + 1;
        ActivitySelector(a, m, n, result, k);
    }
}
int main()
{
    int n;
    printf("Enter the number of activities: ");
    scanf("%d", &n);
    Activity *a = (Activity *)malloc(sizeof(Activity) * n);
    Activity *result = (Activity *)malloc(sizeof(Activity) * n);
    printf("Enter the start and finish times of activities: ");
    for (int i = 0; i < n; i++)
    {
        a[i].id = i + 1;
        printf("Activity %d\n", i + 1);
        printf("Start time: ");
        scanf("%d", &a[i].start);
        printf("Finish time: ");
        scanf("%d", &a[i].finish);
    }
    QuickSort(a, 0, n - 1);
    printf("\nSorted Activities:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i].id);
    }
    result[0] = a[0];
    int index = 0;
    ActivitySelector(a, 1, n, result, &index);
    printf("\nActivities Scheduled:\n");
    for (int i = 0; i <= index; i++)
    {
        printf("%d ", result[i].id);
    }
    return 0;
}