#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *top = NULL;

void push()
{
    struct node *newnode;
    int x;

    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter the element: ");
    scanf("%d", &x);

    newnode->data = x;
    newnode->next = top;
    top = newnode;
}

void pop()
{
    struct node *temp;

    if(top == NULL)
        printf("Stack Underflow\n");
    else
    {
        temp = top;
        printf("Deleted element = %d\n", top->data);
        top = top->next;
        free(temp);
    }
}

void display()
{
    struct node *temp = top;

    if(top == NULL)
        printf("Stack is empty\n");
    else
    {
        while(temp != NULL)
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

int main()
{
    int ch;

    while(1)
    {
        printf("\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: push(); break;
            case 2: pop(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
