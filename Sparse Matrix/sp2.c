/* Triplet representation of sparse matrix*/
#include<stdio.h>
int main()
{
   int sparse[10][10],triplet[10][3],i,j,r,c,k=1,m=0;
   printf("Enter dimension of matrix: ");
   scanf("%d%d",&r,&c);
   printf("Enter matrix elements: ");
   for(i=0;i<r;i++)
   {
     for(j=0;j<c;j++)
	     scanf("%d",&sparse[i][j]);
   }
   printf("Matrix is ");
   for(i=0;i<r;i++)
   {
     for(j=0;j<c;j++)
	  printf("%d",sparse[i][j]);
     printf("\n");
   }
   for(i=0;i<r;i++)
   {
     for(j=0;j<c;j++)
     {
       if(sparse[i][j]!=0)
       {
         triplet[k][0]=i;
         triplet[k][1]=j;
         triplet[k][2]=sparse[i][j];
         k++;
         m++;
       }
     }
   }
   triplet[0][0]=r;
   triplet[0][1]=c;
   triplet[0][2]=m;
   printf("\n The triplet matrix is \n");
   for(i=0;i<k;i++)
   {
	 for(j=0;j<3;j++)
	 {
           
             printf("%d\t",triplet[i][j]);
         }   
         printf("\n");
        
   }
}   
		     
