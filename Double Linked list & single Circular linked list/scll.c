/* To implement menu driven program to implement opeartions on a single circular linked list*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
   int info;
   struct node *next;
};
void Createlist(struct node*);
void Traverse(struct node*);
void Insert_Beg(struct node*);

struct node *newstart;
int main()
{
	struct node *start;
	int ch;
	start=(struct node*)malloc(sizeof(struct node));
	if(start==NULL)
	{
		printf("\n Out of memory");
		exit(0);
	}
	while(1)
	 {
		 printf("\n 1.Creation\n 2.Traversal\n 3.Insertion at the beginning\n 4.Insertion at the end\n 5.Insertion at any location\n 6.Delete the first node\n 7.Delete the last node\n 8.Deletion from any location\n 9.Quit\n Enter your choice: ");
		 scanf("%d",&ch);
		 switch(ch)
		 {
			 case 1:Createlist(start);
				start=newstart;
				break;
			case 2:Traverse(start);
                               break;
			case 3:Insert_Beg(start);
			       break;
		 }
        }



}

void Createlist(struct node *clink)
{
	struct node *p;
	int i=1;
	char ch;
	p=clink;
	printf("Enter element for node %d ",i);
	scanf("%d",&clink->info);
	clink->next=newstart;
        newstart=clink;
	i++;
	printf("\n Press n to quit and any other key to continue ");
	scanf(" %c",&ch);
	while(ch!='n')
	{
		clink->next=(struct node*)malloc(sizeof(struct node));
		if(clink->next==NULL)
		{
			printf("\n Out of memory");
			return;
		}
		clink=clink->next;
		printf("\n Enter element for node %d ",i);
		scanf("%d",&clink->info);
		clink->next=p;
		i++;
		printf("\n Press n to quit and any other key to continue");
		scanf(" %c",&ch);
	}

}

void Traverse(struct node *clink)
{
	struct node *mlink;
	mlink=clink;
	printf("\n Elements are");
	while(mlink->next!=clink)
	{
		printf("%d\t",mlink->info);
		mlink=mlink->next;
	
	        printf("%d\t",clink->next);
	}

}

void Insert_Beg(struct node *clink)
{
	struct node *cur,*mlink;
	mlink=clink;
	cur=(struct node*)malloc(sizeof(struct node));
	if(cur==NULL)
	{
		printf("\n Out of memory");
		return;
	}
	printf("\n Enter element");
	scanf("%d",&cur->info);
        cur->next=clink;
	newstart=cur;
	while(mlink->next!=clink)
		mlink=mlink->next;
	mlink->next=cur;
}
