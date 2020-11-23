#include <stdio.h>
#include <stdlib.h>
#define MAX 1000
typedef struct node
{
    int data;
    struct node *next;
} Node;
typedef struct q
{
    Node *head;
    int size;
} Queue;
typedef struct graph
{
    int n;
    Node *edges[MAX];
    char color[MAX];
    int parent[MAX];
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
            printf("| %d |", curr->data);
        }
    }
}
void Enqueue(Queue *q, int element)
{
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = element;
    temp->next = NULL;
    // if (q->head == NULL)
    // {
    //     printf("2. %d\n", q->head->data);
    //     q->head = temp;
    //     q->size = 1;
    //     return;
    // }
    Node *curr = q->head, *prev = NULL;
    while (curr != NULL)
    {
        prev = curr;
        curr = curr->next;
    }
    if (prev != NULL)
    {
        prev->next = temp;
    }
    else
    {

        q->head = temp;
    }

    q->size++;
}
int Dequeue(Queue *q)
{
    if (q->size == 0)
    {
        return -1;
    }
    int element = q->head->data;
    Node *temp = q->head;
    q->head = q->head->next;
    free(temp);
    q->size--;
    return element;
}
void BFS(Graph *g, int source)
{
    printf("\nBFS Traversal:\n");
    for (int i = 0; i < g->n; i++)
    {
        g->color[i] = 'w';
        g->parent[i] = 0;
    }
    g->color[source - 1] = 'g';
    Queue q;
    q.head = NULL;
    q.size = 0;
    Enqueue(&q, source);
    while (q.size > 0)
    {
        int u = Dequeue(&q);
        Node *curr = g->edges[u - 1];
        while (curr != NULL)
        {
            int v = curr->data;
            if (g->color[v - 1] == 'w')
            {
                Enqueue(&q, v);
                g->color[v - 1] = 'g';
                g->parent[v - 1] = u;
            }
            curr = curr->next;
        }
        g->color[u - 1] = 'b';
        printf("%d->", u);
    }
    printf("END");
}
void PrintPath(Graph *g, int s, int v)
{
    if (v == s)
        printf("%d->", v);
    else if (g->parent[v - 1] == 0)
    {
        printf("\nThere is no path from %d to %d", s, v);
    }
    else
    {
        PrintPath(g, s, g->parent[v - 1]);
        printf("%d->", v);
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
    BFS(&g, 1);
    printf("\n");
    int source, dest;
    printf("\nEnter source: ");
    scanf("%d", &source);
    printf("Enter destination: ");
    scanf("%d", &dest);
    PrintPath(&g, source, dest);
    printf("DONE");
    return 0;
}