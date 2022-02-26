/*C program to implement binary search*/

#include<stdio.h>

int binary_search(int[],int,int);   //Function Declaration

int main()
{
    int a[100],n,i,key,p;

    printf("Enter no. of elements: ");
    scanf("%d",&n);

    printf("Enter %d elements in ascending order:\n",n);
    for(i=0;i<n;i++)
	scanf("%d",a+i);    //Input array

    printf("\nEnter key: ");
    scanf("%d",&key);     //Input Key

    p=binary_search(a,n,key);    //Function Call

    if(p==-1)
	printf("%d not found\n",key);
    else
	printf("%d found at position %d\n",key,p);

    printf("\n");

    return 0;
}         //End of Program

int binary_search(int a[],int n,int key)    //Function Definition
{
    int first=0,last=n-1,mid;

    mid = (first+last)/2;

    while(first<=last&&a[mid]!=key)
    {
	if(key>a[mid])
	    first=mid+1;
	else if(key<a[mid])
	    last=mid-1;
	mid=(first+last)/2;   //Condition Updation
    }

    if(first>last)
	return -1;
    else
	return mid+1;

}    //End of Function
