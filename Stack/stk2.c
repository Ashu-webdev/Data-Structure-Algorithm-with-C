/* To reverse any string using stack*/
#include<stdio.h>
#include<string.h>
char STACK[20];
int top=-1;
void PUSH(char);
char POP();
int main()
{
   char str[20],ch;
   int l,i;
   printf("Enter any string: ");
   gets(str);
   l=strlen(str);
   for(i=0;i<l;i++)
   {
     PUSH(str[i]);
   }
   printf("Reversed string: ");
   for(i=0;i<l;i++)
   {    
	ch=POP();
	printf("%c",ch);
   }
}

void PUSH(char c)
{
	top++;
	STACK[top]=c;
}

char POP()
{
   char c;
   c=STACK[top];
   top--;
   return c;
}   

      
