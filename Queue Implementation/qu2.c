/* To perform insert,delete and traverse operations on a circular queue implemented using on array*/
#include<stdio.h>
#include<stdlib.h>
#define N 10
int CQ[N];
int FRONT=-1,REAR=-1;
void CQINSERT(int);
void CQDELETE();
void CQTRAVERSE();

void CQINSERT(int item)
{
	if(FRONT==0 && REAR==N-1 || FRONT==REAR+1)
	{
		printf("CQ overflow");
	        return;
	}
	if (REAR==-1)
	{	
	       FRONT=0;
	       REAR=0;
	}       
        else
	{
	     if (REAR==N-1)
		     REAR=0;
	     else
		     REAR=REAR+1;
	}    
	CQ[REAR]=item;
}

void CQDELETE()
{
	int TEMP;
	if(FRONT==-1)
	{

		printf("CQ is UNDERFLOW");
	        return;
	}	
	else
	{
		TEMP=CQ[FRONT];

          if(FRONT==REAR)
          {		  
		FRONT=-1;
	        REAR=-1;
	  }	
	  else
          {
		if (FRONT==N-1)
			FRONT=0;
	        else
			 FRONT=FRONT+1;
          }
	  printf("Deleted element is %d\n",TEMP);
        }
}	

void CQTRAVERSE()
{
	 int i;
	 if(FRONT==-1)
	 {
		 printf("\n CQ is empty");
		 return;
 	 }
         if(FRONT>REAR)
	 {
		 for(i=FRONT;i<N;i++)
			 printf("%d\t",CQ[i]);
		 for(i=0;i<=REAR;i++)
			 printf("%d\t",CQ[i]);
         }
	 else
       	{
		for(i=FRONT;i<=REAR;i++)
			printf("%d\t",CQ[i]);
	}
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

	    case 1:printf("Enter the element to insert: ");
		        scanf("%d",&item);

                       CQINSERT( item );

                      break;

            case 2:

            CQDELETE();

            break;

            case 3:

            CQTRAVERSE();

            break;

            case 4:

            exit(1);

            default:

            printf("Wrong choice \n");
      }

    }
}
