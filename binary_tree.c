#include <stdio.h>
#include <stdlib.h>
#include "binary_tree.h"
#include "stack_linked_list.h"
#include "queue_linked_list.h"

// typedef struct TreeNode
// {
//     int data;
//     struct TreeNode *left, *right;
// } TreeNode;

void initTree(TreeNode **root, int data)
{
    *root = (TreeNode *)malloc(sizeof(TreeNode));
    (*root)->left = (*root)->right = NULL;
    (*root)->data = data;
}

TreeNode *newTreeNode(int data)
{
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));

    node->data = data;

    node->left = NULL;
    node->right = NULL;
    return node;
}

int isTreeEmpty(TreeNode *root)
{
    return (root == NULL);
}

int isInterior(TreeNode *node)
{
    if (node->left != NULL || node->right != NULL)
        return 1;
    else
        return 0;
}

int isLeaf(TreeNode *node)
{
    if (node->left == NULL && node->right == NULL)
        return 1;
    else
        return 0;
}

void preorder(TreeNode *root)
{
    if (root != NULL)
    {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(TreeNode *root)
{
    if (root)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void postorder(TreeNode *root)
{
    if (root)
    {
        inorder(root->left);
        inorder(root->right);
        printf("%d ", root->data);
    }
}

int height(TreeNode *root)
{
    int hs, hd;
    if (root == NULL)
        return 0;
    hs = height(root->left);
    hd = height(root->right);
    return 1 + ((hs > hd) ? hs : hd);
}

void printLevel(TreeNode *root, int level)
{
    if (root == NULL)
        return;
    if (level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printLevel(root->left, level - 1);
        printLevel(root->right, level - 1);
    }
}
//TODO

// void preorderIterative(TreeNode *root)
// {
//     StackNode *stack = NULL;
//     while (1)
//     {
//         printf("%d ", root->data);
//         push(&stack, root->data);
//         root = root->left;
//         if (isStackEmpty(stack))
//         {
//             break;
//         }
//         root->data = pop(&stack);
//         root = root->right;
//     }
//     freeStack(&stack);
// }

//TODO

// void deleteNode(TreeNode **root, int key)
// {
//     Queue *Q = initQueue();
//     enQueue(Q, *root);
//     TreeNode *temp, *key_node = NULL;
//     while (!isEmptyQueue(Q))
//     {
//         temp = dequeue(Q);
//         if (temp->data == key)
//             key_node = temp;
//         if (temp->left != NULL)
//             enQueue(Q, temp->left); /*sitot avansez*/
//         if (temp->right != NULL)
//             enQueue(Q, temp->right);
//     } /* la final –in temp o saam ceamaidin dreaptafrunza*/
//     if ((*root)->data == key && (*root)->left == NULL && (*root)->right == NULL)
//     {
//         free(*root);
//         *root = NULL; /*dacaam doarun nod in arbore -siel trebuiesters*/
//     }
//     else
//     {
//         int aux = temp->data;
//         deleteDeepest(*root, temp);
//         key_node->data = aux;
//     }
// }

TreeNode *createTree()
{
    int data;
    char decision;
    TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
    printf("Enter the data for node: \n");
    scanf("%d", &data);
    root->data = data;

    printf("Does the added node have left child?\n");
    scanf("%s", &decision);
    if (decision == 'd')
        root->left = createTree();
    else
        root->left = NULL;

    printf("Does the added node have right child?\n");
    scanf("%s", &decision);
    if (decision == 'd')
        root->right = createTree();
    else
        root->right = NULL;

    return root;
}

void freeTree(TreeNode **root)
{
    if (*root)
    {
        freeTree(&(*root)->right);
        freeTree(&(*root)->left);
        free(*root);
    }
}

// int main()
// {
//     TreeNode *root = createTree();

//     preorder(root);

//     freeTree(&root);
//     return 0;
// }