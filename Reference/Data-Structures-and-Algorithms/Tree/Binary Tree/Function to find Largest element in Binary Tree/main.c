#include <stdio.h>

int main() {
    printf("Hello, World!\n");
    return 0;
}



// defining the structure of Binary Tree Node
struct node
{
    struct node *left;
    int data;
    struct node *right;
};



// function to Find Maximum element in Binary Tree
int FindMax(struct node *root)
{
    int root_val, left, right, max;
    if (root != NULL) {
        root_val = root->data;
        left = FindMax(root->left);
        right = FindMax(root->right);

        if(left > right)
            max = left;
        else
            max = right;

        if(root_val > max)
            max = root_val;

    }
    return max;
}
