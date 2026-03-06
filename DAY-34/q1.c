#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push(int value)
{
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data = value;
    newnode->next = top;
    top = newnode;
}

int pop()
{
    int value;
    struct node *temp;

    if(top == NULL)
    {
        printf("Stack Underflow\n");
        return 0;
    }

    temp = top;
    value = temp->data;
    top = top->next;
    free(temp);
    return value;
}

int main()
{
    char exp[100];
    int i, op1, op2, result;

    printf("Enter postfix expression: ");
    fgets(exp, sizeof(exp), stdin);

    for(i = 0; exp[i] != '\0'; i++)
    {
        if(isdigit(exp[i]))
        {
            push(exp[i] - '0');
        }

        else if(exp[i] == '+' || exp[i] == '-' || exp[i] == '*' || exp[i] == '/')
        {
            op2 = pop();
            op1 = pop();

            switch(exp[i])
            {
                case '+': push(op1 + op2); break;
                case '-': push(op1 - op2); break;
                case '*': push(op1 * op2); break;
                case '/': push(op1 / op2); break;
            }
        }
    }

    result = pop();
    printf("%d", result);

    return 0;
}