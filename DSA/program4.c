#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;
struct node *next;
};

struct node *head = NULL;

void insertBeginning(int value)
{
struct node *newNode;


newNode = (struct node *)malloc(sizeof(struct node));

newNode->data = value;
newNode->next = head;

head = newNode;


}

void insertPosition(int value, int position)
{
struct node *newNode;
struct node *temp;


newNode = (struct node *)malloc(sizeof(struct node));

newNode->data = value;

if (position == 1)
{
    newNode->next = head;
    head = newNode;

    return;
}

temp = head;

for (int i = 1; i < position - 1; i++)
{
    if (temp == NULL)
    {
        printf("Invalid position\n");
        return;
    }

    temp = temp->next;
}

if (temp == NULL)
{
    printf("Invalid position\n");
    return;
}

newNode->next = temp->next;
temp->next = newNode;


}

void deleteValue(int value)
{
struct node *temp;
struct node *prev;


temp = head;
prev = NULL;

while (temp != NULL)
{
    if (temp->data == value)
    {
        break;
    }

    prev = temp;
    temp = temp->next;
}

if (temp == NULL)
{
    printf("Element not found\n");
    return;
}

if (prev == NULL)
{
    head = head->next;
}
else
{
    prev->next = temp->next;
}

free(temp);

printf("Element deleted\n");


}

void search(int value)
{
struct node *temp;


temp = head;

int position = 1;

while (temp != NULL)
{
    if (temp->data == value)
    {
        printf("Element found at position %d\n", position);
        return;
    }

    temp = temp->next;
    position++;
}

printf("Element not found\n");


}

void display()
{
struct node *temp;


temp = head;

if (head == NULL)
{
    printf("List is empty\n");
    return;
}

while (temp != NULL)
{
    printf("%d ", temp->data);
    temp = temp->next;
}

printf("\n");


}

void reverse()
{
struct node *prev = NULL;
struct node *current = head;
struct node *next;


while (current != NULL)
{
    next = current->next;

    current->next = prev;

    prev = current;
    current = next;
}

head = prev;


}

int main()
{
int choice;
int value;
int position;


do
{
    printf("\n1. Insert at beginning\n");
    printf("2. Insert at position\n");
    printf("3. Delete by value\n");
    printf("4. Search\n");
    printf("5. Display\n");
    printf("6. Reverse\n");
    printf("7. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        insertBeginning(value);
    }

    else if (choice == 2)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        printf("Enter position: ");
        scanf("%d", &position);

        insertPosition(value, position);
    }

    else if (choice == 3)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        deleteValue(value);
    }

    else if (choice == 4)
    {
        printf("Enter value: ");
        scanf("%d", &value);

        search(value);
    }

    else if (choice == 5)
    {
        display();
    }

    else if (choice == 6)
    {
        reverse();

        printf("Reversed list:\n");
        display();
    }

} while (choice != 7);

return 0;


}
