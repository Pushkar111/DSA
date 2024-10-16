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

==> Traversal in Binary Tree
    1) pre-order
        root -> left subtree -> right subtree
    2) post-order
       left subtree -> right subtree -> root
    3) in-order
       left subtree -> root -> right subtree

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
  struct node *node;
  node = (struct node *)malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;

  return node;
}

void preOrder(struct node *root)
{
  if (root != NULL)
  {
    printf("%d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
  }
}

void postOrder(struct node *root)
{
  if (root != NULL)
  {
    postOrder(root->left);
    postOrder(root->right);
    printf("%d ", root->data);
  }
}

void inOrder(struct node *root)
{
  if (root != NULL)
  {
    inOrder(root->left);
    printf("%d ", root->data);
    inOrder(root->right);
  }
}

int findHeight(struct node *root)
{
  if (root == NULL)
  {
    return -1;
  }
  else
  {
    int leftHeight = findHeight(root->left);
    int rightHeight = findHeight(root->right);

    // Return the height of the taller subtree, plus 1 for the current level
    return (leftHeight > rightHeight) ? (leftHeight + 1) : (rightHeight + 1);
  }
}

int main()
{
  /*
  1)
            7
          /  \
         2    3
        /      \
       1        4
       -> pre-order  : 7 2 1 3 4
       -> post-order : 1 2 4 3 7
       -> in-order   : 1 2 7 3 4

  2)
            4
          /  \
         1    6
        / \
       5   2
       -> pre-order  : 4 1 5 2 6 
       -> post-order : 5 2 1 6 4
       -> in-order   : 5 1 2 4 6
  */

  struct node *root;

  int choice;
  int height;

  while (1)
  {
    printf("\n========================================================================");
    printf("\n              Binary Tree Linked Representation Menu Driven");
    printf("\n========================================================================");
    printf("\n1. Create node");
    printf("\n2. Pre-Order Traversal");
    printf("\n3. Post-Order Traversal");
    printf("\n4. In-Order Traversal");
    printf("\n5. Find Height of the Binary Tree");
    printf("\n6. Exit");
    printf("\n========================================================================");

    printf("\nEnter your choice : ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
      // 1)
      // root = createNode(7);
      // root->left = createNode(2);
      // root->right = createNode(3);
      // root->left->left = createNode(1);
      // root->right->right = createNode(4);

      // 2)
      root = createNode(4);
      root->left = createNode(1);
      root->right = createNode(6);
      root->left->left = createNode(5);
      root->left->right = createNode(2);      
      break;

    case 2:
      preOrder(root);
      printf("\n");
      break;

    case 3:
      postOrder(root);
      printf("\n");
      break;

    case 4:
      inOrder(root);
      printf("\n");
      break;

    case 5:
      height = findHeight(root);
      printf("Height of the binary tree: %d\n", height);
      break;

    case 6:
      exit(0);
    }
  }

  return 0;
}