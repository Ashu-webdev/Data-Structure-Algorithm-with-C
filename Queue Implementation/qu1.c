/* To perform the Insert,Delete, and Traverse operations on a Queue implemented using an array*/
#include<stdio.h>
#include<stdlib.h>
#define N 10
int QUEUE [N];
int FRONT=-1,REAR=-1;
void INSERT(int);
void DELETE();
void TRAVERSE();

void INSERT(int item)
{
   if(REAR==N-1)
   {
     printf("\n Linear Queue overflow");
     return;
   }
   if(REAR<N-1)
   {
	REAR++;
        QUEUE[REAR]=item;
           if (FRONT==-1)
	     FRONT=0;
   }
}

void DELETE()
{
	int temp;
	if (FRONT==-1)
	{
		printf("\n Linear Queue Underflow");
		return;
	}
	else
	{
		temp=QUEUE[FRONT];
                if (FRONT==REAR)
		{
			FRONT=-1;
			REAR=-1;
		}
		else
			FRONT++;
	}
	printf("\n Deleted element is %d\n",temp);
}

void TRAVERSE()
{
	int i;
	if (FRONT==-1)
	{
		printf("\n Linear Queue is empty");
		return;
	}
	printf("\n Elements are");
	for(i=FRONT;i<=REAR;i++)
		printf("%d\t",QUEUE[i]);
}

int main()

{

    int choice,item;

    while (1)

    {

        printf("1.Insert element to queue \n");

        printf("2.Delete element from queue \n");

        printf("3.Display all elements of queue \n");

        printf("4.Quit \n");

        printf("Enter your choice : ");

        scanf("%d", &choice);

        switch (choice)

        {

            case 1:printf("Enter the element to insert");
		   scanf("%d",&item);

            INSERT( item );

            break;

            case 2:

            DELETE();

            break;

            case 3:

            TRAVERSE();

            break;

            case 4:

            exit(1);

            default:

            printf("Wrong choice \n");
      }
    
    }
}    
