#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX];
int indegree[MAX];
int queue[MAX];
int front = -1, rear = -1;

// Function to add element to queue
void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

// Function to remove element from queue
int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

int main() {
    int n, m, i, j, u, v;
    
    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter number of edges: ");
    scanf("%d", &m);

    // Initialize adjacency matrix and indegree
    for (i = 0; i < n; i++) {
        indegree[i] = 0;
        for (j = 0; j < n; j++) {
            adj[i][j] = 0;
        }
    }

    printf("Enter edges (u v) [0-based index]:\n");
    for (i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }

    // Calculate indegree
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            if (adj[j][i] == 1) {
                indegree[i]++;
            }
        }
    }

    // Enqueue vertices with indegree 0
    for (i = 0; i < n; i++) {
        if (indegree[i] == 0) {
            enqueue(i);
        }
    }

    printf("Topological Order: ");
    int count = 0;

    while (front != -1 && front <= rear) {
        int node = dequeue();
        printf("%d ", node);
        count++;

        // Reduce indegree of adjacent vertices
        for (i = 0; i < n; i++) {
            if (adj[node][i] == 1) {
                indegree[i]--;
                if (indegree[i] == 0) {
                    enqueue(i);
                }
            }
        }
    }

    // If count != n → cycle exists
    if (count != n) {
        printf("\nCycle detected! Topological sort not possible.\n");
    }

    return 0;
}