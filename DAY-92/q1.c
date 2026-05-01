#include <stdio.h>

int partition(int *a, int low, int high) {
    int pivot = a[high], i = low - 1;
    for (int j = low; j < high; j++) {
        if (a[j] <= pivot) {
            i++;
            int t = a[i]; a[i] = a[j]; a[j] = t;
        }
    }
    int t = a[i+1]; a[i+1] = a[high]; a[high] = t;
    return i + 1;
}

void quickSort(int *a, int low, int high) {
    if (low >= high) return;
    int pi = partition(a, low, high);
    quickSort(a, low, pi - 1);
    quickSort(a, pi + 1, high);
}

int main() {
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    quickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) printf("%d%c", a[i], i == n-1 ? '\n' : ' ');
    return 0;
}