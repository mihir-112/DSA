#include<stdio.h>

char stack[50];
int top=-1;

void push(char ch)
{
stack[++top]=ch;
}

char pop()
{
return stack[top--];
}

int precedence(char ch)
{
if(ch=='^')
return 3;
if(ch=='*'||ch=='/')
return 2;
if(ch=='+'||ch=='-')
return 1;
return -1;
}

int isOperator(char ch)
{
if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
return 1;
return 0;
}

void infixtopostfix(char in[50])
{
char postfix[50];
int i,j=0;

for(i=0;in[i]!='\0';i++)
{
if((in[i]>='A'&&in[i]<='Z')||(in[i]>='a'&&in[i]<='z')||(in[i]>='0'&&in[i]<='9'))
postfix[j++]=in[i];

else if(in[i]=='(')
push(in[i]);

else if(in[i]==')')
{
while(top!=-1&&stack[top]!='(')
postfix[j++]=pop();
pop();
}

else if(isOperator(in[i]))
{
while(top!=-1&&stack[top]!='('&&precedence(stack[top])>=precedence(in[i]))
postfix[j++]=pop();

push(in[i]);
}
}

while(top!=-1)
postfix[j++]=pop();

postfix[j]='\0';

printf("Postfix expression=%s",postfix);
}

int main()
{
char infix[50];

printf("Enter the expression:");
scanf("%s",infix);

infixtopostfix(infix);

return 0;
}



#include<stdio.h>

int stack[50];
int top=-1;

void push(int value)
{
stack[++top]=value;
}

int pop()
{
return stack[top--];
}

int main()
{
char postfix[50];
int i;
int a,b;

printf("Enter postfix expression:");
scanf("%s",postfix);

for(i=0;postfix[i]!='\0';i++)
{
if(postfix[i]>='0'&&postfix[i]<='9')
push(postfix[i]-'0');

else
{
b=pop();
a=pop();

if(postfix[i]=='+')
push(a+b);
else if(postfix[i]=='-')
push(a-b);
else if(postfix[i]=='*')
push(a*b);
else if(postfix[i]=='/')
push(a/b);
else if(postfix[i]=='^')
{
int result=1;
int j;

for(j=0;j<b;j++)
result=result*a;

push(result);
}
}
}

printf("Result=%d",pop());

return 0;
}