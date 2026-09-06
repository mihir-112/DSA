// radix Sort
#include <stdio.h>

int getMax(int *arr, int n)
{
int max = arr[0];


for (int i = 1; i < n; i++)
{
    if (arr[i] > max)
    {
        max = arr[i];
    }
}

return max;


}

void countSort(int *arr, int n, int exp)
{
int output[n];
int count[10] = {0};


for (int i = 0; i < n; i++)
{
    int index = (arr[i] / exp) % 10;

    count[index]++;
}

for (int i = 1; i < 10; i++)
{
    count[i] = count[i] + count[i - 1];
}

for (int i = n - 1; i >= 0; i--)
{
    int index = (arr[i] / exp) % 10;

    output[count[index] - 1] = arr[i];

    count[index]--;
}

for (int i = 0; i < n; i++)
{
    arr[i] = output[i];
}


}

void radixSort(int *arr, int n)
{
int max = getMax(arr, n);


for (int exp = 1; max / exp > 0; exp = exp * 10)
{
    countSort(arr, n, exp);
}


}

int main()
{
int n;


printf("Enter number of elements: ");
scanf("%d", &n);

int arr[n];

printf("Enter elements:\n");

for (int i = 0; i < n; i++)
{
    scanf("%d", &arr[i]);
}

radixSort(arr, n);

printf("Sorted array:\n");

for (int i = 0; i < n; i++)
{
    printf("%d ", arr[i]);
}

printf("\n");

return 0;


}
