#include<stdio.h>
#include<ctype.h>
char stack[100];
int top=-1;
void push(char value)
{
top++;
stack[top]=value;
}
char pop()
{
char value;
value=stack[top];
top--;
return value;
}
int precedence(char ch)
{
if(ch=='^')
{
return 3;
}
if(ch=='*'||ch=='/')
{
return 2;
}
if(ch=='+'||ch=='-')
{
return 1;
}
return 0;
}
int main()
{
char infix[100];
char postfix[100];
int i=0;
int j=0;
printf("Enter infix expression: ");
scanf("%s",infix);
while(infix[i]!='\0')
{
char ch=infix[i];
if(isalnum(ch))
{
postfix[j]=ch;
j++;
}
else if(ch=='(')
{
push(ch);
}
else if(ch==')')
{
while(top!=-1&&stack[top]!='(')
{
postfix[j]=pop();
j++;
}
pop();
}
else
{
while(top!=-1&&precedence(stack[top])>=precedence(ch))
{
postfix[j]=pop();
j++;
}
push(ch);
}
i++;
}
while(top!=-1)
{
postfix[j]=pop();
j++;
}
postfix[j]='\0';
printf("Postfix expression = %s\n",postfix);
return 0;
}