// Queues using Array
#include <stdio.h>

#define MAX 5

int queue[MAX];

int front = -1;
int rear = -1;

void enqueue(int value)
{
if (rear == MAX - 1)
{
printf("Queue Overflow\n");
return;
}


if (front == -1)
{
    front = 0;
}

rear++;

queue[rear] = value;


}

void dequeue()
{
if (front == -1)
{
printf("Queue Underflow\n");
return;
}


printf("Deleted element = %d\n", queue[front]);

front++;

if (front > rear)
{
    front = -1;
    rear = -1;
}


}

void display()
{
if (front == -1)
{
printf("Queue is empty\n");
return;
}


for (int i = front; i <= rear; i++)
{
    printf("%d ", queue[i]);
}

printf("\n");


}

int main()
{
int choice;
int value;


do
{
    printf("\n1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        enqueue(value);
    }

    else if (choice == 2)
    {
        dequeue();
    }

    else if (choice == 3)
    {
        display();
    }

} while (choice != 4);

return 0;


}


// Circular Queue
/*
#include <stdio.h>

#define MAX 5

int queue[MAX];

int front = -1;
int rear = -1;

void enqueue(int value)
{
if ((rear + 1) % MAX == front)
{
printf("Queue Overflow\n");
return;
}


if (front == -1)
{
    front = 0;
    rear = 0;
}
else
{
    rear = (rear + 1) % MAX;
}

queue[rear] = value;


}

void dequeue()
{
if (front == -1)
{
printf("Queue Underflow\n");
return;
}


printf("Deleted element = %d\n", queue[front]);

if (front == rear)
{
    front = -1;
    rear = -1;
}
else
{
    front = (front + 1) % MAX;
}


}

void display()
{
if (front == -1)
{
printf("Queue is empty\n");
return;
}


int i = front;

while (1)
{
    printf("%d ", queue[i]);

    if (i == rear)
    {
        break;
    }

    i = (i + 1) % MAX;
}

printf("\n");


}

int main()
{
int choice;
int value;


do
{
    printf("\n1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        enqueue(value);
    }

    else if (choice == 2)
    {
        dequeue();
    }

    else if (choice == 3)
    {
        display();
    }

} while (choice != 4);

return 0;


}

*/