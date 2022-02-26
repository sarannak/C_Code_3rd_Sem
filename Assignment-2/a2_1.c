/*C program to implement linear search*/

#include<stdio.h>

int linear_search(int[],int,int);   //Function Declaration

int main()
{
    int a[50],i,n,key,p;      //Variables Declaration

    printf("Enter no. of elements: ");
    scanf("%d",&n);

    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
	scanf("%d",&a[i]);    //Input Array

    printf("\nEnter key: ");
    scanf("%d",&key);     //Input Key

    p=linear_search(a,n,key);    //Function Call

    if(p==-1)
	printf("%d not found\n",key);
    else
	printf("%d found at %d\n",key,p);

    printf("\n");

    return 0;
}    //End of program

int linear_search(int a[],int n,int key)   //Function Definition
{
    int i;

    a[n]=key;

    for(i=0;a[i]!=key;i++);

    if(i==n)
	return -1;
    else
	return i+1;

}        //End of function
