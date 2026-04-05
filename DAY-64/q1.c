#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = 0, rear = 0;
int visited[MAX] = {0};

void enqueue(int val) { queue[rear++] = val; }
int dequeue()        { return queue[front++]; }
int isEmpty()        { return front == rear; }

void bfs(int adj[][MAX], int n, int s) {
    enqueue(s);
    visited[s] = 1;

    while (!isEmpty()) {
        int node = dequeue();
        printf("%d ", node);

        for (int i = 0; i < n; i++) {
            if (adj[node][i] && !visited[i]) {
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int n, e;
    printf("Vertices: "); scanf("%d", &n);
    printf("Edges:    "); scanf("%d", &e);

    int adj[MAX][MAX] = {0};
    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;  
    }

    int s;
    printf("Source: "); scanf("%d", &s);

    printf("BFS: ");
    bfs(adj, n, s);
    printf("\n");
    return 0;
}