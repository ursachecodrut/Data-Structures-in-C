#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

void initL(Node **head)
{
    *head = (Node *)malloc(sizeof(Node));
    //head is pointing to itself
    (*head)->next = *head;
}

void addL(Node **head, int x)
{
    Node *temp = *head;
    Node *new = (Node *)malloc(sizeof(Node));
    new->data = x;
    new->next = *head;
    while (temp->next != *head)
    {
        //searching for the address of the first element
        temp = temp->next;
    }
    temp->next = new;
}

void printList(Node *head)
{
    Node *temp = head->next;
    while (temp != head)
    {
        //repeat until we find sentinel
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{
    Node *head;

    initL(&head);
    addL(&head, 1);
    addL(&head, 2);
    addL(&head, 3);
    addL(&head, 4);

    printf("Contents of Circular Linked List\n ");
    printList(head);

    return 0;
}