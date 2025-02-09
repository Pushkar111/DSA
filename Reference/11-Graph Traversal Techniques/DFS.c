#include <stdio.h>
#define size 10
int queue[size], visited[size];
int front = -1, rear = -1;
struct Graph
{
    int adjmatrix[size][size];
};
void initGraph(struct Graph *graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            graph->adjmatrix[i][j] = 0;
    }
}
void addEdge(struct Graph *graph, int src, int dest, int n)
{
    if (src >= 0 && src < n && dest >= 0 && dest < n)
    {
        graph->adjmatrix[src][dest] = 1;
        graph->adjmatrix[dest][src] = 1;
    }
}
void printGraph(struct Graph *graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", graph->adjmatrix[i][j]);
        printf("\n");
    }
}

void DFS(struct Graph *graph, int totalvertices, int start)
{
    printf("%d ", start);
    visited[start] = 1;
    for (int i = 0; i < totalvertices; i++)
    {
        if (graph->adjmatrix[start][i] == 1 && visited[i] != 1)
            DFS(graph, totalvertices, i);
    }
}
int main()
{
    struct Graph graph;
    int totalvertices, edges, start;
    printf("Enter Number of Vertices:");
    scanf("%d", &totalvertices);
    for (int i = 0; i < totalvertices; i++)
    {
        queue[i] = 0;
        visited[i] = 0;
    }
    initGraph(&graph, totalvertices);
    printf("Enter Number of edges:");
    scanf("%d", &edges);
    for (int i = 1; i <= edges; i++)
    {
        int src, dest;
        printf("Enter edge %d (source destination): ", i);
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest, totalvertices);
    }
    printGraph(&graph, totalvertices);
    printf("Enter The starting Vertex:");
    scanf("%d", &start);
    printf("DFS Traversal:");
    DFS(&graph, totalvertices, start);
}