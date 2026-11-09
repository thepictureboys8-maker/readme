#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *front = NULL;
struct node *rear = NULL;

void enqueue()
{
    struct node *newnode;
    int x;

    newnode = (struct node*)malloc(sizeof(struct node));
    if(newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return;
    }

    printf("Enter element: ");
    scanf("%d", &x);

    newnode->data = x;
    newnode->next = NULL;

    if(front == NULL)
        front = rear = newnode;
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

void dequeue()
{
    struct node *temp;

    if(front == NULL)
        printf("Queue Underflow\n");
    else
    {
        temp = front;
        printf("Deleted element = %d\n", front->data);
        front = front->next;

        if(front == NULL)
            rear = NULL;

        free(temp);
    }
}

void display()
{
    struct node *temp = front;

    if(front == NULL)
        printf("Queue is empty\n");
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
        printf("\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n");
        scanf("%d", &ch);

        switch(ch)
        {
            case 1: enqueue(); break;
            case 2: dequeue(); break;
            case 3: display(); break;
            case 4: return 0;
            default: printf("Invalid choice\n");
        }
    }
}
