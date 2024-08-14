//Polynomial display
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
        int cof;
	int exp;
        struct node *next;

};
void createlist(struct node*);
void traverse(struct node*);
int main()
{
        struct node *start;
        start=(struct node *)malloc(sizeof(struct node));
        if(start==NULL)
        {
                printf("\nOut of memory");
                exit(0);
        }
	createlist(start);
	traverse(start);
}
void createlist(struct node *link)
{
        int i=1;
        char ch;
        printf("\nEnter the coefficient and expression for term  %d\n",i);
        scanf("%d%d", &link->cof,&link->exp);
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
                printf("\nEnter coefficient and expression for node %d\n", i);
                scanf("%d%d", &link->cof,&link->exp);
                link->next==NULL;
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
                printf("%dx%d\t", link->cof,link->exp);
                link=link->next;
		while(link)
		{
			printf("+ %dx%d ", link->cof,link->exp);
			link=link->next;
		}
		printf("\n");
        }
}

