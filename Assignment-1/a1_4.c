/*C program to delete duplicate elements from an array*/

#include<stdio.h>

void delete_duplicates(int[],int*);   //Function Declaration

int main()
{
    int a[100],i,n;

    printf("Enter no. of elements: ");
    scanf("%d",&n);

    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
	scanf("%d",&a[i]);

    delete_duplicates(a,&n);

    printf("After deletion:\n");
    for(i=0;i<n;i++)
	printf("   %d",*(a+i));   //Output
    printf("\n\n");

    return;
}         //End of program

void delete_duplicates(int a[],int *size)  //Function definition
{
    int i,j,k;
    
    for(i=0;i<*size-1;i++)  //Loop to iterate through the array
    {
    	for(j=i+1;j<*size;)    //Loop to check for duplicate elements
    	{
    		if(a[j]==a[i])
    		{
    			for(k=j;k<*size-1;k++)   //Loop to delete element
    			{
    				a[k]=a[k+1];
				}
				*size=*size-1;
			}
			else
			    j++;
		}
	}

    return;

}           //End of Function
