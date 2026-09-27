#include<stdio.h>
#include<stdlib.h>
struct node{
int data;
struct node *next;
};
typedef struct node NODE;
NODE* insertfront(NODE *start,int n){
NODE *newnode;
newnode=(NODE*)malloc(sizeof(NODE));
newnode->data=n;
newnode->next=start;
return newnode;
}
NODE* insertposition(NODE *start,int n,int position){
NODE *newnode,*temp;
int i;
newnode=(NODE*)malloc(sizeof(NODE));
newnode->data=n;
if(position==1){
newnode->next=start;
return newnode;
}
temp=start;
for(i=1;i<position-1&&temp!=NULL;i++)
temp=temp->next;
if(temp==NULL){
printf("Invalid position\n");
free(newnode);
return start;
}
newnode->next=temp->next;
temp->next=newnode;
return start;
}
NODE* deletekey(NODE *start,int key){
NODE *temp,*ptr;
if(start==NULL){
printf("List Empty\n");
return start;
}
if(start->data==key){
ptr=start;
start=start->next;
free(ptr);
printf("Item deleted:%d\n",key);
return start;
}
ptr=start;
while(ptr->next!=NULL&&ptr->next->data!=key)
ptr=ptr->next;
if(ptr->next==NULL)
printf("Invalid key\n");
else{
temp=ptr->next;
ptr->next=temp->next;
free(temp);
printf("Item deleted:%d\n",key);
}
return start;
}
NODE* searchkey(NODE *start,int key){
NODE *ptr=start;
while(ptr!=NULL){
if(ptr->data==key){
printf("Key %d found\n",key);
return start;
}
ptr=ptr->next;
}
printf("Invalid key\n");
return start;
}
NODE* reverse(NODE *start){
NODE *prev=NULL,*current=start,*next;
while(current!=NULL){
next=current->next;
current->next=prev;
prev=current;
current=next;
}
return prev;
}
void display(NODE *start){
NODE *ptr=start;
if(start==NULL){
printf("List is empty\n");
return;
}
printf("The list data are\n");
while(ptr!=NULL){
printf("%d\n",ptr->data);
ptr=ptr->next;
}
}
int main(){
NODE *start=NULL;
int choice,num,key,position;
while(1){
printf("\n1.Insert at front");
printf("\n2.Insert at position");
printf("\n3.Delete a node");
printf("\n4.Search a key");
printf("\n5.Reverse");
printf("\n6.Display");
printf("\n7.Stop");
printf("\nEnter choice:");
scanf("%d",&choice);
switch(choice){
case 1:
printf("Enter data:");
scanf("%d",&num);
start=insertfront(start,num);
break;
case 2:
printf("Enter data:");
scanf("%d",&num);
printf("Enter position:");
scanf("%d",&position);
start=insertposition(start,num,position);
break;
case 3:
printf("Enter key:");
scanf("%d",&key);
start=deletekey(start,key);
break;
case 4:
printf("Enter key:");
scanf("%d",&key);
searchkey(start,key);
break;
case 5:
start=reverse(start);
printf("List reversed\n");
break;
case 6:
display(start);
break;
case 7:
exit(0);
default:
printf("Invalid choice");
}
}
return 0;
}
