#include <stdio.h>

int binary_search(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            return mid;
        } else if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    int numbers[] = {1, 3, 5, 7, 9, 11};
    int size = sizeof(numbers) / sizeof(numbers);
    int result = binary_search(numbers, size, 7);
    printf("%d\n", result);
    return 0;
}