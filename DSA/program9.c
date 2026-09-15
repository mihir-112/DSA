#include <stdio.h>

char stack[100];
int top = -1;

void push(char ch)
{
    top++;
    stack[top] = ch;
}

char pop()
{
    char ch;

    ch = stack[top];
    top--;

    return ch;
}

int priority(char ch)
{
    if (ch == '^')
        return 3;

    if (ch == '*' || ch == '/')
        return 2;

    if (ch == '+' || ch == '-')
        return 1;

    return 0;
}

int main()
{
    char infix[100];
    char postfix[100];

    int i = 0;
    int j = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    while (infix[i] != '\0')
    {
        char ch = infix[i];

        if ((ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9'))
        {
            postfix[j] = ch;
            j++;
        }

        else if (ch == '(')
        {
            push(ch);
        }

        else if (ch == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                postfix[j] = pop();
                j++;
            }

            pop();
        }

        else
        {
            while (top != -1 &&
                   priority(stack[top]) >= priority(ch))
            {
                postfix[j] = pop();
                j++;
            }

            push(ch);
        }

        i++;
    }

    while (top != -1)
    {
        postfix[j] = pop();
        j++;
    }

    postfix[j] = '\0';

    printf("Postfix expression = %s", postfix);

    return 0;
}


// postfix evaluation
/* #include <stdio.h>
int stack[100];
int top=-1;
void push(int value)
{
top++;
stack[top]=value;
}
int pop()
{
int value;
value=stack[top];
top--;
return value;
}
int main()
{
char postfix[100];
int i=0;
printf("Enter postfix expression: ");
scanf("%s",postfix);
while(postfix[i]!='\0')
{
char ch=postfix[i];
if(ch>='0'&&ch<='9')
{
push(ch-'0');
}
else
{
int b=pop();
int a=pop();
if(ch=='+')
push(a+b);
else if(ch=='-')
push(a-b);
else if(ch=='*')
push(a*b);
else if(ch=='/')
push(a/b);
}
i++;
}
printf("Result=%d",pop());
return 0;
}
*/
