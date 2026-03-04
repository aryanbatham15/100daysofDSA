#include <stdio.h>

#define MAX 100

int main() {
    int stack[MAX];
    int top = -1;
    int n, m;

    // Read number of elements
    scanf("%d", &n);

    // Push n elements
    for(int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        stack[++top] = value;
    }

    // Number of pops
    scanf("%d", &m);

    // Perform m pops
    for(int i = 0; i < m; i++) {
        if(top != -1) {
            top--;
        }
    }

    // Display remaining stack (top to bottom)
    for(int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}