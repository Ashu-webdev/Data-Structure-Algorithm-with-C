/* To check the validity of expression containing nested parenthesis using a stack*/
#include<stdio.h>
#include<string.h>
#define MAX 20
char stack [MAX];
int top=-1;
void PUSH(char);
char POP();
int main()
{
	 char expr[MAX],temp;
	 int i,valid=1;
	 printf("Enter the algebraic exp: ");
	 gets(expr);
	 for(i=0;i<strlen(expr);i++)
	 {
		 if (expr[i]=='(' || expr[i]=='{' || expr[i]=='[')
			 PUSH(expr[i]);
		 if (expr[i]==')' || expr[i]=='}' || expr[i]==']')
	         {
			 if(top==-1)
				 valid=0;
			 else
			 {
			    temp=POP();
		            if (temp=='(' && (expr[i]=='}' || expr[i]==']'))
			          valid=0;
		            if(temp=='[' && (expr[i]==')' || expr[i]=='}'))
				valid=0;
			    if (temp=='{' && (expr[i]==')' || expr[i]==']'))
				    valid=0;
		         }
	        }
          }
          if(top>=0)
                valid=0;
          if(valid==1)
                 printf("Valid exp");
          else
             printf("Invalid exp");
}

void PUSH(char c)
{
    top++;
    stack[top]=c;
        
}

char POP()
{
   char c;
   c=stack[top];
   top--;
   return c;
}
  
