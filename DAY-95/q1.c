#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b) {
    float fa = *(float *)a;
    float fb = *(float *)b;
    return (fa > fb) - (fa < fb);
}

void bucketSort(float arr[], int n) {
    int k = n; 
    float **buckets = (float **)malloc(k * sizeof(float *));
    int *bucketSize = (int *)calloc(k, sizeof(int));
    int *bucketCap  = (int *)malloc(k * sizeof(int));

    for (int i = 0; i < k; i++) {
        bucketCap[i]  = 4;
        buckets[i]    = (float *)malloc(bucketCap[i] * sizeof(float));
    }
    for (int i = 0; i < n; i++) {
        int idx = (int)(arr[i] * k);
        if (idx >= k) idx = k - 1; 
        if (bucketSize[idx] == bucketCap[idx]) {
            bucketCap[idx] *= 2;
            buckets[idx] = (float *)realloc(buckets[idx], bucketCap[idx] * sizeof(float));
        }
        buckets[idx][bucketSize[idx]++] = arr[i];
    }
    int pos = 0;
    for (int i = 0; i < k; i++) {
        qsort(buckets[i], bucketSize[i], sizeof(float), compare);
        for (int j = 0; j < bucketSize[i]; j++)
            arr[pos++] = buckets[i][j];
    }
    for (int i = 0; i < k; i++) free(buckets[i]);
    free(buckets);
    free(bucketSize);
    free(bucketCap);
}

int main() {
    float arr[] = {0.78, 0.17, 0.39, 0.26, 0.72, 0.94, 0.21, 0.12, 0.55, 0.63};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Before: ");
    for (int i = 0; i < n; i++) printf("%.2f ", arr[i]);

    bucketSort(arr, n);

    printf("\nAfter:  ");
    for (int i = 0; i < n; i++) printf("%.2f ", arr[i]);
    printf("\n");

    return 0;
}