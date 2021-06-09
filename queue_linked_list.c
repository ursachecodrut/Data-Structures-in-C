#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "queue_linked_list.h"

// typedef struct QueueNode
// {
//     int data;
//     struct QueueNode *next;
// } QueueNode;

// typedef struct Queue
// {
//     struct QueueNode *front, *rear;
// } Queue;

QueueNode *newQueueNode(int k)
{
    QueueNode *temp = (QueueNode *)malloc(sizeof(QueueNode));
    temp->data = k;
    temp->next = NULL;
    return temp;
}

Queue *initQueue()
{
    Queue *q = (Queue *)malloc(sizeof(Queue));
    q->front = q->rear = NULL;
    return q;
}

int isEmptyQueue(Queue *q)
{
    return q->front == NULL;
}

void enqueue(Queue *q, int k)
{
    QueueNode *temp = newQueueNode(k);

    if (q->rear == NULL)
    {
        q->front = q->rear = temp;
        return;
    }

    q->rear->next = temp;
    q->rear = temp;
}

void dequeue(Queue *q)
{
    if (q->front == NULL)
        return;

    QueueNode *temp = q->front;

    q->front = q->front->next;

    if (q->front == NULL)
        q->rear = NULL;

    free(temp);
}

int peekQueue(Queue *q)
{
    if (isEmptyQueue(q))
        return INT_MIN;

    return q->front->data;
}

void printQueue(Queue *q)
{
    QueueNode *temp = q->front;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

void freeQueue(Queue *q)
{
    QueueNode *temp = q->front;
    QueueNode *del;
    while (temp != NULL)
    {
        del = temp;
        temp = temp->next;
        free(del);
    }
    free(q);
}

// int main()
// {
//     Queue *q = initQueue();
//     enqueue(q, 10);
//     enqueue(q, 20);
//     dequeue(q);
//     dequeue(q);
//     enqueue(q, 30);
//     enqueue(q, 40);
//     enqueue(q, 50);
//     dequeue(q);
//     printf("Queue Front : %d \n", q->front->data);
//     printf("Queue Rear : %d\n", q->rear->data);
//     printf("is Empty %d\n", isEmptyQueue(q));
//     printf("peak: %d\n", peekQueue(q));
//     printf("\n");
//     printQueue(q);
//     freeQueue(q);
//     return 0;
// }