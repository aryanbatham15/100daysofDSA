#include <stdio.h>

int check(int *a, int n, int k, int mid) {
    int painters = 1, time = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > mid) return 0;
        if (time + a[i] > mid) { painters++; time = 0; }
        time += a[i];
    }
    return painters <= k;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int a[n];
    int sum = 0, mx = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        if (a[i] > mx) mx = a[i];
    }

    int low = mx, high = sum, ans = sum;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (check(a, n, k, mid)) { ans = mid; high = mid - 1; }
        else low = mid + 1;
    }

    printf("%d\n", ans);
    return 0;
}