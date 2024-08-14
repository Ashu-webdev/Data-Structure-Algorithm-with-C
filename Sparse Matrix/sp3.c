/*To find transpose of triplet matrix*/
#include<stdio.h>
void Findtranspose(int [10][3],int [10][3]);
int main()
{
	int mat[5][5],Triplet[10][3],Transpose[10][3],i;
	printf("Enter total no of rows,cols and non-zero elements ");
	scanf("%d%d%d",&mat[i][0],&mat[i][1],&mat[i][2]);
	printf("Elements of matrix are");
	for(i=0;i<=mat[0][2];i++)
		printf("%d\t%d\t%d\n",mat[i][0],mat[i][1],mat[i][2]);
	Findtranspose(Triplet,Transpose);
}

void Findtranspose(int Triplet[10][3],int Transpose[10][3])
{
   int i,j,k=1;
   Transpose[0][0]=Triplet[0][1];
   Transpose[0][1]=Triplet[0][2];
   for(j=0;j<=Triplet[0][1];j++)
   {
     for(i=1;i<=Triplet[0][2];i++)
     {
       if(Triplet[i][1]==j)
       {
         Transpose[k][0]=Triplet[i][1];
         Transpose[k][1]=Triplet[i][0];
         Transpose[k][2]=Triplet[i][2];
         k++;
       }
     }
   }
}   
