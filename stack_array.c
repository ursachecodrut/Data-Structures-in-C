#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "stack_array.h"

// typedef struct stack
// {
//     int top;
//     int capacity;
//     int *array;
// } Stack;

void showStack(Stack *stk)
{
    for (int i = 0; i <= stk->top; i++)
        printf("%d ", stk->array[i]);
}

Stack *createStack(int capacity)
{
    Stack *stk = (Stack *)malloc(sizeof(Stack));
    stk->top = -1;
    stk->capacity = capacity;
    stk->array = (int *)malloc(capacity * sizeof(int));
    return stk;
}

int isFullStack(Stack *stk) // No pun intended
{
    return stk->top == stk->capacity - 1;
}

int isEmptyStack(Stack *stk)
{
    return stk->top == -1;
}

void push(Stack *stk, int value)
{
    if (isFullStack(stk))
        return;

    stk->array[++(stk->top)] = value;
}

int pop(Stack *stk)
{
    if (isEmptyStack(stk))
        return INT_MIN;

    return stk->array[(stk->top)--];
}

int peekStack(Stack *stk)
{
    if (isEmptyStack(stk))
        return INT_MIN;

    return stk->array[(stk->top)];
}

void freeStack(Stack *stk)
{
    free(stk->array);
    free(stk);
}

// int main()
// {
//     Stack *stack = createStack(10);
//     push(stack, 1);
//     push(stack, 2);
//     push(stack, 3);
//     push(stack, 4);
//     showStack(stack);
//     pop(stack);
//     printf("\n");
//     showStack(stack);
//     printf("\npeek: %d\n", peekStack(stack));
//     printf("\nis full: %d\n", isFullStack(stack));
//     printf("\nis Empty %d\n", isEmptyStack(stack));
//     freeStack(stack);

//     return 0;
// }