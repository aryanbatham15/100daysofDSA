#include <stdio.h>

int check(int *a, int n, int m, int mid) {
    int students = 1, pages = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] > mid) return 0;
        if (pages + a[i] > mid) { students++; pages = 0; }
        pages += a[i];
    }
    return students <= m;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
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
        if (check(a, n, m, mid)) { ans = mid; high = mid - 1; }
        else low = mid + 1;
    }

    printf("%d\n", ans);
    return 0;
}