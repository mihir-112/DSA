// Binary search tree
#include <stdio.h>
#include <stdlib.h>

struct node
{
int data;


struct node *left;
struct node *right;


};

struct node *create(int value)
{
struct node *newNode;


newNode = (struct node *)malloc(sizeof(struct node));

newNode->data = value;

newNode->left = NULL;
newNode->right = NULL;

return newNode;


}

struct node *insert(struct node *root, int value)
{
if (root == NULL)
{
return create(value);
}


if (value < root->data)
{
    root->left = insert(root->left, value);
}
else
{
    root->right = insert(root->right, value);
}

return root;


}

void inorder(struct node *root)
{
if (root != NULL)
{
inorder(root->left);


    printf("%d ", root->data);

    inorder(root->right);
}


}

void preorder(struct node *root)
{
if (root != NULL)
{
printf("%d ", root->data);


    preorder(root->left);

    preorder(root->right);
}


}

void postorder(struct node *root)
{
if (root != NULL)
{
postorder(root->left);


    postorder(root->right);

    printf("%d ", root->data);
}


}

int countLeaf(struct node *root)
{
if (root == NULL)
{
return 0;
}


if (root->left == NULL && root->right == NULL)
{
    return 1;
}

return countLeaf(root->left)
       + countLeaf(root->right);


}

int countNonLeaf(struct node *root)
{
if (root == NULL)
{
return 0;
}


if (root->left == NULL && root->right == NULL)
{
    return 0;
}

return 1 + countNonLeaf(root->left)
         + countNonLeaf(root->right);


}

void levelOrder(struct node *root)
{
struct node *queue[100];


int front = 0;
int rear = 0;

if (root == NULL)
{
    return;
}

queue[rear] = root;
rear++;

while (front < rear)
{
    struct node *temp;

    temp = queue[front];
    front++;

    printf("%d ", temp->data);

    if (temp->left != NULL)
    {
        queue[rear] = temp->left;
        rear++;
    }

    if (temp->right != NULL)
    {
        queue[rear] = temp->right;
        rear++;
    }
}


}

int main()
{
struct node *root = NULL;


int n;

printf("Enter number of elements: ");
scanf("%d", &n);

for (int i = 0; i < n; i++)
{
    int value;

    scanf("%d", &value);

    root = insert(root, value);
}

printf("\nInorder traversal:\n");
inorder(root);

printf("\n\nPreorder traversal:\n");
preorder(root);

printf("\n\nPostorder traversal:\n");
postorder(root);

printf("\n\nLevel order traversal:\n");
levelOrder(root);

printf("\n\nLeaf nodes = %d\n",
       countLeaf(root));

printf("Non leaf nodes = %d\n",
       countNonLeaf(root));

return 0;


}
