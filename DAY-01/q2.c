#include <stdio.h>
int main() {
    int arr[] = {2, 7, 11, 15};
    int target = 9;
    int n = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] + arr[j] == target) {
                printf("Indices: %d %d\n", i, j);
                return 0;
            }
        }
    }
    printf("No pair found");
    return 0;
}