#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
    struct Node *prev;
} Node;

void initList(Node **head)
{
    *head = NULL;
}

void push(Node **head_ref, int new_data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->data = new_data;

    new_node->next = (*head_ref);
    new_node->prev = NULL;

    if ((*head_ref) != NULL)
    {
        (*head_ref)->prev = new_node;
    }

    (*head_ref) = new_node;
}

void insertAfter(Node *prev_node, int new_data)
{
    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    Node *new_node = (Node *)malloc(sizeof(Node));

    new_node->data = new_data;

    new_node->next = prev_node->next;

    prev_node->next = new_node;

    new_node->prev = prev_node;

    if (new_node->next != NULL)
        new_node->next->prev = new_node;
}

void append(Node **head_ref, int new_data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    struct Node *last = *head_ref;

    new_node->data = new_data;

    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;

    new_node->prev = last;

    return;
}

void deleteNode(struct Node **head_ref, struct Node *del)
{
    if (*head_ref == NULL || del == NULL)
        return;

    if (*head_ref == del)
        *head_ref = del->next;

    if (del->next != NULL)
        del->next->prev = del->prev;

    if (del->prev != NULL)
        del->prev->next = del->next;

    free(del);
    return;
}

int isEmpty(Node *head)
{
    return (head == NULL);
}

void printList(Node *node)
{
    struct Node *last;
    printf("\nTraversal in forward direction \n");
    while (node != NULL)
    {
        printf(" %d ", node->data);
        last = node;
        node = node->next;
    }

    printf("\nTraversal in reverse direction \n");
    while (last != NULL)
    {
        printf(" %d ", last->data);
        last = last->prev;
    }
}

void freeList(Node **head)
{
    Node *tmp;
    while (*head != NULL)
    {
        tmp = *head;
        *head = (*head)->next;
        free(tmp);
    }
}

int main()
{

    Node *head;
    initList(&head);
    push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 10);
    push(&head, 100);
    append(&head, 6);
    append(&head, 4);
    insertAfter(head->next, 8);

    printf("Created Linked list is: \n");
    printList(head);
    freeList(&head);
    return 0;
}