#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

int main()
{
    int n, i, key, count = 0;
    struct Node *head = NULL, *temp = NULL, *newnode = NULL;

    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newnode = (struct Node*)malloc(sizeof(struct Node));
        scanf("%d", &newnode->data);
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
        }
    }

    scanf("%d", &key);

    temp = head;

    while(temp != NULL)
    {
        if(temp->data == key)
        {
            count++;
        }
        temp = temp->next;
    }

    printf("%d", count);

    return 0;
}