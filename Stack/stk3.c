/* To evaluate arithmetic expression written in postfix notation using stack*/
#include<stdio.h>
void sum();
void diff();
void mul();
void div();
void power();
int stack[50],top=-1;
int main()
{
   char st[30];
   int i;
   printf("Enter the postfix notation: ");
   scanf("%[^\n]s",st);
   for(i=0;st[i]!='\0';i++)
   {
	 if (st[i]!=' ')
         {
		 switch(st[i])
		 {
			 case'+':sum();
				 break;
		         case'-':diff();
				 break;
			 case'*':mul();
				 break;
			 case'/':div();
				 break;
			 case'^':power();
				 break;
			 default:top++;
				 stack[top]=st[i]-48;
		 }
	 }

   }
   printf("The result is %d\n",stack[top]);
}

void sum()
{
	int res,op1,op2;
	op1=stack[top];
	top--;
	op2=stack[top];
	top--;
	res=op2+op1;
	top++;
	stack[top]=res;
}

void diff()
{
  int res,op1,op2;
  op1=stack[top];
  top--;
  op2=stack[top];
  top--;
  res=op2-op1;
  top++;
  stack[top]=res;
}

void mul()
{
  int res,op1,op2;
  op1=stack[top];
  top--;
  op2=stack[top];
  top--;
  res=op2*op1;
  top++;
  stack[top]=res;
}  

void div()
{
  int res,op1,op2;
  op1=stack[top];
  top--;
  op2=stack[top];
  top--;
  res=op2/op1;
  top++;
  stack[top]=res;
}

void power()
{
  int res=1,op2,op1,i;
  op1=stack[top];
  top--;
  op2=stack[top];
  top--;
  for(i=0;i<op1;i++)
  {
	 res=res*op2;
  }
  top++;
  stack[top]=res;
}  
