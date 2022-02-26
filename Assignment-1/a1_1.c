/*C Progrma to insert an element in a specific position of an array*/

#include<stdio.h>

void Insert(int[],int*,int,int);  //Function Declaration

int main()
{
    int a[100],i,p,key,n;     //Declaration

    printf("Enter no. of elements: ");
    scanf("%d",&n);

    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
	scanf("%d",&a[i]);    //Input array

    printf("Given Array:\n");
    for(i=0;i<n;i++)
	printf("   %d",*(a+i));

    printf("\nEnter key value: ");
    scanf("%d",&key);   //Input Key

    printf("Enter position: ");
    scanf("%d",&p);   //Input position

    Insert(a,&n,key,p);   //Function call

    printf("After inserting %d at %d position:\n",key,p);
    for(i=0;i<n;i++)
	printf("   %d",*(a+i));   //printing array
    printf("\n");

    return 0;
}         //End of program

void Insert(int a[],int *n,int key,int p)    //Fucntion Definition
{
    int i;

    for(i=(*n)-1;i>=p-1;i--)   //Loop to copy
        a[i+1]=a[i];
    a[p-1]=key;     //Inserting key

    *n=*n+1;    //Increasing size of array

    return;
}
