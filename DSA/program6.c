#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;


struct node *prev;
struct node *next;


};

struct node *head = NULL;

void insertFront(int value)
{
struct node *newNode;


newNode = (struct node *)malloc(sizeof(struct node));

newNode->data = value;

newNode->prev = NULL;
newNode->next = head;

if (head != NULL)
{
    head->prev = newNode;
}

head = newNode;


}

void insertBefore(int key, int value)
{
struct node *temp;
struct node *newNode;


temp = head;

while (temp != NULL)
{
    if (temp->data == key)
    {
        break;
    }

    temp = temp->next;
}

if (temp == NULL)
{
    printf("Element not found\n");
    return;
}

newNode = (struct node *)malloc(sizeof(struct node));

newNode->data = value;

newNode->next = temp;
newNode->prev = temp->prev;

if (temp->prev != NULL)
{
    temp->prev->next = newNode;
}
else
{
    head = newNode;
}

temp->prev = newNode;


}

void deleteValue(int value)
{
struct node *temp;


temp = head;

while (temp != NULL)
{
    if (temp->data == value)
    {
        break;
    }

    temp = temp->next;
}

if (temp == NULL)
{
    printf("Element not found\n");
    return;
}

if (temp->prev != NULL)
{
    temp->prev->next = temp->next;
}
else
{
    head = temp->next;
}

if (temp->next != NULL)
{
    temp->next->prev = temp->prev;
}

free(temp);

printf("Element deleted\n");


}

void display()
{
struct node *temp;


temp = head;

while (temp != NULL)
{
    printf("%d ", temp->data);

    temp = temp->next;
}

printf("\n");


}

int main()
{
int choice;
int value;
int key;


do
{
    printf("\n1. Insert at front\n");
    printf("2. Insert before an element\n");
    printf("3. Delete by value\n");
    printf("4. Display\n");
    printf("5. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        insertFront(value);
    }

    else if (choice == 2)
    {
        printf("Enter key: ");
        scanf("%d", &key);

        printf("Enter value: ");
        scanf("%d", &value);

        insertBefore(key, value);
    }

    else if (choice == 3)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        deleteValue(value);
    }

    else if (choice == 4)
    {
        display();
    }

} while (choice != 5);

return 0;


}
