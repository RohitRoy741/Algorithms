#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
int time = 0;
typedef struct node
{
    int data;
    struct node *next;
} Node;
typedef struct graph
{
    int n;
    Node *edges[MAX];
    char color[MAX];
    int parent[MAX];
    int d[MAX];
    int f[MAX];
} Graph;
typedef struct TopologicalSorting
{
    Node *head;
} TS;
TS list;
void Push(int data)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    if (list.head == NULL)
    {
        list.head = temp;
    }
    else
    {
        temp->next = list.head;
        list.head = temp;
    }
}
void CreateGraph(Graph *g, int n)
{
    g->n = n;
    for (int i = 0; i < n; i++)
    {
        int number_of_edges;
        printf("Enter number of edges from vertex %d: ", i);
        scanf("%d", &number_of_edges);
        g->edges[i] = NULL;
        printf("Enter the vertices in adjacency list of %d:\n", i);
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
        printf("\n%d->", i);
        for (Node *curr = g.edges[i]; curr != NULL; curr = curr->next)
        {
            printf("| %d |", curr->data);
        }
    }
}
void DFS_VISIT(Graph *g, int u)
{
    time += 1;
    g->color[u] = 'g';
    g->d[u] = time;
    for (Node *curr = g->edges[u]; curr != NULL; curr = curr->next)
    {
        if (g->color[curr->data] == 'w')
        {
            g->parent[curr->data] = u;
            DFS_VISIT(g, curr->data);
        }
    }
    time++;
    g->f[u] = time;
    g->color[u] = 'b';
    Push(u);
}
void DFS(Graph *g)
{
    list.head = NULL;
    for (int i = 0; i < g->n; i++)
    {
        g->color[i] = 'w';
        g->parent[i] = -1;
    }
    time = 0;
    for (int i = 0; i < g->n; i++)
    {
        if (g->color[i] == 'w')
        {
            DFS_VISIT(g, i);
        }
    }
}
int main()
{
    Graph g;
    int n;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    CreateGraph(&g, n);
    PrintGraph(g);
    DFS(&g);
    printf("\nTopologically Sorted graph:\n");
    for (Node *curr = list.head; curr != NULL; curr = curr->next)
    {
        printf("%d->", curr->data);
    }
    printf("NULL");
    return 0;
}
