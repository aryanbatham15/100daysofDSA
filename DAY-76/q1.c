#include <stdio.h>

int parent[100005];

int find(int x) {
    if (parent[x] != x)
        parent[x] = find(parent[x]);
    return parent[x];
}

void unite(int a, int b) {
    parent[find(a)] = find(b);
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        unite(a, b);
    }
    
    int count = 0;
    for (int i = 1; i <= n; i++)
        if (find(i) == i)
            count++;
    
    printf("%d\n", count);
    return 0;
}