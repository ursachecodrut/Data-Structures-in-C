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

void insert(Node **head, int x)
{
    Node *start;
    Node *end;
    Node *new;
    new = (Node *)malloc(sizeof(Node));
    new->data = x;
    if (*head == NULL || x < (*head)->data)
    {
        new->next = *head;
        *head = new;
        return;
    }
    else
    {
        start = *head;
        end = *head;
        while (end != NULL && end->data < x)
        {
            start = end;
            end = end->next;
        }
        new->next = end;
        start->next = new;
    }
}

void deleteNode(Node **head, int x)
{
    Node *temp = *head;
    Node *del;
    //if x is on first node
    if (x == (*head)->data)
    {
        del = *head;
        *head = (*head)->next;
        free(del);
        return;
    }
    while (temp->next != NULL && temp->next->data < x)
    {
        temp = temp->next;
    }
    //x not found
    if (temp->next == NULL || x != temp->next->data)
    {
        return;
    }
    del = temp->next;
    temp->next = temp->next->next;
    free(del);
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
    insert(&head, 6);
    insert(&head, 7);
    insert(&head, 5);
    insert(&head, 10);
    deleteNode(&head, 2);

    printf("Created Linked list is: \n");
    printList(head);
    // printf("mama ce tare");
    freeList(&head);
    return 0;
}