/*
            1
          /   \-
         2     ---- 6
       /            |
      /        5    |
     /          \   /
    3------------ 4



index	src	dest
0	    1	2
1	    1	6
2	    2	3
3	    2	1
4	    3	4
5	    3	2
6	    4	5
7	    4	3
8	    4	6
9	    5	4
10	    6	4
11	    6	1

totalVertices : 6
totalEdges : 6

Each Edge (src dest):
1	2
1	6
2	3
3	4
4	5
4	6


*/

#include <stdio.h>
#define SIZE 10
int visited[SIZE];

struct Graph
{
    int a[SIZE][SIZE];
};

void initGraph(struct Graph *graph, int totalVertices)
{
    for (int i = 0; i < totalVertices; i++)
    {
        for (int j = 0; j < totalVertices; j++)
        {
            graph->a[i][j] = 0;
        }
    }
}

void addEdge(struct Graph *graph, int src, int dest, int totalVertices)
{
    if (src >= 0 && src < totalVertices && dest >= 0 && dest < totalVertices)
    {
        graph->a[src][dest] = 1;
        graph->a[dest][src] = 1;
    }
}

void printGraph(struct Graph *graph, int totalVertices)
{
    for (int i = 0; i < totalVertices; i++)
    {
        for (int j = 0; j < totalVertices; j++)
        {
            printf("%d ", graph->a[i][j]);
        }
        printf("\n");
    }
}

void DFS(struct Graph *graph, int totalVertices, int start)
{
    printf("%d ", start);
    visited[start] = 1;

    for (int i = 0; i < totalVertices; i++)
    {
        if (graph->a[start][i] == 1 && visited[i] != 1)
        {
            DFS(graph, totalVertices, i);
        }
    }
}

int main()
{
    struct Graph graph;
    int totalVertices, totalEdges, start;

    printf("\nEnter Number of Vertices : ");
    scanf("%d", &totalVertices);

    for (int i = 0; i < totalVertices; i++)
    {
        visited[i] = 0;
    }

    initGraph(&graph, totalVertices);

    printf("\nEnter Number of Edges : ");
    scanf("%d", &totalEdges);

    for (int i = 1; i <= totalEdges; i++)
    {
        int src, dest;
        printf("\nEnter edge %d (source destination) : ", i);
        scanf("%d %d", &src, &dest);
        addEdge(&graph, src, dest, totalVertices);
    }

    printGraph(&graph, totalVertices);

    printf("\nEnter The starting Vertex : ");
    scanf("%d", &start);

    printf("\nDFS Traversal : ");
    printf("\n-------------------------------------\n");
    DFS(&graph, totalVertices, start);

    // Check for unvisited vertices and perform DFS on them
    for (int i = 1; i <= totalVertices; i++)
    {
        if (visited[i] == 0)
        {
            DFS(&graph, totalVertices, i);
        }
    }
    return 0;
}
