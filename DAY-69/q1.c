#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_VERTICES 100

typedef struct {
    int vertex, weight;
} Edge;

typedef struct {
    int vertex, dist;
} HeapNode;

typedef struct {
    HeapNode data[MAX_VERTICES * MAX_VERTICES];
    int size;
} MinHeap;

int adj_vertex[MAX_VERTICES][MAX_VERTICES];
int adj_weight[MAX_VERTICES][MAX_VERTICES];
int adj_count[MAX_VERTICES];
int dist[MAX_VERTICES];
int visited[MAX_VERTICES];

void swap(HeapNode *a, HeapNode *b) {
    HeapNode t = *a; *a = *b; *b = t;
}

void push(MinHeap *h, int v, int d) {
    int i = h->size++;
    h->data[i] = (HeapNode){v, d};
    while (i > 0) {
        int p = (i - 1) / 2;
        if (h->data[p].dist <= h->data[i].dist) break;
        swap(&h->data[p], &h->data[i]);
        i = p;
    }
}

HeapNode pop(MinHeap *h) {
    HeapNode top = h->data[0];
    h->data[0] = h->data[--h->size];
    int i = 0;
    while (1) {
        int l = 2*i+1, r = 2*i+2, smallest = i;
        if (l < h->size && h->data[l].dist < h->data[smallest].dist) smallest = l;
        if (r < h->size && h->data[r].dist < h->data[smallest].dist) smallest = r;
        if (smallest == i) break;
        swap(&h->data[i], &h->data[smallest]);
        i = smallest;
    }
    return top;
}

void dijkstra(int src, int n) {
    MinHeap h = {.size = 0};
    for (int i = 0; i < n; i++) { dist[i] = INT_MAX; visited[i] = 0; }
    dist[src] = 0;
    push(&h, src, 0);
    while (h.size > 0) {
        HeapNode cur = pop(&h);
        int u = cur.vertex;
        if (visited[u]) continue;
        visited[u] = 1;
        for (int i = 0; i < adj_count[u]; i++) {
            int v = adj_vertex[u][i];
            int w = adj_weight[u][i];
            if (!visited[v] && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                push(&h, v, dist[v]);
            }
        }
    }
}

void add_edge(int u, int v, int w) {
    adj_vertex[u][adj_count[u]] = v;
    adj_weight[u][adj_count[u]] = w;
    adj_count[u]++;
    adj_vertex[v][adj_count[v]] = u;
    adj_weight[v][adj_count[v]] = w;
    adj_count[v]++;
}

int main() {
    int n = 5;
    for (int i = 0; i < n; i++) adj_count[i] = 0;

    add_edge(0, 1, 4);
    add_edge(0, 2, 1);
    add_edge(2, 1, 2);
    add_edge(1, 3, 1);
    add_edge(2, 3, 5);
    add_edge(3, 4, 3);

    dijkstra(0, n);

    for (int i = 0; i < n; i++) {
        printf("0 -> %d : %d\n", i, dist[i]);
    }
    return 0;
}