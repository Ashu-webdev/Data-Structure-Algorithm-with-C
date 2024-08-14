/* 
    Program to perform the PUSH,POP and TRAVERSE operations on a stack implemented by using an array
   Date:1.03.2024
*/
#include<stdio.h>
#define MAXSTK 20
int STACK[MAXSTK];
int top=-1;
void PUSH(int);
int POP();
void TRAVERSE();
int main()
{
   int ch=1,item;
   while(ch!=4)
   {
     printf("\n 1.PUSH\n 2.POP\n 3.TRAVERSE \n 4.QUIT \n Enter your choice: ");
     scanf("%d",&ch);
     switch(ch)
     {
	     case 1:printf("Enter element to be pushed: ");
	        scanf("%d",&item);
	        PUSH(item);
	        break;
	case 2:POP();
               break;
        case 3:TRAVERSE();
               break;
        case 4:break;
        default:printf("Wrong choice");
     }
   }
}

void PUSH(int item)
{
	if(top==MAXSTK-1)
	{
		printf("STACK OVERFLOW");
		return;
        }
	else
	{
		top=top+1;
		STACK[top]=item;
	}
}

int POP(int temp)
{
	
        if(top==-1)
	{
		printf("STACK UNDERFLOW");
		return 0;
        }
	temp=STACK[top];
	top=top-1;
	printf("Deleted element is %d",temp);
        return temp;
}

void TRAVERSE()
{
  int i;
  if(top==-1)
  {
	printf("STACK is empty");
        return;
  }
  printf("Elements are:");
  for(i=top;i>=0;i--)
	printf("%d\t",STACK[i]);
}  

