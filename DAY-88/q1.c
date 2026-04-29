#include <stdio.h>

int check(int *a, int n, int k, int mid) {
    int count = 1, last = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] - last >= mid) {
            count++;
            last = a[i];
            if (count == k) return 1;
        }
    }
    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);

    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - i - 1; j++)
            if (a[j] > a[j + 1]) {
                int t = a[j]; a[j] = a[j + 1]; a[j + 1] = t;
            }

    int low = 1, high = a[n - 1] - a[0], ans = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(a, n, k, mid)) { ans = mid; low = mid + 1; }
        else high = mid - 1;
    }

    printf("%d\n", ans);
    return 0;
}