#include<stdio.h>
#include<ctype.h>
char stack[50];
int top=-1;
void push(char ch){
stack[++top]=ch;
}
char pop(){
return stack[top--];
}
int precedence(char ch){
if(ch=='^')
return 3;
if(ch=='*'||ch=='/')
return 2;
if(ch=='+'||ch=='-')
return 1;
return -1;
}
int isOperator(char ch){
if(ch=='+'||ch=='-'||ch=='*'||ch=='/'||ch=='^')
return 1;
return 0;
}
void infixtopostfix(char in[50]){
char postfix[50];
int i,j=0;
for(i=0;in[i]!='\0';i++){
if(isalnum(in[i]))
postfix[j++]=in[i];
else if(in[i]=='(')
push(in[i]);
else if(in[i]==')'){
while(top!=-1&&stack[top]!='(')
postfix[j++]=pop();
pop();
}
else if(isOperator(in[i])){
while(top!=-1&&stack[top]!='('&&precedence(stack[top])>=precedence(in[i]))
postfix[j++]=pop();
push(in[i]);
}
}

while(top!=-1)
postfix[j++]=pop();
postfix[j]='\0';
printf("The corresponding postfix expression is:%s",postfix);
}
int main(){
char infix[50];
printf("Enter the expression:");
scanf("%s",infix);
infixtopostfix(infix);
return 0;
}

/*
#include<stdio.h>
#include<ctype.h>
int stack[50];
int top=-1;
void push(int value){
stack[++top]=value;
}
int pop(){
if(top==-1){
printf("Error: Invalid expression");
return 0;
}
return stack[top--];
}
int evaluatePostfix(char exp[]){
int i,a,b,result;
for(i=0;exp[i]!='\0';i++){
if(isdigit(exp[i]))
push(exp[i]-'0');
else{
b=pop();
a=pop();
switch(exp[i]){
case '+':
result=a+b;
break;
case '-':
result=a-b;
break;
case '*':
result=a*b;
break;
case '/':
if(b==0){
printf("Error: Division by zero");
return 0;
}
result=a/b;
break;
default:printf("Error: Invalid Operator");return 0;
}
push(result);
}
}
return pop();
}
int main(){
char postfix[50];
int result;
printf("Enter the postfix expression:");
scanf("%s",postfix);
result=evaluatePostfix(postfix);
printf("Evaluated Result:%d",result);
return 0;
}*/