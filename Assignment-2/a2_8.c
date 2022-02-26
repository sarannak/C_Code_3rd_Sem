/*C program to implement Merge Sort*/

#include<stdio.h>     //Preprocessor Directive
#define MAX 10

void mergesort(int[],int,int);   //Function Declaration
void merge(int[],int,int,int);

int main()
{
    int a[MAX],n,i;

    printf("Enter no. of elements: ");
    scanf("%d",&n);

    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
        scanf("%d",a+i);    //input array elements

    printf("\nGiven Array:-\n");
    for(i=0;i<n;i++)
        printf("   %d",*(a+i));

    mergesort(a,0,n-1);    //function call

    printf("\n\nSorted Array:-\n");
    for(i=0;i<n;i++)
        printf("   %d",*(a+i));   //output sorted array
    printf("\n\n");

    return 0;
}      //end of program

void mergesort(int a[],int first,int last)
{
    if(first<last)
    {
        int mid=(first+last)/2;

        mergesort(a,first,mid);     //recursive call to divide
        mergesort(a,mid+1,last);

        merge(a,first,mid,last);   //merging divided array
    }

    return;
}     //end of mergesort

void merge(int a[],int first,int mid,int last)
{
    int temp[MAX],k=first,i=first,j=mid+1;

    while(i<=mid&&j<=last)
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }

    while(i<=mid)
        temp[k++]=a[i++];

    while(j<=last)
        temp[k++]=a[j++];

    for(i=first;i<k;i++)   //loop to copy sorted part to original array
        a[i]=temp[i];

    return;
}    //end of merge funtion
