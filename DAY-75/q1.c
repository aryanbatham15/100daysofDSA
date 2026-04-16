#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maxLenZeroSum(int arr[], int n) {
    int *keys = malloc(n * sizeof(int));
    int *vals = malloc(n * sizeof(int));
    int size = 0;
    
    int maxLen = 0, sum = 0;
    
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        
        if (sum == 0) maxLen = i + 1;
        
        int found = 0;
        for (int j = 0; j < size; j++) {
            if (keys[j] == sum) {
                if (i - vals[j] > maxLen) maxLen = i - vals[j];
                found = 1;
                break;
            }
        }
        
        if (!found) {
            keys[size] = sum;
            vals[size] = i;
            size++;
        }
    }
    
    free(keys);
    free(vals);
    return maxLen;
}

int main() {
    int arr[1000], n = 0;
    while (scanf("%d", &arr[n]) == 1) n++;
    printf("%d\n", maxLenZeroSum(arr, n));
    return 0;
}