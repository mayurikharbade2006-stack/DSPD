#include <stdio.h>
#include <stdlib.h>

int adj[20][20];  
int visited[20];

void BFS(int start, int N) {
    int queue[20], front = 0, rear = 0;
    for (int i = 1; i <= N; i++)
        visited[i] = 0;

    printf("BFS Order: ");
    visited[start] = 1;
    queue[rear++] = start;

    while (front < rear) {
        int node = queue[front++];
        printf("%d ", node);

        for (int i = 1; i <= N; i++) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = 1;
                queue[rear++] = i;
            }
        }
    }
    printf("\n");
}
void DFS(int start, int N) {
    int stack[20], top = -1;
    for (int i = 1; i <= N; i++)
        visited[i] = 0;

    printf("DFS Order: ");
    stack[++top] = start;

    while (top != -1) {
        int node = stack[top--];
        if (!visited[node]) {
            visited[node] = 1;
            printf("%d ", node);

            for (int i = N; i >= 1; i--) {
                if (adj[node][i] && !visited[i]) {
                    stack[++top] = i;
                }
            }
        }
    }
    printf("\n");
}
int main() {
    int n;
    printf("Enter grid size (n): ");
    scanf("%d", &n);

    int total = n * n;
    for (int i = 1; i <= total; i++) {
        
        if (i % n != 0)
            adj[i][i + 1] = adj[i + 1][i] = 1;
       
        if (i + n <= total)
            adj[i][i + n] = adj[i + n][i] = 1;
    }

    printf("\nFor %dx%d grid (Total nodes = %d):\n", n, n, total);
    BFS(1, total);
    DFS(1, total);

    return 0;
}
