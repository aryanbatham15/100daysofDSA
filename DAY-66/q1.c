#include <stdio.h>
#include <stdlib.h>

int dfs(int node, int** adj, int* adjSize, int* visited, int* recStack) {
    
    visited[node] = 1;
    recStack[node] = 1;

    for (int i = 0; i < adjSize[node]; i++) {
        int neighbor = adj[node][i];

        if (!visited[neighbor]) {
            if (dfs(neighbor, adj, adjSize, visited, recStack))
                return 1;
        }
        else if (recStack[neighbor]) {
            return 1; 
        }
    }

    recStack[node] = 0; 
    return 0;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    int** adj = (int**)malloc(n * sizeof(int*));
    int* adjSize = (int*)calloc(n, sizeof(int));

    for (int i = 0; i < n; i++) {
        adj[i] = (int*)malloc(n * sizeof(int));
    }
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][adjSize[u]++] = v; 
    }

    int* visited = (int*)calloc(n, sizeof(int));
    int* recStack = (int*)calloc(n, sizeof(int));
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (dfs(i, adj, adjSize, visited, recStack)) {
                printf("YES\n");
                return 0;
            }
        }
    }

    printf("NO\n");
    return 0;
}