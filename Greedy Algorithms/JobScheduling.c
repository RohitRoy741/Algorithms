#include <stdio.h>
#include <stdlib.h>
typedef struct job
{
    int id;
    int deadline;
    int profit;
} Job;
int Partition(Job a[], int p, int r)
{
    Job pivot = a[r];
    int j = p;
    int i = p - 1;
    while (j < r)
    {
        if (a[j].profit >= pivot.profit)
        {
            i++;
            Job temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
        j++;
    }
    Job temp = a[i + 1];
    a[i + 1] = a[r];
    a[r] = temp;
    return i + 1;
}
void QuickSort(Job a[], int p, int r)
{
    if (p < r)
    {
        int q = Partition(a, p, r);
        QuickSort(a, p, q - 1);
        QuickSort(a, q + 1, r);
    }
}
int JobSelector(Job a[], int n, int deadlines[], int max)
{
    int p = 0;
    QuickSort(a, 0, n - 1);
    printf("\nSorted Jobs:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i].id);
    }
    Job *result = (Job *)malloc(sizeof(Job) * n);
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        int x = a[i].deadline;
        for (int j = x; j > 0; j--)
        {
            if (deadlines[j] == 0)
            {
                deadlines[j] = 1;
                result[index++] = a[i];
                p += a[i].profit;
                break;
            }
        }
    }
    printf("\nJobs Scheduled:\n");
    for (int i = 0; i < index; i++)
    {
        printf("%d ", result[i].id);
    }
    return p;
}
int main()
{
    int n;
    printf("Enter the number of jobs: ");
    scanf("%d", &n);
    Job *a = (Job *)malloc(sizeof(Job) * n);
    int m = INT_MIN;
    printf("Enter the profit and deadline of job\n");
    for (int i = 0; i < n; i++)
    {
        a[i].id = i + 1;
        printf("Job %d:\n", i + 1);
        printf("Profit: ");
        scanf("%d", &a[i].profit);
        printf("Deadline: ");
        scanf("%d", &a[i].deadline);
        if (a[i].deadline > m)
            m = a[i].deadline;
    }
    int *deadlines = (int *)malloc(sizeof(int) * (m + 1));
    for (int i = 0; i < m; i++)
    {
        deadlines[i] = 0;
    }
    int profit = JobSelector(a, n, deadlines, m + 1);
    printf("\nProfit = %d", profit);
    return 0;
}