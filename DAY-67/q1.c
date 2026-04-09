#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Adjacency list node
struct Node {
    int dest;
    struct Node* next;
};

// Graph structure
struct Graph {
    int vertices;
    struct Node* adjList[MAX];
};

// Stack structure
int stack[MAX];
int top = -1;

void push(int val) { stack[++top] = val; }
int pop()          { return stack[top--]; }

// Create a new adjacency list node
struct Node* newNode(int dest) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->dest = dest;
    node->next = NULL;
    return node;
}

// Add directed edge u -> v
void addEdge(struct Graph* graph, int u, int v) {
    struct Node* node = newNode(v);
    node->next = graph->adjList[u];
    graph->adjList[u] = node;
}

// DFS + push to stack after visiting all neighbors
void dfs(struct Graph* graph, int v, int visited[]) {
    visited[v] = 1;

    struct Node* temp = graph->adjList[v];
    while (temp) {
        if (!visited[temp->dest])
            dfs(graph, temp->dest, visited);
        temp = temp->next;
    }

    push(v); // Push vertex AFTER all descendants are processed
}

// Topological Sort
void topologicalSort(struct Graph* graph) {
    int visited[MAX] = {0};

    // Run DFS from every unvisited vertex
    for (int i = 0; i < graph->vertices; i++)
        if (!visited[i])
            dfs(graph, i, visited);

    // Pop from stack = topological order
    printf("Topological Order: ");
    while (top != -1)
        printf("%d ", pop());
    printf("\n");
}

// Initialize graph
struct Graph* createGraph(int vertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->vertices = vertices;
    for (int i = 0; i < vertices; i++)
        graph->adjList[i] = NULL;
    return graph;
}

// ── Driver ──────────────────────────────────────────────
int main() {
    /*
     * Example DAG (6 nodes):
     *
     *   5 → 2 → 3
     *   5 → 0
     *   4 → 0
     *   4 → 1
     *   2 → 3
     *   3 → 1
     *
     * Expected order (one valid): 5 4 2 3 1 0
     */
    struct Graph* graph = createGraph(6);
    addEdge(graph, 5, 2);
    addEdge(graph, 5, 0);
    addEdge(graph, 4, 0);
    addEdge(graph, 4, 1);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 1);

    topologicalSort(graph);
    return 0;
}