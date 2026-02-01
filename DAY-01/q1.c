#include <stdio.h>
int main() {
    int arr[10], n, pos, element;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter position: ");
    scanf("%d", &pos);

    printf("Enter element to insert: ");
    scanf("%d", &element);
    for(int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = element;
    printf("Array after insertion:\n");
    for(int i = 0; i <= n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}