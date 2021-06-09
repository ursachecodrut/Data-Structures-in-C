#ifndef STACK_LINKED_LIST_H
#define STACK_LINKED_LIST_H

typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode;

void initStack(StackNode **root);
StackNode *newStackNode(int data);
int isStackEmpty(StackNode *root);
void push(StackNode **root, int data);
int pop(StackNode **root);
int peek(StackNode *root);
void printStack(StackNode *root);
void freeStack(StackNode **root);

#endif /* STACK_LINKED_LIST_H */