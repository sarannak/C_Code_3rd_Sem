#include<stdio.h>
#define MAX 20

int binary_search(int[],int,int,int);

int main()
{
    int a[MAX],n,i,key,c;

    printf("\nEnter no. of elements: ");
    scanf("%d",&n);

    printf("\nEnter %d elements: \n",n);
    for(i=0;i<n;++i)
        scanf("%d",a+i);

    printf("\nEnter KEY: ");
    scanf("%d",&key);

    c=binary_search(a,0,n-1,key);

    if(c==-1)
        printf("\n%d NOT FOUND\n\n",key);
    else
        printf("\n%d FOUND at position %d\n\n",key,c+1);

    return 0;
}

int binary_search(int a[],int first,int last,int key)
{
    if(first>last)
        return -1;

    int mid=(first+last)/2;

    if(a[mid]==key)
        return mid;
    else if(key>a[mid])
        return binary_search(a,mid+1,last,key);
    else
        return binary_search(a,first,mid,key);
}
