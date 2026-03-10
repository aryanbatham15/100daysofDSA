#include <stdio.h>
#include <string.h>

#define MAX 100

int pq[MAX];
int size = 0;

void insert(int x) {
    pq[size++] = x;
}

int delete() {
    if (size == 0)
        return -1;

    int minIndex = 0;

    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[minIndex]) {
            minIndex = i;
        }
    }

    int value = pq[minIndex];

    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }

    size--;

    return value;
}

int peek() {
    if (size == 0)
        return -1;

    int min = pq[0];

    for (int i = 1; i < size; i++) {
        if (pq[i] < min) {
            min = pq[i];
        }
    }

    return min;
}

int main() {
    int n, x;
    char op[10];

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%s", op);

        if (strcmp(op, "insert") == 0) {
            scanf("%d", &x);
            insert(x);
        }
        else if (strcmp(op, "delete") == 0) {
            printf("%d\n", delete());
        }
        else if (strcmp(op, "peek") == 0) {
            printf("%d\n", peek());
        }
    }

    return 0;
}