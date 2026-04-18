#include <stdio.h>
#include <string.h>

int adj[101][101], visited[101], n, m;

void dfs(int v) {
    visited[v] = 1;
    for (int i = 1; i <= n; i++)
        if (adj[v][i] && !visited[i])
            dfs(i);
}

int main() {
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u][v] = adj[v][u] = 1;
    }
    dfs(1);
    for (int i = 1; i <= n; i++)
        if (!visited[i]) { printf("NOT CONNECTED"); return 0; }
    printf("CONNECTED");
}