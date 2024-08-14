/* Menu driven program to implement following operations on Double linked list
   A.Creation*/
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	struct  node *prev;
	int info;
        struct node *next;
};
struct node *newstart;
void Createlist(struct node*);
void Traverse(struct node*);
void InsertionatBegin(struct node*);
void Insert_End(struct node*);
void Insert_loc(struct node*);
void Delete_Begin(struct node*);
void Delete_End(struct node*);
void Delete_loc(struct node*);
int main()
{
	
	 struct node *start;
	 int  ch;
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
			case 3:InsertionatBegin(start);
			       
			       start=newstart;
			       break;
			 case 4:Insert_End(start);
				break;
			 case 5:
				Insert_loc(start);
				start=newstart;
				break;
			case 6:Delete_Begin(start);
			       start=newstart;
			       break;
			case 7:Delete_End(start);
			       break;
			case 8:Delete_loc(start);
			       break;



			case 9:exit(0);


		
			default:printf("Wrong choice");
		}
	 }

}

void Createlist(struct node *dlink)
{
	struct node *cur;
	int i=1;
	char ch;
	printf("\n Enter element for node %d ",i);
	scanf("%d",&dlink->info);
	dlink->prev=NULL;
	dlink->next=NULL;
	i++;
	newstart=dlink;
	printf("Press n quit and any other key to continue");
	scanf(" %c",&ch);
	while(ch!='n')
	{
		cur=(struct node *)malloc(sizeof(struct node));
		if(cur==NULL)
		{
			printf("\n Out of memory");
			return;
		}
		printf("\n Enter element for node %d",i);
		scanf("%d",&cur->info);
		dlink->next=cur;
		cur->prev=dlink;
		dlink=dlink->next;
		dlink->next=NULL;
		i++;
		printf("Press n to quit and any other key to continue");
	        scanf(" %c",&ch);
	}
}

void Traverse(struct node *dlink)
{
        struct node *cur;
	printf("\n Elements are ");
	cur=dlink;
	while(cur!=NULL)
	{
	      
		printf("%d\t",cur->info);
		cur=cur->next;
	}
}

void InsertionatBegin(struct node *dlink)
{
	struct node *cur;
	cur=(struct node*)malloc(sizeof(struct node));
	if(cur==NULL)
	{
		printf("\n Out of memory");
		return;
	}
	printf("\n Enter element for the new node");
	scanf("%d",&cur->info);
	cur->next=dlink;
	dlink->prev=cur;
	cur->prev=NULL;
	newstart=cur;
}

void Insert_End(struct node*dlink)
{
	struct node*cur;
	cur=(struct node*)malloc(sizeof(struct node));
	if (cur==NULL)
	{
		printf("\n Out of memopry");
		return;
	}
	printf("\n Enter element for the new node");
	scanf("%d",&cur->info);
	while(dlink->next!=NULL)
		dlink=dlink->next;
	        dlink->next=cur;
		cur->prev=dlink;
		cur->next=NULL;

}

int count(struct node *dlink)
{
	int i=0;
	while(dlink!=NULL)
	{
		i++;
		dlink=dlink->next;
	}
	return i;
}


void Insert_loc(struct node* dlink)
{
	struct node *cur;
	int loc,c,i=1;
	printf("\n Enter location:");
	scanf("%d",&loc);
	c=count(dlink);
	if(loc>c)
	{
		printf("\n Invalid location");
		return;
	}
	cur=(struct node*)malloc(sizeof(struct node));
	if(cur==NULL)
        {
	  printf("Out of memory");
	  return;
	}
	printf("\n Enter element");
	scanf("%d",&cur->info);
	while(i<loc)
        {
	  dlink=dlink->next;
	  i++;
        }
	if(loc==1)
	{
	 cur->next=dlink;
	 dlink->prev=cur;
	 cur->prev=NULL;
	 newstart=cur;
	}
	else
	{
		dlink->prev->next=cur;
		cur->prev=dlink->prev;
		cur->next=dlink;
		dlink->prev=cur;
	}

}

void Delete_Begin(struct node *dlink)
{
	if(dlink->next==NULL)
	{
		newstart=NULL;
		free(dlink);
	}
	else
	{
		newstart=dlink->next;
		newstart->prev=NULL;
		free(dlink);
	}
}

void Delete_End(struct node *dlink)
{
        struct node*temp;
	if(dlink->next==NULL)
	{
		 newstart=NULL;
		 free(dlink);
		 return;
	}
	while(dlink->next!=NULL)
	{
		dlink=dlink->next;
		temp=dlink->prev;
		temp->next=NULL;
		free(dlink);
	}

}

void Delete_loc(struct node *dlink)
{
	struct node *temp;
        int loc,c,i=1;
        printf("\n Enter location:");
        scanf("%d",&loc);
        c=count(dlink);
        if(loc>c)
        {
                printf("\n Invalid location");
                return;
        }
       
     
        while(i<loc)
        {
          dlink=dlink->next;
          i++;
        }
        if(loc==1)
        {
	
	  if(dlink->next==NULL)
          {
        
            newstart=NULL;
	    free(dlink);
          }
          else
          {
                
                newstart=dlink->next;
                newstart->prev=NULL;
                free(dlink);
          }
	}
	else
	{  
	    if(dlink->next==NULL)
            {
		    temp=dlink->prev;
		    temp->next=NULL;
		    free(dlink);
            }
	    else
            {
		    temp=dlink->prev;
		    temp->next=dlink->next;
		    dlink->next->prev=temp;
		    free(dlink);
             }
	}

}
        

