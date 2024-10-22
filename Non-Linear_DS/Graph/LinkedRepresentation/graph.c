#include <stdio.h>
#include <stdlib.h>

struct node
{
    int vertex; // int data
    struct node *next;
};

struct Graph
{
    int TotalVertex;
    struct node *a;
};

struct node *createNode(int v)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->vertex = v;
    temp->next = NULL;
    return temp;
}

struct Graph *createGraph(int v)
{
    struct Graph *g = (struct Graph *)malloc(sizeof(struct Graph));

    g->TotalVertex = v;
    g->a = malloc(v * sizeof(struct node));

    for (int i = 0; i < v; i++)
    {
        g->a[i].next = NULL;
    }

    return g;
}

void addEdge(struct Graph *g, int source, int dest)
{
    struct node *temp;

    // for source to destination
    temp = createNode(dest);
    temp->next = g->a[source].next;
    g->a[source].next = temp;

    // for destination to source
    temp = createNode(source);
    temp->next = g->a[dest].next;
    g->a[dest].next = temp;
}

void displayGraph(struct Graph *g)
{
    for (int i = 0; i < g->TotalVertex; i++)
    {
        struct node *temp = g->a[i].next;

        while (temp != NULL)
        {
            printf("%d -> %d\n", i, temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int v = 4;

    struct Graph *g = createGraph(v);

    /*

    0-------3
    |       |        ==> V : {0, 1, 2, 3}
    |       |        ==> E : {0-1, 0-3, 1-2, 2-3}
    1-------2

    */

    addEdge(g, 0, 1);
    addEdge(g, 0, 3);
    addEdge(g, 1, 2);
    addEdge(g, 2, 3);

    displayGraph(g);

    return 0;
}