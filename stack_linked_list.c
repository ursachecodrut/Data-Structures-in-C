#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack_linked_list.h"

// typedef struct StackNode
// {
//     int data;
//     struct StackNode *next;
// } StackNode;

void initStack(StackNode **root)
{
    *root = NULL;
}

StackNode *newStackNode(int data)
{
    StackNode *stackNode = (StackNode *)malloc(sizeof(StackNode));
    stackNode->data = data;
    stackNode->next = NULL;
    return stackNode;
}

int isStackEmpty(StackNode *root)
{
    return !root;
}

void push(StackNode **root, int data)
{
    StackNode *stackNode = newStackNode(data);
    stackNode->next = *root;
    *root = stackNode;
    printf("%d pushed to stack\n", data);
}

int pop(StackNode **root)
{
    if (isStackEmpty(*root))
        return INT_MIN;
    StackNode *temp = *root;
    *root = (*root)->next;
    int popped = temp->data;
    free(temp);

    return popped;
}

int peek(StackNode *root)
{
    if (isStackEmpty(root))
        return INT_MIN;
    return root->data;
}

void printStack(StackNode *root)
{
    while (root != NULL)
    {
        printf("%d ", root->data);
        root = root->next;
    }
}

void freeStack(StackNode **root)
{
    StackNode *tmp;
    while (*root != NULL)
    {
        tmp = *root;
        *root = (*root)->next;
        free(tmp);
    }
}

// int main()
// {
//     StackNode *root;
//     initStack(&root);

//     // push(&root, 10);
//     // push(&root, 20);
//     // push(&root, 30);

//     // printf("%d popped from stack\n", pop(&root));

//     printf("Top element is %d\n", peek(root));

//     printf("is Empty %d\n", isEmpty(root));

//     printStack(root);
//     freeStack(&root);

//     return 0;
// }