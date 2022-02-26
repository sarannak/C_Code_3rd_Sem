#include<stdio.h>
#define MAX 20

void bubble_sort(int[],int,int);
void pass(int[],int);

int main()
{
    int a[MAX],n,i;

    printf("\nEnter no. of elements: ");
    scanf("%d",&n);

    printf("\nEnter %d elements:\n",n);
    for(i=0;i<n;++i)
        scanf("%d",a+i);

    printf("\nGiven Array:-\n");
    for(i=0;i<n;++i)
        printf("   %d",*(a+i));
    printf("\n");

    bubble_sort(a,n,n);

    printf("\nSorted Array:-\n");
    for(i=0;i<n;++i)
        printf("   %d",*(a+i));
    printf("\n\n");

    return 0;
}

void bubble_sort(int a[],int size,int n)
{
    if(n==1)
        return;
    else
    {
        pass(a,size);
        bubble_sort(a,size,n-1);
    }
}

void pass(int a[],int n)
{
    if(n==0)
        return;
    else
    {
        int temp;

        if(a[n]<a[n-1])
        {
            temp=a[n];
            a[n]=a[n-1];
            a[n-1]=temp;
        }
        pass(a,n-1);
    }
}
