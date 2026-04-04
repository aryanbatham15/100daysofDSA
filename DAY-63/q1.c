#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAXN 1000          // <-- this line was missing

typedef struct Node {
    int val;
    struct Node* next;
} Node;

Node* adj[MAXN];
bool visited[MAXN];

void addEdge(int u, int v) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = v;
    newNode->next = adj[u];
    adj[u] = newNode;
}

void dfs(int u) {
    visited[u] = true;
    printf("%d ", u);

    Node* curr = adj[u];
    while (curr != NULL) {
        if (!visited[curr->val])
            dfs(curr->val);
        curr = curr->next;
    }
}

int main() {
    int n, e, s;

    printf("Enter number of vertices and edges: ");
    scanf("%d %d", &n, &e);

    for (int i = 0; i < n; i++)
        adj[i] = NULL;

    printf("Enter edges (u v):\n");
    for (int i = 0; i < e; i++) {
        int u, v;
        scanf("%d %d", &u, &v);
        addEdge(u, v);
        addEdge(v, u);
    }

    printf("Enter starting vertex: ");
    scanf("%d", &s);

    for (int i = 0; i < n; i++)
        visited[i] = false;

    printf("DFS Traversal: ");
    dfs(s);
    printf("\n");

    return 0;   // <-- make sure this closing brace for main() is present
}