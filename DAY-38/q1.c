#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

void push_front(int x) {
    if (front == 0) {
        printf("Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        front--;
    }
    deque[front] = x;
}

void push_back(int x) {
    if (rear == MAX - 1) {
        printf("Overflow\n");
        return;
    }
    if (front == -1) {
        front = rear = 0;
    } else {
        rear++;
    }
    deque[rear] = x;
}

int pop_front() {
    if (front == -1) return -1;

    int val = deque[front];
    if (front == rear)
        front = rear = -1;
    else
        front++;

    return val;
}

int pop_back() {
    if (rear == -1) return -1;

    int val = deque[rear];
    if (front == rear)
        front = rear = -1;
    else
        rear--;

    return val;
}

int get_front() {
    if (front == -1) return -1;
    return deque[front];
}

int get_back() {
    if (rear == -1) return -1;
    return deque[rear];
}

int size() {
    if (front == -1) return 0;
    return rear - front + 1;
}

int empty() {
    return (front == -1);
}

void display() {
    if (empty()) {
        printf("Deque is empty\n");
        return;
    }

    for (int i = front; i <= rear; i++)
        printf("%d ", deque[i]);
    printf("\n");
}

int main() {
    push_back(10);
    push_back(20);
    push_front(5);

    printf("Front: %d\n", get_front());
    printf("Back: %d\n", get_back());

    printf("Pop Front: %d\n", pop_front());
    printf("Pop Back: %d\n", pop_back());

    printf("Size: %d\n", size());

    display();

    return 0;
}