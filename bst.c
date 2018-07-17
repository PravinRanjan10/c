#include<stdio.h>
#include<malloc.h>
struct node
 {
 int data;
 struct node* left;
 struct node* right;
};

struct node* insertnode(int data, struct node* root)
{
 if (!root)
    {
     struct node* newnode;
     newnode = (struct node*) malloc (sizeof(struct node));
     newnode->data = data;
     newnode->left = newnode->right = NULL;
     return newnode;
    }

else
{
 if (data < root->data)
     root->left = insertnode(data, root->left);
 else
     root->right = insertnode(data, root->right);
}
return root;
}

void inorder(struct node* root)
 {
 if (root != NULL)
 {
  inorder(root->left);
  printf("%d",root->data);
  inorder(root->right);
 }
}
     

int main()
{
int data, n, i;
printf("Enter no of dtata to insert: ");
scanf("%d",&n);

struct node *root;
root = NULL;

for(i = 0; i < n; i++)
{
 scanf("%d",&data);
 root = insertnode(data, root);
}
printf("Inorder is: ");
inorder(root);
return 0;
}
