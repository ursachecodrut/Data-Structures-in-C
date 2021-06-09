#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#include "stack_array.h"
#include "queue_linked_list.h"

typedef struct AdjListNode
{
    int dest, weight;
    struct AdjListNode *next;
} AdjListNode;

typedef struct AdjList
{
    struct AdjListNode *head;
} AdjList;

typedef struct Graph
{
    int V;
    struct AdjList *array;
} Graph;

typedef struct edge
{
    int src, dest, weight;
} Edge;

typedef struct edgeList
{
    int size;
    Edge *edges;
} EdgeList;

AdjListNode *newAdjListNode(int dest)
{
    AdjListNode *newNode = (AdjListNode *)malloc(sizeof(AdjListNode));
    newNode->dest = dest;
    newNode->next = NULL;
    return newNode;
}

Graph *initGraph(int V)
{
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->V = V;

    graph->array = (AdjList *)malloc(V * sizeof(AdjList));

    int i;
    for (i = 0; i < V; ++i)
        graph->array[i].head = NULL;

    return graph;
}

int **listToMatrix(Graph *graph)
{
    int size = graph->V;
    int **matrix = (int **)malloc(size * sizeof(int *) + size * size * sizeof(int));
    int *ptr;

    ptr = (int *)(matrix + size);
    for (int i = 0; i < size; i++)
    {
        matrix[i] = (ptr + size * i);
        memset(matrix[i], 0, sizeof(matrix[i]));
    }

    for (int i = 0; i < size; i++)
    {

        for (; graph->array[i].head != NULL; graph->array[i].head = graph->array[i].head->next)
        {
            matrix[i][graph->array[i].head->dest] = graph->array[i].head->weight;
        }
    }

    return matrix;
}

void addEdge(Graph *graph, int src, int dest)
{
    AdjListNode *newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;

    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}

void DFS(Graph *graph, int startNode)
{
    AdjListNode *cursor;
    int cur;
    int *visited = (int *)calloc(graph->V, sizeof(int));

    Stack *s = createStack(graph->V);
    push(s, startNode);
    visited[startNode] = 1;

    while (!isEmptyStack(s))
    {
        cur = pop(s);
        printf("Visited %d   ", cur);

        cursor = graph->array[cur].head;
        while (cursor)
        {
            if (visited[cursor->dest] == 0)
            {
                push(s, cursor->dest);
                visited[cursor->dest] = 1;
            }
            cursor = cursor->next;
        }
    }
}

void BFS(Graph *graph, int startNode)
{
    AdjListNode *cursor;
    int cur;
    int *visited = (int *)calloc(graph->V, sizeof(int));

    Queue *q = initQueue();
    enqueue(q, startNode);
    visited[startNode] = 1;

    while (!isEmptyQueue(q))
    {
        cur = peekQueue(q);
        dequeue(q);
        printf("Visited %d   ", cur);

        cursor = graph->array[cur].head;
        while (cursor)
        {
            if (visited[cursor->dest] == 0)
            {
                enqueue(q, cursor->dest);
                visited[cursor->dest] = 1;
            }
            cursor = cursor->next;
        }
    }
}

int minDistance(int *distance, int *visited, int size)
{
    int index = -1, min = INT_MAX;
    for (int i = 0; i < size; i++)
    {
        if (visited[i] == 0 && distance[i] < min)
        {
            min = distance[i];
            index = i;
        }
    }

    return index;
}

void dijkstra(Graph *graph, int startNode)
{
    int **matrix = listToMatrix(graph);
    int *distance = (int *)malloc(graph->V * sizeof(int));
    int *visited = (int *)calloc(graph->V, sizeof(int));

    for (int i = 0; i < graph->V; i++)
        distance[i] = INT_MAX - 1;

    int curNode = startNode;
    distance[curNode] = 0;
    visited[curNode] = 1;

    for (int i = 0; i < graph->V; i++)
    {
        for (int j = 0; j < graph->V; j++)
        {
            if (matrix[curNode][j] != 0 && distance[curNode] + matrix[curNode][j] < distance[j])
                distance[j] = distance[curNode] + matrix[curNode][j];
        }

        curNode = minDistance(distance, visited, graph->V);
        visited[curNode] = 1;
    }

    int cost = 0;
    printf("Costuri: ");
    for (int i = 0; i < graph->V; i++)
    {
        cost += distance[i];
        printf("%d ", distance[i]);
    }

    printf("\nCost total: %d\n", cost);
}

int minKey(int *key, int *mstSet, int V)
{
    int min = INT_MAX;
    int minIndex;

    for (int i = 0; i < V; i++)
    {
        if (mstSet[i] == 0 && key[i] < min)
        {
            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void prim(Graph *graph)
{
    int *mstSet = (int *)calloc(graph->V, sizeof(int));
    int *key = (int *)malloc(graph->V * sizeof(int));
    for (int i = 0; i < graph->V; i++)
        key[i] = INT_MAX;
    int *parent = (int *)malloc(graph->V * sizeof(int));

    key[0] = 0;
    parent[0] = -1;

    for (int i = 0; i < graph->V - 1; i++)
    {
        int minV = minKey(key, mstSet, graph->V);

        mstSet[minV] = 1;

        while (graph->array[minV].head != NULL)
        {
            if (mstSet[graph->array[minV].head->dest] == 0 && graph->array[minV].head->weight < key[graph->array[minV].head->dest])
            {
                parent[graph->array[minV].head->dest] = minV;
                key[graph->array[minV].head->dest] = graph->array[minV].head->weight;
            }

            graph->array[minV].head = graph->array[minV].head->next;
        }
    }

    int totalCost = 0;
    for (int i = 1; i < graph->V; i++)
    {
        printf("(%d %d) -> cost %d\n", parent[i], i, key[i]);
        totalCost += key[i];
    }
    printf("Cost total: %d\n", totalCost);
}

void printGraph(Graph *graph)
{
    int v;
    for (v = 0; v < graph->V; ++v)
    {
        AdjListNode *pCrawl = graph->array[v].head;
        printf("\n Adjacency list of vertex %d\n head ", v);
        while (pCrawl)
        {
            printf("-> %d", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
}

int main()
{
    int V = 5;
    Graph *graph = initGraph(V);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    printGraph(graph);
    printf("\n");
    DFS(graph, 0);
    printf("\n");
    BFS(graph, 0);
    printf("\n");
    dijkstra(graph, 4);
    return 0;
}