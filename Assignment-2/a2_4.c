/*C program to implement refined bubble sort*/

#include<stdio.h>

void bubble_sort(int[],int);     //Function Declaration

int main()
{
    int a[50],n,i;

    printf("Enter no. of elements: ");
    scanf("%d",&n);

    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
	scanf("%d",&a[i]);      //Input array elements

    printf("\nGiven Array;-\n");
    for(i=0;i<n;i++)
	printf("   %d",a[i]);

    bubble_sort(a,n);     //Fucntion Call

    printf("\nAfter Sorting:\n");
    for(i=0;i<n;i++)
	printf("   %d",*(a+i));     //Output Array
    printf("\n");

    return 0;
}      //End of program

void bubble_sort(int a[],int n)       //Fucntion Definition
{
    int i,j,flag=1,temp;

    for(i=0;i<n-1&&flag!=0;i++)
    {
	flag=0;
	for(j=0;j<n-1;j++)
	{
	    if(a[j]>a[j+1])
	    {
		temp=a[j];
		a[j]=a[j+1];
		a[j+1]=temp;
		flag=1;      //if swap happens set flag=1
	    }
	}    //End of inner loop
    }       //End of outer loop

    return;
}        //End of function
