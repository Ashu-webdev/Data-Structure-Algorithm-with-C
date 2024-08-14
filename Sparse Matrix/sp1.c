/* Whether a given matrix is sparse or not */
#include<stdio.h>
int main()
{
   int a[5][5],z,nz,i,j,r,c;
   printf("Enter size of matrix: ");
   scanf("%d%d",&r,&c);
   printf("Enter matrix elements: ");
   for(i=0;i<r;i++)
   { 
     for(j=0;j<c;j++)
       scanf("%d",&a[i][j]);
   }   
   printf("Entered Matrix is\n");
   for(i=0;i<r;i++)
   {
     for(j=0;j<c;j++)
      printf("%d\t",a[i][j]);
     printf("\n");
   }
   for(i=0;i<r;i++)
   {
     for(j=0;j<c;j++)
     {
        if(a[i][j]==0)
           z++;
        else 
	   nz++;
     }
   }
   if(z>nz)
	printf("\nSparse matrix\n");
   else
	printf("\nNot a sparse matrix\n");
}   
