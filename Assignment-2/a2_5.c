#include<stdio.h>
#define MAX 10

void selection_sort(int[],int);
void min(int[],int,int,int*);

int main()
{
    int a[MAX],n,i;

    printf("Enter no. of elements: ");
    scanf("%d",&n);

    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
	scanf("%d",a+i);

    printf("\nGiven Array:-\n");
    for(i=0;i<n;i++)
	printf("   %d",*(a+i));

    selection_sort(a,n);

    printf("\n\nSorted Array:-\n");
    for(i=0;i<n;i++)
	printf("   %d",*(a+i));
    printf("\n\n");

    return 0;
}

void selection_sort(int a[],int n)
{
    int i,loc,temp;

    for(i=0;i<n;i++)
    {
	min(a,n,i,&loc);
	temp=a[i];
	a[i]=a[loc];
	a[loc]=temp;
    }

    return;
}

void min(int a[],int n,int k,int *loc)
{
    int temp,j;

    temp=a[k];*loc=k;

    for(j=k+1;j<n;j++)
    {
	if(a[j]<temp)
	{
	    temp=a[j];
	    *loc=j;
	}
    }
    return;
}
