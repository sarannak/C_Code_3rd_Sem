/*C Program to implement quick sort*/

#include<stdio.h>       //preprocessor directive
#define MAX 10

void quicksort(int[],int,int);    //Function Prototype
void partition(int[],int,int,int*);

int main()
{
    int a[MAX],n,i;

    printf("Enter no. of elements: ");
    scanf("%d",&n);

    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
	scanf("%d",a+i);     //input array elements

    printf("\nGiven Array:-\n");
    for(i=0;i<n;i++)
	printf("   %d",*(a+i));

    quicksort(a,0,n-1);    //function call

    printf("\n\nSorted Array:-\n");
    for(i=0;i<n;i++)
        printf("   %d",*(a+i));     //output sorted array
    printf("\n\n");

    return 0;
}      //end of program

void quicksort(int a[],int first,int last)
{
    if(first<last)
    {
        int loc;

        partition(a,first,last,&loc);   //call partition

        quicksort(a,first,loc-1);    //divide array
        quicksort(a,loc+1,last);

    }

    return;
}     //end of quicksort

void partition(int a[],int first,int last,int *loc)
{
    int pivot=a[first],i=first+1,j=last,temp;

    do          //loop to place pivot
    {
        while(j>first&&a[j]>=pivot)
            j--;

        while(i<=last&&a[i]<=pivot)
            i++;

        if(i<j)
        {
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }while(i<j);

    if(i>j)
    {
        temp=a[j];
        a[j]=a[first];
        a[first]=temp;
    }

    *loc=j;    //assigning correct position of pivot

    return;
}       //end of partition
