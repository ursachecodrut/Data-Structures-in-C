#ifndef STACK_ARRAY_H
#define STACK_ARRAY_H

typedef struct Stack
{
    int top;
    int capacity;
    int *array;
} Stack;

void showStack(Stack *stk);

Stack *createStack(int capacity);

int isFullStack(Stack *stk);

int isEmptyStack(Stack *stk);

void push(Stack *stk, int value);

int pop(Stack *stk);

int peekStack(Stack *stk);

void freeStack(Stack *stk);

#endif /* STACK_ARRAY_H */