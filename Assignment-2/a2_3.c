/*C program to implement interpolation search*/

#include<stdio.h>

void interpolation_search(int[],int,int);  //Function Declaration

int main()
{
    int a[100],n,i,key;     //Variables Declaration

    printf("Enter no. of elements: ");
    scanf("%d",&n);

    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
	scanf("%d",a+i);        //Input Array

    printf("\nEnter Key: ");
    scanf("%d",&key);       //Input Key

    interpolation_search(a,n,key);   //Fucntion Call

    printf("\n");

    return 0;
}     //End of program

void interpolation_search(int a[],int n,int key)   //Fucntion Definition
{
    int high=n-1,low=0,mid;

    mid=(high+low)/2;

    while(low<=high&&a[mid]!=key)
    {
	if(key>a[mid])
	    low=mid+1;
	else if(key<a[mid])
	    high=mid-1;
	mid=low+(high-low)*((key-a[low])/(a[high]-a[low]));
				//Condition updation
    }

    if(low>high)
	printf("%d not found\n",key);
    else
	printf("%d found at position %d\n",key,mid+1);

    return;
}    //End of Function
