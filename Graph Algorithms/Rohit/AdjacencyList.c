#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct node
{
    int data;
    struct node *next;
} Node;
typedef struct graph
{
    int n;
    Node *edges[MAX];
} Graph;
void CreateGraph(Graph *g, int n)
{
    g->n = n;
    for (int i = 0; i < n; i++)
    {
        int number_of_edges;
        printf("Enter number of edges from vertex %d: ", i + 1);
        scanf("%d", &number_of_edges);
        g->edges[i] = NULL;
        printf("Enter the vertices in adjacency list of %d:\n", i + 1);
        Node *curr;
        for (int j = 0; j < number_of_edges; j++)
        {
            printf("->: ");
            int data;
            scanf("%d", &data);
            Node *temp = (Node *)malloc(sizeof(Node));
            temp->data = data;
            temp->next = NULL;
            if (g->edges[i] == NULL)
            {
                curr = temp;
                g->edges[i] = temp;
            }
            else
            {
                curr->next = temp;
                curr = temp;
            }
        }
        curr->next = NULL;
    }
}
void PrintGraph(Graph g)
{
    printf("\nAdjacency List representation:\n");
    for (int i = 0; i < g.n; i++)
    {
        printf("\n%d->", i + 1);
        for (Node *curr = g.edges[i]; curr != NULL; curr = curr->next)
        {
            printf("|%d|", curr->data);
        }
    }
}
int main()
{
    Graph g;
    int n;
    printf("Enter the number of vertices in graph: ");
    scanf("%d", &n);
    CreateGraph(&g, n);
    PrintGraph(g);
    return 0;
}