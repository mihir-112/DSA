#include <stdio.h>

struct account
{
int accountNumber;
char name[50];
float balance;
};

void display(struct account arr[], int n)
{
for (int i = 0; i < n; i++)
{
printf("\nAccount Number : %d\n", arr[i].accountNumber);
printf("Name : %s\n", arr[i].name);
printf("Balance : %.2f\n", arr[i].balance);
}
}

int search(struct account arr[], int n, int key)
{
for (int i = 0; i < n; i++)
{
if (arr[i].accountNumber == key)
{
return i;
}
}


return -1;


}

int main()
{
int n;
int choice;
int key;
int index;
float amount;


printf("Enter number of accounts: ");
scanf("%d", &n);

struct account arr[n];

for (int i = 0; i < n; i++)
{
    printf("\nEnter account number: ");
    scanf("%d", &arr[i].accountNumber);

    printf("Enter name: ");
    scanf(" %[^\n]", arr[i].name);

    printf("Enter balance: ");
    scanf("%f", &arr[i].balance);
}

do
{
    printf("\n1. Display\n");
    printf("2. Deposit\n");
    printf("3. Withdraw\n");
    printf("4. Search\n");
    printf("5. Total Balance\n");
    printf("6. Exit\n");

    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1)
    {
        display(arr, n);
    }

    else if (choice == 2)
    {
        printf("Enter account number: ");
        scanf("%d", &key);

        index = search(arr, n, key);

        if (index == -1)
        {
            printf("Account not found\n");
        }
        else
        {
            printf("Enter amount: ");
            scanf("%f", &amount);

            arr[index].balance =
                arr[index].balance + amount;

            printf("Amount deposited successfully\n");
        }
    }

    else if (choice == 3)
    {
        printf("Enter account number: ");
        scanf("%d", &key);

        index = search(arr, n, key);

        if (index == -1)
        {
            printf("Account not found\n");
        }
        else
        {
            printf("Enter amount: ");
            scanf("%f", &amount);

            if (amount > arr[index].balance)
            {
                printf("Insufficient balance\n");
            }
            else
            {
                arr[index].balance =
                    arr[index].balance - amount;

                printf("Amount withdrawn successfully\n");
            }
        }
    }

    else if (choice == 4)
    {
        printf("Enter account number to search: ");
        scanf("%d", &key);

        index = search(arr, n, key);

        if (index == -1)
        {
            printf("Account not found\n");
        }
        else
        {
            printf("Account found\n");
            printf("Account Number : %d\n",
                   arr[index].accountNumber);
            printf("Name : %s\n",
                   arr[index].name);
            printf("Balance : %.2f\n",
                   arr[index].balance);
        }
    }

    else if (choice == 5)
    {
        float total = 0;

        for (int i = 0; i < n; i++)
        {
            total = total + arr[i].balance;
        }

        printf("Total Balance = %.2f\n", total);
    }

} while (choice != 6);

return 0;


}
