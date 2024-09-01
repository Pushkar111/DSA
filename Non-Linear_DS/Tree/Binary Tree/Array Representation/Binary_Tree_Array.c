#include <stdio.h>
#include <stdlib.h>

int getParent(int index)
{
    return (index - 1) / 2;
}

int getLeftChild(int index)
{
    return 2 * index + 1;
}

int getRightChild(int index)
{
    return 2 * index + 2;
}

void printTree(int tree[], int SIZE)
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("\nnode %d : %d", i, tree[i]);

        if (getLeftChild(i) < SIZE)
        {
            printf("\nLeftChild : %d", tree[getLeftChild(i)]);
        }
        if (getRightChild(i) < SIZE)
        {
            printf("\nRightChild : %d", tree[getRightChild(i)]);
        }
        printf("\n");
    }
}

int main()
{
    int tree[] = {1, 2, 3, 4, 5, 6, 7};
    int SIZE = sizeof(tree) / sizeof(int);

    printTree(tree, SIZE);
    return 0;
}