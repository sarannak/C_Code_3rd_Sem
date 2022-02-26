/*C Program to implement Insertion Sort*/

#include<stdio.h>     //Preprocessor Directive
#include<limits.h>
#define MAX 10

void insertion_sort(int[],int);    //Function Declaration

int main()
{
    int a[MAX+1],n,i;

    a[0]=INT_MIN;    //Setting Sentinal Element

    printf("Enter no. of elements: ");
    scanf("%d",&n);   //Input no. of elements

    printf("Enter %d elements:\n",n);
    for(i=1;i<=n;i++)
	scanf("%d",a+i);      //Input elements

    printf("\nGiven Array:\n");
    for(i=1;i<=n;i++)
	printf("   %d",*(a+i));   //print given array

    insertion_sort(a,n);      //Function Call

    printf("\n\nSorted Array:\n");
    for(i=1;i<=n;i++)
	printf("   %d",*(a+i));    //print sorted array
    printf("\n\n");

    return 0;
}     //End of program

void insertion_sort(int a[],int n)    //Function Definition
{
    int temp,i,p;

    for(i=1;i<=n;i++)
    {
	temp=a[i];p=i-1;

	while(temp<a[p])    //Loop to copy previous elements
	{
	    a[p+1]=a[p];
	    p--;
	}     //End of while loop

	a[p+1]=temp;
    }      //End of for loop

    return;
}      //End of Function
