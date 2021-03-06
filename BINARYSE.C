#include<stdlib.h>
#include<conio.h>
struct node
{
struct node *left;
int data;
struct node *right;
};
struct node *ROOT=NULL;
void insert();
void delet(int);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);
void search();
void main()
{
int opt,x;
do
{
printf("\nMenu\n 1.insert\n 2.delete\n 3.inorder\n 4.preorder\n 5.postorder\n 6.search\n 7.exit\n");
printf("Enter your option\n");
scanf("%d",&opt);
switch(opt)
{
case 1:
insert();
break;
case 2:
printf("\nEnter the data to delete:");
scanf("%d",&x);
delet(x);
break;
case 3:
inorder(ROOT);
break;
case 4:
preorder(ROOT);
break;
case 5:
postorder(ROOT);
break;
case 6:
search();
break;
}
}
while(opt!=7);
}
void insert()
{
struct node *ptr,*ne,*ptr1;
int x;
ne=(struct node *)malloc(sizeof(struct node));
if(ne==NULL)
{
printf("\ninsufficient memory");
return;
}
printf("\nEnter the data to insert:");
scanf("%d",&x);
ne->right=ne->left=NULL;
ne->data=x;
if(ROOT==NULL)
{
ROOT=ne;
return;
}
ptr=ROOT;
while(ptr!=NULL)
{
if(x==ptr->data)
{
printf("\nitem present in the tree");
break;
}
if(x>ptr->data)
{
ptr1=ptr;
ptr=ptr->right;
}
else
{
ptr1=ptr;
ptr=ptr->left;
}
}
if(ptr==NULL)
{
if(x>ptr1->data)
ptr1->right=ne;
else
ptr1->left=ne;
}
}
void search()
{
int x;
struct node *ptr=ROOT;
printf("\nEnter the data to search:");
scanf("%d",&x);
while(ptr!=NULL)
{
if(ptr->data==x)
{
printf("\ndata present");
break;
}
if(x>ptr->data)
ptr=ptr->right;
else
ptr=ptr->left;
}
if(ptr==NULL)
printf("\ndata not present");
}
void inorder(struct node *p)
{
if(p!=NULL)
{
inorder(p->left);
printf("%d",p->data);
inorder(p->right);
}
}
void preorder(struct node *p)
{
if(p!=NULL)
{
printf("%d",p->data);
preorder(p->left);
preorder(p->right);
}
}
void postorder(struct node *p)
{
if(p!=NULL)
{
postorder(p->left);
postorder(p->right);
printf("%d",p->data);
}
}
void delet(int x)
{
struct node *parent,*p,*ptr;
int dat;
if(ROOT==NULL)
{
printf("\nTree is empty");
return;
}
parent=NULL;
ptr=ROOT;
while(ptr!=NULL)
{
if(ptr->data==x)
break;
parent=ptr;
if(x>ptr->data)
ptr=ptr->right;
else
ptr=ptr->left;
}
if(ptr==NULL)
{
printf("item not present");
return;
}
if(ptr->right==NULL && ptr->left==NULL)
{
if(parent==NULL)
ROOT=NULL;
else if(parent->right==ptr)
parent->right=NULL;
else
parent->left=NULL;
printf("element deleted");
free(ptr);
return;
}
if(ptr->right!=NULL && ptr->left!=NULL)
{
p=ptr->right;
while(p->left!=NULL)
{
p=p->left;
}
dat=p->data;
delet(p->data);
ptr->data=dat;
return;
}
if(parent==NULL)
{
if(ptr->right==NULL)
ROOT=ptr->left;
else
ROOT=ptr->right;
}
else
{
if(parent->right==ptr)
{
if(ptr->right==NULL)
parent->right=ptr->left;
else
parent->right=ptr->right;
}
else
{
if(ptr->left==NULL)
parent->right=ptr->left;
else
parent->right=ptr->right;
}
else
{
if(ptr->left==NULL)
parent->left=ptr->right;
else
parent->left=ptr->left;
}
}
printf("\nelement deleted");
free(ptr);
return;
}
