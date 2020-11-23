#include <stdio.h>
#include <limits.h>
#include <stdlib.h>
#define SOURCE 0
#define MAX_CITIES 10000
int cost[MAX_CITIES][MAX_CITIES] = {0};
int TSP(int source, int set[], int n)
{
    //If queue is empty return distance to source
    if (n == 0)
    {
        return cost[source][SOURCE];
    }
    int min = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int temp_set[MAX_CITIES];
        int index1 = 0, index2 = 0;
        while (index1 < n)
        {
            if (index1 == i)
            {
                index1++;
            }
            else
            {
                temp_set[index2++] = set[index1++];
            }
        }
        int res = cost[source][set[i]] + TSP(set[i], temp_set, index2);
        if (res < min)
            min = res;
    }
    return min;
}
int main()
{
    int n;
    printf("\nEnter the number of cities: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("Enter the distance from city %d to %d: ", i + 1, j + 1);
            scanf("%d", &cost[i][j]);
        }
    }
    int *set = (int *)malloc(sizeof(int) * n);
    for (int i = 1; i < n; i++)
    {
        set[i - 1] = i;
    }
    int result = TSP(SOURCE, set, n - 1);
    printf("Cost of TSP = %d", result);
    return 0;
}