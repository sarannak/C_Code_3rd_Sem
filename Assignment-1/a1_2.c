/*C program to delete an element form a specified position of an array*/

#include<stdio.h>

void Delete(int[],int*,int);    //Function Declaration

int main()
{
    int a[100],n,i,p;     //Variables Declaration

    printf("Enter no. of elements: ");
    scanf("%d",&n);

    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
	scanf("%d",(a+i));     //Input array

    printf("Given Array:\n");
    for(i=0;i<n;i++)
	printf("   %d",*(a+i));

    printf("\nEnter position to be deleted: ");
    scanf("%d",&p);     //Input Position

    Delete(a,&n,p);    //Fucntion Call

    printf("After Deletion:\n");
    for(i=0;i<n;i++)
	printf("   %d",*(a+i));     //Output Array
    printf("\n");

    return 0;
}    //End of program

void Delete(int a[],int *n,int p)    //Function Definition
{
    int i;

    for(i=0;i<p-1;i++);

    for(;i<*n-1;i++)
	a[i]=a[i+1];

    *n=*n-1;     //Decreasing Size

    return;
}     //End of Function
