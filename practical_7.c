#include <stdio.h>
#define MAX 10

int adj[MAX][MAX];
int visited[MAX];
int queue[MAX];
int n;

void BFS(int start) {
    int front = -1, rear = -1;
    int i;

    printf("\nBFS Traversal starting from vertex %d:\n", start);

    for (i = 1; i <= n; i++)
        visited[i] = 0;

    queue[++rear] = start;
    visited[start] = 1;

    while (front != rear) {
        int v = queue[++front];
        printf("%d ", v);

        for (i = 1; i <= n; i++) {
            if (adj[v][i] == 1 && visited[i] == 0) {
                queue[++rear] = i;
                visited[i] = 1;
            }
        }
    }
}

void DFS(int v) {
    int i;
    visited[v] = 1;
    printf("%d ", v);

    for (i = 1; i <= n; i++) {
        if (adj[v][i] == 1 && visited[i] == 0) {
            DFS(i);
        }
    }
}
int main() {
    int i, j, s, d, e, start;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    // Initialize adj matrix
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            adj[i][j] = 0;

    printf("Enter number of edges: ");
    scanf("%d", &e);

    printf("Enter edges (source destination):\n");
    for (i = 1; i <= e; i++) {
        scanf("%d %d", &s, &d);
        adj[s][d] = 1;   
        adj[d][s] = 1;   // remove this if undirected
    }

    printf("Enter starting vertex: ");
    scanf("%d", &start);

    BFS(start);

    for (i = 1; i <= n; i++)
        visited[i] = 0;

    printf("\nDFS Traversal starting from vertex %d:\n", start);
    DFS(start);

    return 0;
}
