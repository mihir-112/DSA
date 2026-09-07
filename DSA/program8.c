#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 5

int stack[MAX_SIZE];

int push(int top,int id)
{
if(top>=MAX_SIZE-1)
{
printf("\nStack Overflow! History is full.\n");
}
else
{
top++;
stack[top]=id;
}
return top;
}

int pop(int top)
{
if(top==-1)
{
printf("\nStack Underflow! History is empty.\n");
}
else
{
printf("\nWebpage %d removed from history.\n",stack[top]);
top--;
}
return top;
}

void display(int top)
{
int i;
if(top==-1)
{
printf("\nHistory is empty.\n");
}
else
{
printf("\nThe current browser history:\n");
for(i=top;i>=0;i--)
{
printf("%d\n",stack[i]);
}
}
}

int main()
{
int top=-1,choice,id;

while(1)
{
printf("\n----- Browser History -----\n");
printf("1. Visit a new webpage (Push)\n");
printf("2. Press Back (Pop)\n");
printf("3. Display History\n");
printf("4. Exit\n");
printf("\nEnter the Choice: ");
scanf("%d",&choice);

switch(choice)
{
case 1:
printf("Enter webpage ID: ");
scanf("%d",&id);
top=push(top,id);
break;

case 2:
top=pop(top);
break;

case 3:
display(top);
break;

case 4:
printf("\nEXIT POINT\n");
exit(0);

default:
printf("\nEnter a Valid Choice\n");
}
}

return 0;
}