#include<stdio.h>
struct Bank{
int accno;
char name[20];
float balance;
};
void display(struct Bank b){
printf("\nAccount No:%d",b.accno);
printf("\nName:%s",b.name);
printf("\nBalance:%.2f\n",b.balance);
}
int main(){
struct Bank b[10];
int n,i,choice,acc,found;
float amount,total;
printf("Enter number of accounts:");
scanf("%d",&n);
for(i=0;i<n;i++){
printf("Enter account number:");
scanf("%d",&b[i].accno);
printf("Enter name:");
scanf("%s",b[i].name);
printf("Enter balance:");
scanf("%f",&b[i].balance);
}
do{
printf("\n1.Display Accounts");
printf("\n2.Deposit");
printf("\n3.Withdraw");
printf("\n4.Search Account");
printf("\n5.Total Balance");
printf("\n6.Exit");
printf("\nEnter choice:");
scanf("%d",&choice);
switch(choice){
case 1:
for(i=0;i<n;i++)
display(b[i]);
break;
case 2:
printf("Enter account number:");
scanf("%d",&acc);
for(i=0;i<n;i++){
if(b[i].accno==acc){
printf("Enter amount:");
scanf("%f",&amount);
b[i].balance+=amount;
printf("Deposit successful!");
}
}
break;
case 3:
printf("Enter account number:");
scanf("%d",&acc);
for(i=0;i<n;i++){
if(b[i].accno==acc){
printf("Enter amount:");
scanf("%f",&amount);
if(amount<=b[i].balance){
b[i].balance-=amount;
printf("Withdrawal successful!");
}
else
printf("Insufficient balance!");
}
}
break;
case 4:
printf("Enter account number:");
scanf("%d",&acc);
found=0;
for(i=0;i<n;i++){
if(b[i].accno==acc){
display(b[i]);
found=1;
}
}
if(found==0)
printf("Account not found!");
break;
case 5:
total=0;
for(i=0;i<n;i++)
total+=b[i].balance;
printf("Total Balance=%.2f",total);
break;
case 6:
printf("Thank you!");
break;
default:
printf("Invalid choice!");
}
}while(choice!=6);
return 0;
}
