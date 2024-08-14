/* Menu driven program to perform operations on bst*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	struct node *left;
	int info;
	struct node *right;
};
typedef struct node *bstnode;
bstnode insert(bstnode,int);
bstnode delete(bstnode,int);
bstnode findmin(bstnode);
bstnode search(bstnode,int);
bstnode findmax(bstnode);
void preorder(bstnode);
void inorder(bstnode);
void postorder(bstnode);
int main()
{
	bstnode t=NULL,p;
	int  x,ch;
	while(ch!=9)
	{
		printf("\n1.Insert element in bst\n 2.Delete\n 3.Search\n 4.Find Max element\n 5.Find Minimun element \n 6.Preorder traversal\n 7.Inorder traversal\n 8. Postorder traversal\n 9.Quit\n Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:printf("\n Enter element: ");
			       scanf("%d",&x);
			       t=insert(t,x);
			       break;
			case 2:printf("\n Enter the element to be deleted: ");
			       scanf("%d",&x);
			       t=delete(t,x);
			       break;
			case 5:p=findmin(t);
			       printf("\n Smallest element is %d",p->info);
			       break;
			case 3:printf("\n Enter the element to be searched: ");
			       scanf("%d",&x);
			       t=search(t,x);
			       printf("%d is found",x);
			       break;
			 case 4:p=findmax(t);
				printf("\n Largest element is %d",p->info);
				break;
			case 6:preorder(t);
			       break;
			case 7:inorder(t);
			       break;
			case 8:postorder(t);
			       break;
			case 9:break;


	        }
	}
}

bstnode insert(bstnode t,int x)
{
	if(t==NULL)
	{
		t=(bstnode)malloc(sizeof(struct node));
	        if(t==NULL)
	        {  
		   printf("\n Out of memory");
	           exit(0);
	        }   
	        else
	        {
		   t->info=x;
		   t->left=NULL;
		   t->right=NULL;
	        }
	}
	else
	{
		if(x<t->info)
			t->left=insert(t->left,x);
		else
		{
			if(x>t->info)
				t->right=insert(t->right,x);
		}
	}
	return t;
}

	
bstnode delete(bstnode t,int x)
{
	bstnode temp;
	if(t==NULL)
	    printf("\n %d is not found",x);
	else
	{
		if(x<t->info)
			t->left=delete(t->left,x);
		else
		{
			if(x>t->info)
				t->right=delete(t->right,x);
			else
			{
				if(t->left && t->right)
				{
					temp=findmin(t->right);
					t->info=temp->info;
					t->right=delete(t->right,t->info);
				}
				else
				{
					temp=t;
					if(t->left==NULL)
						t=t->right;
					else
					{
						if(t->right==NULL)
							t=t->left;
					}
					free(temp);
				}
			}
		}
	}
	return t;
}

bstnode findmin(bstnode t)
{
	if(t==NULL)
		return NULL;
	else
	{
		if(t->left==NULL)
			return t;
		else 
			return findmin(t->left);
	}
}

bstnode search(bstnode t,int x)
{
	if(t==NULL)
		return NULL;
        else 
	{
		if(x<t->info)
			return search(t->left,x);
		else
		{
			if(x>t->info)
				return search(t->right,x);
		        else
				return t;
	        }
	}
}

bstnode findmax(bstnode t)
{
	if(t->right!=NULL)
		t=t->right;
	return t;
}

void preorder(bstnode t)
{
	if(t!=NULL)
	{
		printf("%d\t",t->info);
		preorder(t->left);
		preorder(t->right);
	}
}

void inorder(bstnode t)
{
	if(t!=NULL)
	{
		inorder(t->left);
		printf("%d\t",t->info);
		inorder(t->right);
	}
}

void postorder(bstnode t)
{
	if(t!=NULL)
	{
		postorder(t->left);
		postorder(t->right);
		printf("%d\t",t->info);
	}
}
