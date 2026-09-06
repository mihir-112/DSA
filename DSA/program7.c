#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;


struct node *prev;
struct node *next;


};

struct node *head = NULL;

void insertEnd(int value)
{
struct node *newNode;
struct node *last;


newNode = (struct node *)malloc(sizeof(struct node));

newNode->data = value;

if (head == NULL)
{
    head = newNode;

    newNode->next = head;
    newNode->prev = head;
}
else
{
    last = head->prev;

    newNode->next = head;
    newNode->prev = last;

    last->next = newNode;
    head->prev = newNode;
}


}

void deleteKey(int key)
{
struct node *temp;


if (head == NULL)
{
    printf("List is empty\n");
    return;
}

temp = head;

do
{
    if (temp->data == key)
    {
        break;
    }

    temp = temp->next;

} while (temp != head);

if (temp == head && temp->data != key)
{
    printf("Element not found\n");
    return;
}

if (temp->next == temp)
{
    head = NULL;
}
else
{
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;

    if (temp == head)
    {
        head = temp->next;
    }
}

free(temp);

printf("Element deleted\n");


}

void displayForward()
{
struct node *temp;


if (head == NULL)
{
    printf("List is empty\n");
    return;
}

temp = head;

do
{
    printf("%d ", temp->data);

    temp = temp->next;

} while (temp != head);

printf("\n");


}

void displayReverse()
{
struct node *temp;


if (head == NULL)
{
    printf("List is empty\n");
    return;
}

temp = head->prev;

do
{
    printf("%d ", temp->data);

    temp = temp->prev;

} while (temp != head->prev);

printf("\n");


}

int main()
{
int choice;
int value;


do
{
    printf("\n1. Insert at end\n");
    printf("2. Delete by key\n");
    printf("3. Display forward\n");
    printf("4. Display reverse\n");
    printf("5. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        insertEnd(value);
    }

    else if (choice == 2)
    {
        printf("Enter key: ");
        scanf("%d", &value);

        deleteKey(value);
    }

    else if (choice == 3)
    {
        displayForward();
    }

    else if (choice == 4)
    {
        displayReverse();
    }

} while (choice != 5);

return 0;


}
