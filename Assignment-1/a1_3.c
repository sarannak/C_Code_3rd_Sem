/*C program to merge two sorted arrays*/

#include<stdio.h>

void merge(int[],int,int[],int,int[]);  //Function Declaration

int main()
{
    int a[50],b[50],c[100],i,m,n;    //Variables Declaration

    printf("Enter 2 sorted arrays:\n\n");

    printf("Enter no. of elements of 1st Array: ");
    scanf("%d",&m);

    printf("Enter %d elements:\n",m);
    for(i=0;i<m;i++)
	scanf("%d",a+i);     //Input 1st array

    printf("Enter no. of elements of 2nd Array: ");
    scanf("%d",&n);

    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
	scanf("%d",b+i);     //Input 2nd array

    printf("1st Array:\n");
    for(i=0;i<m;i++)
	printf("   %d",*(a+i));

    printf("\n2nd Array:\n");
    for(i=0;i<n;i++)
	printf("   %d",*(b+i));

    merge(a,m,b,n,c);     //Fucntion Call

    printf("\n\nAfter merging:\n");
    for(i=0;i<m+n;i++)
	printf("   %d",*(c+i));    //Output merged array
    printf("\n\n");

    return 0;
}     //End of program

void merge(int a[],int m,int b[],int n,int c[])  //Fucntion Definition
{
    int i=0,j=0,k=0;

    while(i<m&&j<n)
    {
	if(a[i]<b[j])
	    c[k++]=a[i++];
	else
	    c[k++]=b[j++];
    }

    if(i==m)
    {
	while(k<m+n)
	    c[k++]=b[j++];
    }
    else if(j==n)
    {
	while(k<m+n)
	    c[k++]=a[i++];
    }

    return;
}     //End of function
