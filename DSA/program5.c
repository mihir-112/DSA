#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node *next;
};

struct node *head = NULL;

void insertEnd(int value)
{
struct node *newNode;
struct node *temp;

newNode = (struct node *)malloc(sizeof(struct node));

newNode->data = value;

if (head == NULL)
{
    head = newNode;
    newNode->next = head;
}
else
{
    temp = head;

    while (temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;
}

}

void deleteFront()
{
struct node *temp;
struct node *last;

if (head == NULL)
{
    printf("List is empty\n");
    return;
}

if (head->next == head)
{
    temp = head;
    head = NULL;

    free(temp);

    return;
}

last = head;

while (last->next != head)
{
    last = last->next;
}

temp = head;

head = head->next;

last->next = head;

free(temp);

}

void deleteKey(int key)
{
struct node *temp;
struct node *prev;

if (head == NULL)
{
    printf("List is empty\n");
    return;
}

if (head->data == key)
{
    deleteFront();
    return;
}

prev = head;
temp = head->next;

while (temp != head)
{
    if (temp->data == key)
    {
        break;
    }

    prev = temp;
    temp = temp->next;
}

if (temp == head)
{
    printf("Element not found\n");
    return;
}

prev->next = temp->next;

free(temp);

printf("Element deleted\n");

}

void displayAlternate()
{
struct node *temp;

if (head == NULL)
{
    printf("List is empty\n");
    return;
}

temp = head;

int count = 1;

do
{
    if (count % 2 != 0)
    {
        printf("%d ", temp->data);
    }

    temp = temp->next;
    count++;

} while (temp != head);

printf("\n");

}

void display()
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

int main()
{
int choice;
int value;

do
{
    printf("\n1. Insert at end\n");
    printf("2. Delete from front\n");
    printf("3. Delete by key\n");
    printf("4. Display alternate elements\n");
    printf("5. Display all elements\n");
    printf("6. Exit\n");

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
        deleteFront();
    }

    else if (choice == 3)
    {
        printf("Enter key: ");
        scanf("%d", &value);

        deleteKey(value);
    }

    else if (choice == 4)
    {
        displayAlternate();
    }

    else if (choice == 5)
    {
        display();
    }

} while (choice != 6);

return 0;

}
