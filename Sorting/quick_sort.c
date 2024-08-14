//Quick sort
#include<stdio.h>
#include<stdlib.h>
int partition(int[],int,int);
void quicksort(int[],int,int);
void display(int[],int);
void swap(int *,int *);
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
        quicksort(a,p,n);
        display(a,n);
}
void quicksort(int a[],int p,int r)
{
	int q;
	if(p<r)
	{
		q=partition(a,p,r);
		quicksort(a,p,q-1);
		quicksort(a,q+1,r);
	}
}
int partition(int a[], int p, int r)
{
	int x,i,j;
	x=a[r];
	i=p-1;
        for(j=p;j<r;j++)
	{
		if(a[j]<=x)
		{
			i=i+1;
			swap(a+i,a+j);
		}
	}
	swap(a+i+1,a+r);
	return i+1;
}
void swap(int *p,int *q)
{
	int t;
	t=*p;
	*p=*q;
	*q=t;
}
void display(int a[],int n)
{
        int i;
        printf("Sorted array is\n");
        for(i=0;i<n;i++)
                printf("%d\t",a[i]);
        printf("\n");
}
