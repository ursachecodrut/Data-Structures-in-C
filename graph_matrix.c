#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

typedef struct Graph
{
    int n, m;
    int **a;
} Graph;

void initGraph(Graph *graph, int n)
{
    int i;
    graph->n = n;
    graph->m = 0;
    graph->a = (int **)malloc((n + 1) * sizeof(int *));
    for (i = 1; i <= n; i++)
    {
        graph->a[i] = (int *)calloc(n + 1, sizeof(int));
    }
}

void addArc(Graph *graph, int x, int y)
{
    graph->a[x][y] = 1;
    graph->m++;
}

int arc(Graph graph, int x, int y)
{
    return graph.a[x][y];
}

void deleteArc(Graph *graph, int x, int y)
{
    graph->a[x][y] = 0;
    (graph->m)--;
}

void deleteNode(Graph *graph, int x)
{
    int i;
    for (i = 1; i <= graph->n; i++)
    {
        deleteArc(graph, x, i);
        deleteArc(graph, i, x);
    }
}

void printAdjMatrix(Graph graph)
{
    int i, j;
    for (i = 1; i <= graph.n; i++)
    {
        for (j = 1; j <= graph.n; j++)
        {
            printf("%d ", graph.a[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    Graph g;
    initGraph(&g, 4);
    addArc(&g, 1, 2);
    addArc(&g, 1, 3);
    addArc(&g, 1, 4);
    addArc(&g, 2, 1);
    addArc(&g, 2, 3);
    addArc(&g, 3, 1);
    addArc(&g, 3, 2);
    addArc(&g, 4, 1);

    printAdjMatrix(g);

    deleteNode(&g, 4);
    printf("\n");
    printAdjMatrix(g);
    return 0;
}