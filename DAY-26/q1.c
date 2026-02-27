#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

int main()
{
    int n, i;
    struct Node *head = NULL, *temp = NULL, *newnode = NULL;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newnode->data);
        newnode->prev = NULL;
        newnode->next = NULL;

        if(head == NULL)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            newnode->prev = temp;
            temp = newnode;
        }
    }

    temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}