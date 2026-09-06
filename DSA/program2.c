#include <stdio.h>

void max(int (*p)[10], int *r, int *c)
{
int res[10];


for (int i = 0; i < *r; i++)
{
    int max = p[i][0];

    for (int j = 0; j < *c; j++)
    {
        if (p[i][j] > max)
        {
            max = p[i][j];
        }
    }

    res[i] = max;
}

printf("\nMaximum element in each row:\n");

for (int i = 0; i < *r; i++)
{
    printf("Row %d = %d\n", i + 1, res[i]);
}


}

int main()
{
int r, c;


printf("Enter the number of rows: ");
scanf("%d", &r);

printf("Enter the number of columns: ");
scanf("%d", &c);

int arr[10][10];

printf("Enter the elements of matrix:\n");

for (int i = 0; i < r; i++)
{
    for (int j = 0; j < c; j++)
    {
        scanf("%d", &arr[i][j]);
    }
}

max(arr, &r, &c);

return 0;


}
