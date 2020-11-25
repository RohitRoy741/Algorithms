#include <stdio.h>
#include <stdlib.h>
float minimum(float a, float b)
{
    return a < b ? a : b;
}
typedef struct item
{
    int id;
    float profit;
    float weight;
} Item;
int partition(Item a[], int p, int r)
{
    Item pivot = a[r];
    int j = p;
    int i = p - 1;
    while (j < r)
    {
        if ((a[j].profit / a[j].weight) >= (pivot.profit / pivot.weight))
        {
            i++;
            Item temp = a[j];
            a[j] = a[i];
            a[i] = temp;
        }
        j++;
    }
    Item temp = a[i + 1];
    a[i + 1] = a[r];
    a[r] = temp;
    return i + 1;
}
void QuickSort(Item a[], int p, int r)
{
    if (p < r)
    {
        int q = partition(a, p, r);
        QuickSort(a, p, q - 1);
        QuickSort(a, q + 1, r);
    }
}
float Knapsack(Item a[], int n, float W)
{
    float profit = 0.0;
    QuickSort(a, 0, n - 1);
    printf("\nSorted Items\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i].id);
    }
    int index = 0;
    while (W > 0)
    {
        float w = minimum(a[index].weight, W);
        profit = profit + (w * (a[index].profit / a[index].weight));
        W = W - w;
        index++;
    }
    return profit;
}
int main()
{
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    Item *a = (Item *)malloc(sizeof(Item) * n);
    printf("Enter the profits and weights of item\n");
    for (int i = 0; i < n; i++)
    {
        a[i].id = i + 1;
        printf("Item %d\n", i + 1);
        printf("Profit: ");
        scanf("%f", &a[i].profit);
        printf("Weight: ");
        scanf("%f", &a[i].weight);
    }
    float W;
    printf("Enter the weight of Knapsack: ");
    scanf("%f", &W);
    printf("\nMaximum Profit = %.2f", Knapsack(a, n, W));
    return 0;
}