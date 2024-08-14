//Menu driven programme for linked list
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
	int info;
	struct node *next;

};
struct node *newstart;
void createlist(struct node*);
void traverse(struct node*);
void insert_beg(struct node*);
void insert_end(struct node*);
void insert_loc(struct node*);
void delete_beg(struct node*);
void delete_end(struct node*);
void delete_loc(struct node*);
void search(struct node*,int);
void sort(struct node*);
void reverse(struct node*);
void merge(struct node*,struct node*,struct node*);
int count(struct node*);
int main()
{
	struct node *start,*list2,*merged_list;
	int ch,key;
	start=(struct node *)malloc(sizeof(struct node));
    if(start==NULL)
	{
		printf("\nOut of memory");
		exit(0);
	}
	while(1)
	{
		printf("\n1.CREATE\n2.TRAVERSE\n3.INSERTION AT THE BEGINING\n4.INSERTION AT THE END\n5.INSERTION AT ANY LOCATION\n6.DELETE THE FIRST NODE\n7.DELETE THE LAST NODE\n8.DELETE FROM ANY LOCATION\n9.SORTING\n10.SEARCHING\n11.REVERSING\n12.MERGING\n13.QUIT\nEnter your choice\n");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: createlist(start);
				    break;
			case 2: traverse(start);
				    break;
			case 3: insert_beg(start);
				    start=newstart;
				    break;
			case 4: insert_end(start);
				    break;
			case 5: newstart=start;
				    insert_loc(start);
				    start=newstart;
                    break;
			case 6: delete_beg(start);
				    start=newstart;
				    break;
			case 7: newstart=start;
                    delete_end(start);
                    start=newstart;
                    break;
			case 8: newstart=start;
                    delete_loc(start);
                    start=newstart;
                    break;
			case 9: sort(start);
                    break;
			case 10: printf("Enter element to be searched\n");
                     scanf("%d", &key);
                     search(start,key);
                     break;
			case 11: newstart=start;
                     reverse(start);
                     start=newstart;
                     break;
			case 12: list2 = (struct node *)malloc(sizeof(struct node));
					 if (list2 == NULL)
					 {
						printf("\nOut of memory");
						exit(0);
					 }
			         createlist(list2);
					 merged_list = (struct node *)malloc(sizeof(struct node));
					 if (merged_list == NULL) 
				     {
						printf("\nOut of memory");
						exit(0);
					 }
					 merge(start, list2, merged_list);
					 traverse(merged_list);
					 break;
			case 13: exit(0);
			default: printf("Wrong Choice\n");
     	}
	}
}
void createlist(struct node *link)
{
	int i=1;
	char ch;
	printf("\nEnter the elements for node %d\n",i);
	scanf("%d", &link->info);
	link->next=NULL;
	i++;
	printf("Press n to exit and any other key to continue:- ");
	scanf(" %c", &ch);
	while(ch!='n')
	{
		link->next=(struct node*)malloc(sizeof(struct node));
		if(link->next==NULL)
		{
			printf("Out of memory");
			return;
		}
		link=link->next;
		printf("\nEnter elements for node %d\n", i);
		scanf("%d", &link->info);
		link->next=NULL;
		i++;
		printf("Press n to exit and any other key to continue:- ");
        scanf(" %c", &ch);
	}
}
void traverse(struct node *link)
{
	printf("\nElements are\n");
    while(link!=NULL)
	{
		printf("%d\t", link->info);
		link=link->next;
	}
}
void insert_beg(struct node *link)
{
	struct node *cur;
	cur=(struct node *)malloc(sizeof(struct node));
	if(cur==NULL)
	{
		printf("\nOut of memory");
		return;
	}
	printf("\nEnter element for the new node\n");
	scanf("%d", &cur->info);
	cur->next=link;
	newstart=cur;
}
void insert_end(struct node *link)
{
	struct node *cur;
	cur=(struct node *)malloc(sizeof(struct node));
    if(cur==NULL)
    {
        printf("\nOut of memory");
        return;
    }
    printf("\nEnter element for the new node\n");
    scanf("%d", &cur->info);
	cur->next=NULL;
	while(link->next!=NULL)
		link=link->next;
	link->next=cur;
}
void insert_loc(struct node *link)
{
	int i=1,loc,c=0;
	struct node *cur,*prev;
	printf("Enter elements is to be inserted at which location\n");
    scanf("%d", &loc);
	c=count(link);
	if(loc>c)
	{
		printf("Invalid location");
		return;
	}
    cur=(struct node *)malloc(sizeof(struct node));
    if(cur==NULL)
    {
        printf("\nOut of memory");
        return;
    }
	printf("\nEnter element for the new node\n");
    scanf("%d", &cur->info);
	while(i<loc)
	{
		prev=link;
		link=link->next;
		i++;
	}
	if(loc==1)
	{
		cur->next=link;
		newstart=cur;
	}
	else
	{
		prev->next=cur;
		cur->next=link;
	}
}
void delete_beg(struct node *link)
{
	newstart=link->next;
	free(link);
}
void delete_end(struct node *link)
{
	struct node *prev;
	if(link->next==NULL)
	{
		free(link);
		newstart=NULL;
		return;
	}
	while(link->next!=NULL)
	{
		prev=link;
		link=link->next;
	}
	prev->next=NULL;
	free(link);
}
void delete_loc(struct node *link)
{
    int i=1,loc,c=0;
    struct node *prev;
    printf("Enter location\n");
    scanf("%d", &loc);
    c=count(link);
    if(loc>c)
    {
        printf("Invalid location");
		return;
    }
	while(i<loc)
    {
        prev=link;
        link=link->next;
        i++;
    }
    if(loc==1)
    {
        newstart=link->next;
		free(link);
	}
    else
    {
        prev->next=link->next;
        free(link);
    }
}
void search(struct node *link,int key)
{
	int i=1;
	while(link!=NULL)
	{
		if(link->info==key)
		{
			printf("%d is found at node %d\n", key,i);
			return;
		}
		link=link->next;
		i++;
	}
	printf("%d is not found\n", key);
}
void sort(struct node *link)
{
	struct node *p,*q;
	int temp;
	for(p=link;p->next!=NULL;p=p->next)
	{
		for(q=p->next;q!=NULL;q=q->next)
		{
			if(p->info>q->info)
			{
				temp=p->info;
				p->info=q->info;
				q->info=temp;
			}
		}
	}
}
void reverse(struct node *link)
{
	struct node *ptr,*cur;
	if(link->next==NULL)
		return;
	ptr=link->next;
	link->next=NULL;
	while(ptr->next!=NULL)
	{
		cur=ptr->next;
		ptr->next=link;
		link=ptr;
		ptr=cur;
	}
	ptr->next=link;
	newstart=ptr;
}
void merge(struct node *link1,struct node *link2,struct node *link3)
{
	link3->info=link1->info;
	link3->next=NULL;
	link1=link1->next;
	while(link1!=NULL)
	{
		link3->next=(struct node *)malloc(sizeof(struct node));
		if(link3->next==NULL)
		{
			printf("\nOut of memory");
			exit(0);
		}
		link3=link3->next;
		link3->info=link1->info;
		link3->next=NULL;
		link1=link1->next;
	}
	while(link2!=NULL)
    {
        link3->next=(struct node *)malloc(sizeof(struct node));
        if(link3->next==NULL)
        {
            printf("\nOut of memory");
			exit(0);
        }
        link3=link3->next;
        link3->info=link2->info;
        link3->next=NULL;
        link2=link2->next;
    }
}
int count(struct node *link)
{
	int i=0;
	while(link!=NULL)
	{
		i++;
		link=link->next;
	}
	return i;
}