#include <stdio.h>

#define MAX 5

int stack[MAX];
int top = -1;

void push(int value)
{
if (top == MAX - 1)
{
printf("Stack Overflow\n");
return;
}


top++;

stack[top] = value;


}

void pop()
{
if (top == -1)
{
printf("Stack Underflow\n");
return;
}


printf("Deleted element = %d\n", stack[top]);

top--;


}

void display()
{
if (top == -1)
{
printf("Stack is empty\n");
return;
}


printf("Stack elements are:\n");

for (int i = top; i >= 0; i--)
{
    printf("%d\n", stack[i]);
}


}

int main()
{
int choice;
int value;


do
{
    printf("\n1. Push\n");
    printf("2. Pop\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        push(value);
    }

    else if (choice == 2)
    {
        pop();
    }

    else if (choice == 3)
    {
        display();
    }

} while (choice != 4);

return 0;


}
