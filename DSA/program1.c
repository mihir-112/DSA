#include <stdio.h>

void max(int *arr, int *n)
{
int max = arr[0];


for (int i = 0; i < *n; i++)
{
    if (arr[i] > max)
    {
        max = arr[i];
    }
}

printf("Max is : %d\n", max);


}

int search(int *arr, int *n)
{
int marks;


printf("Enter the marks to search : ");
scanf("%d", &marks);

for (int i = 0; i < *n; i++)
{
    if (arr[i] == marks)
    {
        return i + 1;
    }
}

return -1;


}

int main()
{
int n;


printf("Enter the size of array: ");
scanf("%d", &n);

int arr[n];

printf("Enter the elements of array:\n");

for (int i = 0; i < n; i++)
{
    scanf("%d", &arr[i]);
}

max(arr, &n);

int index = search(arr, &n);

if (index == -1)
{
    printf("Element not found\n");
}
else
{
    printf("Element found at position %d\n", index);
}

return 0;


}
