/*C Program to compare bubble,insertion and selection sort*/

#include<stdio.h>      //Preprocessor Directive
#include<stdlib.h>
#include <sys/time.h>
#include<limits.h>
#define MAX 5000

void bubble_sort(int[],int);         //bubble sort

void selection_sort(int[],int);           //selection sort
void min(int[],int,int,int*);

void insertion_sort(int[],int);       //insertion sort

void merge_sort(int[],int,int);   //Function Declaration
void merge(int[],int,int,int);

void quick_sort(int[],int,int);    //Function Prototype
void partition(int[],int,int,int*);

float timedifference_msec(struct timeval t0, struct timeval t1)   //Function to convert seconds to milliseconds
{
    return (t1.tv_sec - t0.tv_sec) * 1000.0f + (t1.tv_usec - t0.tv_usec) / 1000.0f;
}

int main()
{
	struct timeval t1,t2;int a[MAX],i,n;      //Variable Declaration
	
	for(n=1000;n<=MAX;n+=500)
	{
	    srand(rand());          //Seed for random
	    
	    for(i=0;i<n;i++)       //Loop to assign random values
	    {
		    a[i]=rand();         
	    }
	    
	    gettimeofday(&t1, 0);   //Take time
	    bubble_sort(a,n);
	    gettimeofday(&t2, 0);
	    printf("   Bubble Sort with %d elements time = %f milliseconds\n",n,timedifference_msec(t1,t2));
	    
	    for(i=0;i<n;i++)
	    {
		    a[i]=rand();
	    }
	    
	    gettimeofday(&t1, 0);
	    selection_sort(a,n);
	    gettimeofday(&t2, 0);
	    printf("Selection Sort with %d elements time = %f milliseconds\n",n,timedifference_msec(t1,t2));
	    
	    a[0]=INT_MIN;
	    for(i=1;i<=n;i++)
	    {
		    a[i]=rand();
	    }
	    
	    gettimeofday(&t1, 0);
	    insertion_sort(a,n);
	    gettimeofday(&t2, 0);
	    printf("Insertion Sort with %d elements time = %f milliseconds\n",n,timedifference_msec(t1,t2));
	    

      	for(i=0;i<n;i++)
	    {
		    a[i]=rand();
	    }
	    
	    gettimeofday(&t1, 0);
	    quick_sort(a,0,n-1);
	    gettimeofday(&t2, 0);
	    printf("    Quick Sort with %d elements time = %f milliseconds\n",n,timedifference_msec(t1,t2));
	    
       	for(i=0;i<n;i++)
	    {
		    a[i]=rand();
	    }
	    
	    gettimeofday(&t1, 0);
	    merge_sort(a,0,n-1);
	    gettimeofday(&t2, 0);
	    printf("    Merge Sort with %d elements time = %f milliseconds\n",n,timedifference_msec(t1,t2));
	    


	    printf("\n\n");
    }                        //End of Loop
	return 0;
}                    //End of program

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

void selection_sort(int a[],int n)    //Selection Sort
{
    int i,loc,temp;

    for(i=0;i<n;i++)
    {
	min(a,n,i,&loc);
	temp=a[i];
	a[i]=a[loc];
	a[loc]=temp;
    }

    return;
}           //End of selection Sort

void min(int a[],int n,int k,int *loc)    //Min function for insertion sort
{
    int temp,j;

    temp=a[k];*loc=k;

    for(j=k+1;j<n;j++)
    {
	if(a[j]<temp)
	{
	    temp=a[j];
	    *loc=j;
	}
    }
    return;
}        //End of min

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

void merge_sort(int a[],int first,int last)
{
    if(first<last)
    {
        int mid=(first+last)/2;

        merge_sort(a,first,mid);     //recursive call to divide
        merge_sort(a,mid+1,last);

        merge(a,first,mid,last);   //merging divided array
    }

    return;
}     //end of merge sort


void merge(int a[],int first,int mid,int last)
{
    int temp[MAX],k=first,i=first,j=mid+1;

    while(i<=mid&&j<=last)
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }

    while(i<=mid)
        temp[k++]=a[i++];                       
    while(j<=last)
        temp[k++]=a[j++];

    for(i=first;i<k;i++)   //loop to copy sorted array
        a[i]=temp[i];

    return;
}    //end of merge funtion

void quick_sort(int a[],int first,int last)
{
    if(first<last)
    {
	    int loc;
        partition(a,first,last,&loc);   //call partition

        quick_sort(a,first,loc-1);    //divide array
        quick_sort(a,loc+1,last);

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
