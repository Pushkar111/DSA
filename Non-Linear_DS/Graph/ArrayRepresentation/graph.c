#include <stdio.h>
#include <stdlib.h>
#define VERTEX 4

void createGraph(int a[VERTEX][VERTEX]) // initialize
{ 
    for (int i = 0; i < VERTEX; i++)
    {
        for (int j = 0; j < VERTEX; j++)
        {
            a[i][j] = 0;
        }
    }
}

void createEdge(int a[VERTEX][VERTEX], int i, int j) // insertEdge
{
    a[i][j] = 1;
    a[j][i] = 1;
}

void displayGraph(int a[VERTEX][VERTEX])
{
    for (int i = 0; i < VERTEX; i++)
    {
        for (int j = 0; j < VERTEX; j++)
        {
            printf("%d\t", a[i][j]);
        }
        printf("\n");
    }
}

void printConnectedEdges(int a[VERTEX][VERTEX], int userVertex)
{
    if (userVertex < 0 || userVertex >= VERTEX)
    {
        printf("Invalid Vertex");
    }
    else
    {
        int flag = 0;
        for (int i = 0; i < VERTEX; i++)
        {
            if (a[userVertex][i] == 1)
            {
                printf("%d -> %d\n", userVertex, i);
                flag = 1;
            }
        }

        if (flag == 0)
        {
            printf("No edges connected with vertex %d\n", userVertex);
        }
    }
}

int main()
{
    int a[VERTEX][VERTEX];

    createGraph(a);

    /*

    0-------3
    |       |        ==> V : {0, 1, 2, 3}
    |       |        ==> E : {0-1, 0-3, 1-2, 2-3}
    1-------2 

    */
    createEdge(a, 0, 1);
    createEdge(a, 0, 3);
    createEdge(a, 1, 2);
    createEdge(a, 2, 3);

    displayGraph(a);

    printConnectedEdges(a, 0);
    printConnectedEdges(a, 1);
    printConnectedEdges(a, 2);
    printConnectedEdges(a, 3);

    return 0;

}