#include <stdio.h>
#include <stdlib.h>

long long mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left;    // Index for left subarray
    int j = mid + 1; // Index for right subarray
    int k = left;    // Index for resultant merged subarray
    long long inv_count = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        } else {
            // There is an inversion
            temp[k++] = arr[j++];
            // All elements from arr[i] to arr[mid] are greater than arr[j]
            inv_count += (mid - i + 1);
        }
    }

    // Copy remaining elements of left subarray
    while (i <= mid) temp[k++] = arr[i++];

    // Copy remaining elements of right subarray
    while (j <= right) temp[k++] = arr[j++];

    // Copy back to original array
    for (i = left; i <= right; i++) arr[i] = temp[i];

    return inv_count;
}

long long mergeSort(int arr[], int temp[], int left, int right) {
    long long inv_count = 0;
    if (left < right) {
        int mid = left + (right - left) / 2;

        inv_count += mergeSort(arr, temp, left, mid);
        inv_count += mergeSort(arr, temp, mid + 1, right);
        inv_count += mergeAndCount(arr, temp, left, mid, right);
    }
    return inv_count;
}

int main() {
    int arr[] = {8, 4, 2, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int* temp = (int*)malloc(sizeof(int) * n);
    
    printf("Number of inversions: %lld\n", mergeSort(arr, temp, 0, n - 1));
    
    free(temp);
    return 0;
}