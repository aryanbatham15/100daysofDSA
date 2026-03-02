#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    int n, i, k, value, count = 1;
    struct Node *head = NULL, *temp = NULL, *newnode = NULL, *last = NULL;

    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &value);
        newnode = (struct Node*)malloc(sizeof(struct Node));
        newnode->data = value;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
            count++;
        }
    }

    scanf("%d", &k);

    if(head == NULL || head->next == NULL)
        return 0;

    k = k % count;   

    if(k == 0)
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        return 0;
    }
    last = head;
    while(last->next != NULL)
        last = last->next;
    last->next = head;
    temp = head;
    for(i = 1; i < count - k; i++)
        temp = temp->next;
    head = temp->next;
    temp->next = NULL;
    temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}