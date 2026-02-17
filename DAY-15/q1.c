#include <stdio.h>

int main() {
    int m, n, i, j;
    int sum = 0;

    scanf("%d %d", &m, &n);

    int matrix[m][n];

    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);

            if (i == j) {
                sum += matrix[i][j];
            }
        }
    }

    printf("%d", sum);

    return 0;
}
