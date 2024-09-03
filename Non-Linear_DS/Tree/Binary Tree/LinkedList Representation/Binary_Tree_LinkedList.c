/*
1) root           -> Top Most node
2) node           -> Each element in Binary Tree is node
3) Parent & Child -> node considered as parent when node consists left and right child
4) Leaf           -> node which does not have any child
    ↓
  (External / Terminal)
5) SubTree        -> set of nodes which are connected with root
6) Depth          -> Number of edges in the path from root to that node
7) Height         -> Maximum number of edges in the path from root to any leaf node
8) Sibling        -> nodes which have same parent
9) Degree         -> no of Direct children

==> Binary Tree   -> Tree of Degree 2
                    (nodes can have 0, 1, 2 children)
                  -> Ideal for representing hierarchical data
                  -> n nodes => edges ==> n-1

    ==> Types of Binary Trees
        ---------------------
                                Types
                                  |
                    -------------------------------
*/

#include <stdio.h>
#include <stdlib.h>

struct node
{
  int data;
  struct node *left;
  struct node *right;
};

struct node *createNode(int data)
{
  struct node *temp;
  temp = (struct node *)malloc(sizeof(struct node));
  temp->data = data;
  temp->left = NULL;
  temp->right = NULL;

  return temp;
}

void printTree(struct node *root)
{
  if (root == NULL)
  {
    return;
  }
  static int cnt = 1;
  printf("\nnode %d : %d", cnt, root->data);
  cnt++;

  if (root->left != NULL)
  {
    printf("\n\t Left child of %d is %d", root->data, root->left->data);
  }

  if (root->left != NULL)
  {
    printf("\n\t Right child of %d is %d", root->data, root->right->data);
  }
 
}

int main()
{
  struct node *root = createNode(1);

  struct node *leftChild = createNode(2);

  struct node *rightChild = createNode(3);

  root->left = leftChild;
  root->right = rightChild;

  printTree(root);

  return 0;
}