#include <stdio.h>

#define MAX 100

int queue[MAX];
int stack[MAX];

int front = 0, rear = -1;
int top = -1;

void enqueue(int x)
{
    rear++;
    queue[rear] = x;
}

int dequeue()
{
    int x = queue[front];
    front++;
    return x;
}

void push(int x)
{
    top++;
    stack[top] = x;
}

int pop()
{
    int x = stack[top];
    top--;
    return x;
}

int main()
{
    int n, i, x;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &x);
        enqueue(x);
    }
    for(i = 0; i < n; i++)
    {
        push(dequeue());
    }
    for(i = 0; i < n; i++)
    {
        enqueue(pop());
    } 
    for(i = front; i <= rear; i++)
    {
        printf("%d ", queue[i]);
    }

    return 0;
}