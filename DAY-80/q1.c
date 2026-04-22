#include <stdio.h>

#define MAX 100
#define INF 1e9

int main() {
    int n;
    scanf("%d", &n);

    double dist[MAX][MAX];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            scanf("%d", &val);
            if (val == -1 && i != j)
                dist[i][j] = INF;
            else
                dist[i][j] = val;
        }
    }

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] + dist[k][j] < dist[i][j])
                    dist[i][j] = dist[i][k] + dist[k][j];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j > 0) printf(" ");
            if (dist[i][j] >= INF)
                printf("-1");
            else
                printf("%d", (int)dist[i][j]);
        }
        printf("\n");
    }

    return 0;
} 