#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    int **adj = (int **)malloc((n + 1) * sizeof(int *));
    int *size = (int *)calloc(n + 1, sizeof(int));

    for (int i = 0; i <= n; i++)
        adj[i] = NULL;

    for (int i = 0; i < m; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        adj[u] = (int *)realloc(adj[u], (size[u] + 1) * sizeof(int));
        adj[u][size[u]++] = v;
        adj[v] = (int *)realloc(adj[v], (size[v] + 1) * sizeof(int));
        adj[v][size[v]++] = u;
    }
    for (int i = 1; i <= n; i++) {
        printf("%d: ", i);
        for (int j = 0; j < size[i]; j++) {
            printf("%d", adj[i][j]);
            if (j + 1 < size[i]) printf(" -> ");
        }
        printf("\n");
    }
    for (int i = 0; i <= n; i++)
        free(adj[i]);
    free(adj);
    free(size);

    return 0;
}