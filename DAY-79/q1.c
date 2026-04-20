#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAXN 100005

typedef struct { int v, w; } Edge;
typedef struct { Edge *data; int size, cap; } AdjList;
typedef struct { int dist, v; } HeapNode;

AdjList graph[MAXN];
int dist[MAXN], visited[MAXN];
HeapNode heap[MAXN * 10];
int heapSize = 0;

void addEdge(int u, int v, int w) {
    if (graph[u].size == graph[u].cap) {
        graph[u].cap = graph[u].cap ? graph[u].cap * 2 : 4;
        graph[u].data = realloc(graph[u].data, graph[u].cap * sizeof(Edge));
    }
    graph[u].data[graph[u].size++] = (Edge){v, w};
}

void push(int d, int v) {
    heap[++heapSize] = (HeapNode){d, v};
    int i = heapSize;
    while (i > 1 && heap[i].dist < heap[i/2].dist) {
        HeapNode tmp = heap[i]; heap[i] = heap[i/2]; heap[i/2] = tmp;
        i /= 2;
    }
}

HeapNode pop() {
    HeapNode top = heap[1];
    heap[1] = heap[heapSize--];
    int i = 1;
    while (1) {
        int smallest = i, l = 2*i, r = 2*i+1;
        if (l <= heapSize && heap[l].dist < heap[smallest].dist) smallest = l;
        if (r <= heapSize && heap[r].dist < heap[smallest].dist) smallest = r;
        if (smallest == i) break;
        HeapNode tmp = heap[i]; heap[i] = heap[smallest]; heap[smallest] = tmp;
        i = smallest;
    }
    return top;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    int src;
    scanf("%d", &src);
    for (int i = 1; i <= n; i++) dist[i] = INT_MAX;
    dist[src] = 0;
    push(0, src);
    while (heapSize > 0) {
        HeapNode cur = pop();
        if (visited[cur.v]) continue;
        visited[cur.v] = 1;
        for (int i = 0; i < graph[cur.v].size; i++) {
            Edge e = graph[cur.v].data[i];
            if (dist[cur.v] + e.w < dist[e.v]) {
                dist[e.v] = dist[cur.v] + e.w;
                push(dist[e.v], e.v);
            }
        }
    }
    for (int i = 1; i <= n; i++) printf("%d%c", dist[i], i == n ? '\n' : ' ');
    return 0;
}