/* To convert triplet to sparse matrix*/
#include<stdio.h>
int main()
{
   int trip[10][3],sparse[10][3],i,j,nz,k,m;
   printf("Enter the no of non-zero elements of sparse matrix: ");
   scanf("%d",&nz);
   printf("Enter the triplet matrix: \n");
   for(i=0;i<=nz;i++)
   {
      	   for(j=0;j<3;j++)
	   	   scanf("%d",&trip[i][j]);
   }
   printf("The triplet matrix is\n");
   for(i=0;i<=nz;i++)
   {
      	   for(j=0;j<3;j++)
	   	   printf("%d\t",trip[i][j]);
      	   printf("\n");
   }
   k=trip[0][0];
   m=trip[0][1];
   for(i=0;i<k;i++)
   {
      	   for(j=0;j<m;j++)
	   	   sparse[i][j]=0;
   }
   printf("The sparse matrix is\n");
   for(i=1;i<=nz;i++)
   {
	   		   sparse[trip[i][0]][trip[i][1]]=trip[i][2];
      	   
   }
   for(i=0;i<k;i++)
   {
     	   for(j=0;j<m;j++)
	   	   printf("%d\t",sparse[i][j]);
     	   printf("\n");
   }
}   


