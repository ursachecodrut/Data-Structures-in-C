#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
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
}

void append(Node **head_ref, int new_data)
{
    Node *new_node = (Node *)malloc(sizeof(Node));

    Node *last = *head_ref;

    new_node->data = new_data;

    new_node->next = NULL;

    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }

    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

void deleteNode(Node **head_ref, int key)
{
    struct Node *temp = *head_ref, *prev;
    if (temp != NULL && temp->data == key)
    {
        *head_ref = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
        return;

    prev->next = temp->next;

    free(temp);
}

int isEmpty(Node *head)
{
    return (head == NULL);
}

void printList(Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
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
    deleteNode(&head, 1);
    push(&head, 100);
    append(&head, 6);
    append(&head, 4);
    insertAfter(head->next, 8);

    printf("Created Linked list is: \n");
    printList(head);
    printf("\nis empty: %d\n", isEmpty(head));
    freeList(&head);
    return 0;
}