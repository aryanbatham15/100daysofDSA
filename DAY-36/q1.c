#include <stdio.h>

#define MAX 100

int q[MAX];
int front = -1, rear = -1;

void enqueue(int x, int n)
{
    if ((rear + 1) % n == front)
        return;

    if (front == -1)
        front = 0;

    rear = (rear + 1) % n;
    q[rear] = x;
}

void dequeue(int n)
{
    if (front == -1)
        return;

    if (front == rear)
        front = rear = -1;
    else
        front = (front + 1) % n;
}

void display(int n)
{
    if (front == -1)
        return;

    int i = front;
    while (1)
    {
        printf("%d ", q[i]);
        if (i == rear)
            break;
        i = (i + 1) % n;
    }
}

int main()
{
    int n, m, x;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x, n);
    }

    scanf("%d", &m);

    for (int i = 0; i < m; i++)
        dequeue(n);

    display(n);

    return 0;
}