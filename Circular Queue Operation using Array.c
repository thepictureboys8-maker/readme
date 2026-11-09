#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1, rear = -1;

void enqueue()
{
    int x;

    if((rear + 1) % MAX == front)
        printf("Queue Overflow\n");
    else
    {
        printf("Enter element: ");
        scanf("%d", &x);

        if(front == -1)
            front = rear = 0;
        else
            rear = (rear + 1) % MAX;

        queue[rear] = x;
    }
}

void dequeue()
{
    if(front == -1)
        printf("Queue Underflow\n");
    else
    {
        printf("Deleted element = %d\n", queue[front]);

        if(front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
    }
}

void display()
{
    int i;

    if(front == -1)
        printf("Queue is empty\n");
    else
    {
        i = front;

        while(1)
        {
            printf("%d ", queue[i]);
            if(i == rear)
                break;
            i = (i + 1) % MAX;
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
