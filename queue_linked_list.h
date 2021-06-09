#ifndef QUEUE_LINKED_LIST_H
#define QUEUE_LINKED_LIST_H

typedef struct QueueNode
{
    int data;
    struct QueueNode *next;
} QueueNode;

typedef struct Queue
{
    struct QueueNode *front, *rear;
} Queue;

QueueNode *newQueueNode(int k);
Queue *initQueue();
int isEmptyQueue(Queue *q);
void enqueue(Queue *q, int k);
void dequeue(Queue *q);
int peekQueue(Queue *q);
void printQueue(Queue *q);
void freeQueue(Queue *q);

#endif /* QUEUE_LINKED_LIST_H */