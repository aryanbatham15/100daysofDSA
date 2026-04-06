#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int adj[MAX][MAX];
int visited[MAX];
int n;

int dfs(int node, int parent) {
    visited[node] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[node][i]) {
            if (!visited[i]) {
                if (dfs(i, node)) return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}

int has_cycle() {
    memset(visited, 0, sizeof(visited));
    for (int i = 0; i < n; i++)
        if (!visited[i])
            if (dfs(i, -1)) return 1;
    return 0;
}

int main() {
    int edges[][2] = {{0,1},{0,2},{1,3},{2,3}};
    int e = 4;
    n = 4;

    memset(adj, 0, sizeof(adj));
    for (int i = 0; i < e; i++) {
        int u = edges[i][0], v = edges[i][1];
        adj[u][v] = adj[v][u] = 1;
    }

    printf("%s\n", has_cycle() ? "YES" : "NO");
    return 0;
}