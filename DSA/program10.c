// tower of haoi
#include <stdio.h>

void tower(int n, char source, char auxiliary, char destination)
{
if (n == 1)
{
printf("Move disk 1 from %c to %c\n",
source, destination);


    return;
}

tower(n - 1, source, destination, auxiliary);

printf("Move disk %d from %c to %c\n",
       n, source, destination);

tower(n - 1, auxiliary, source, destination);


}

int main()
{
int n;


printf("Enter number of disks: ");
scanf("%d", &n);

tower(n, 'A', 'B', 'C');

return 0;


}

//Binary Search
/*
#include <stdio.h>

int binarySearch(int *arr, int n, int key)
{
int low = 0;
int high = n - 1;


while (low <= high)
{
    int mid = (low + high) / 2;

    if (arr[mid] == key)
    {
        return mid + 1;
    }

    else if (key < arr[mid])
    {
        high = mid - 1;
    }

    else
    {
        low = mid + 1;
    }
}

return -1;


}

int main()
{
int n;


printf("Enter size of array: ");
scanf("%d", &n);

int arr[n];

printf("Enter sorted elements:\n");

for (int i = 0; i < n; i++)
{
    scanf("%d", &arr[i]);
}

int key;

printf("Enter element to search: ");
scanf("%d", &key);

int result = binarySearch(arr, n, key);

if (result == -1)
{
    printf("Element not found\n");
}
else
{
    printf("Element found at position %d\n", result);
}

return 0;


}

*/