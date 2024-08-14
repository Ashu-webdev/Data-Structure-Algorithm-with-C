//Merge sort
#include<stdio.h>
#include<stdlib.h>
void mergesort(int[],int,int);
void merge(int[],int,int,int);
void display(int[],int);
int main()
{
	int n,a[20],i,p=0;
        printf("\nEnter no of elements\n");
        scanf("%d", &n);
        printf("\nEnter %d no of elements\n",n);
        for(i=0;i<n;i++)
                scanf("%d",&a[i]);
	printf("Array is\n");
        for(i=0;i<n;i++)
                printf("%d\t",a[i]);
	printf("\n");
	mergesort(a,p,n);
	display(a,n);
}
void mergesort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=(p+r)/2;
		mergesort(a,p,q);
		mergesort(a,q+1,r);
		merge(a,p,q,r);
	}
}
void merge(int a[],int p,int q,int r)
{
	int i,j,k,n1=q-p+1,n2=r-q;
	int l[n1+1],m[n2+1];
	for(i=0;i<n1;i++)
		l[i]=a[p+i];
	 for(j=0;j<n2;j++)
                m[j]=a[q+j+1];
	 l[n1]=9999;
	 m[n2]=9999;
	 i=0;
	 j=0;
	 for(k=p;k<=r;k++)
	 {
		 if(l[i]<m[j])
		 {
			 a[k]=l[i];
			 i++;
		 }
		 else
		 {
			 a[k]=m[j];
			 j++;
		 }
	 }
}
void display(int a[],int n)
{
	int i;
	printf("Sorted array is\n");
	for(i=0;i<n;i++)
		printf("%d\t",a[i]);
	printf("\n");
}
