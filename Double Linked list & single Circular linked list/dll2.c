/* To insert a node after a specific node in a double linked list*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct dlink
{
    int info;
    struct dlink *prev;
    struct dlink *next;
};
void CreateList(struct dlink*);
void Insert(struct dlink*);
void Display(struct dlink*);

void main()
{
	struct dlink *node;
	char ch='1';
	node=(struct dlink*)malloc(sizeof(struct dlink));
	if(node==NULL)
	{
		printf("\n Out of memory space");
		exit(0);
	}
	CreateList(node);
	while(ch!='3')
	{
		printf("1.Insert after a given node\n 2.Display\n 3.Quit\n Enter your choice:");
		scanf(" %c",&ch);
		switch(ch)
		{
			case '1':Insert(node);
				 break;
		        case '2':Display(node);
				 break;
			case '3':break;
			default:printf("Wrong choice!");
		}
	

	}
}

void CreateList(struct dlink *node)
{
	struct dlink *curr;
	char ch;
	int i=1;
	printf("\nEnter the value for %d node:",i);
	scanf("%d",&node->info);
	node->prev=NULL;
	node->next=NULL;
	i++;
	printf("\n Press 'n' to quit any other key to continue: ");
	scanf(" %c",&ch);
	while(ch!='n')
	{
		curr=(struct dlink*)malloc(sizeof(struct dlink));
		if(curr==NULL)
	        {
			printf("\n Out of memory space");
			exit(0);
		}
		node->next=curr;
		curr->prev=node;
		node=node->next;
		printf("\n Enter the value for %d node:",i);
		scanf("%d",&node->info);
		node->next=NULL;
		printf("\n Press 'n' to quit any other key to continue:");
		scanf(" %c",&ch);
		i++;
	}
}

void Insert(struct dlink *node)
{
	struct dlink *curr;
	int x;
	printf("\n Enter the node after which node will be inserted:");
	scanf("%d",&x);
	while(node!=NULL)
	{
		if(x==node->info)break;
		    node=node->next;
        }
	if(node==NULL)
	{
		printf("\n%d is not in the list\n",x);
		return;
	}
	curr=(struct dlink*)malloc(sizeof(struct dlink));
	if(curr==NULL)
	{
		printf("\n Out of memory space");
		exit(0);
	}
	printf("\n Enter the value to be inserted:");
	scanf("%d",&curr->info);
	curr->next=node->next;
	node->next->prev=curr;
	node->next=curr;
	curr->prev=node;
}
		        
void Display(struct dlink *node)
{
	struct dlink *temp;
	printf("\n Values of nodes in the list\n");
	while(node!=NULL)
	{
		temp=node;
		printf("%d\t",node->info);
		node=node->next;
	}
}
