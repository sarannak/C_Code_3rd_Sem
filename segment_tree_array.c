/*C Program to create segment tree of a given array*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define minimum(x,y) (x<y)?x:y

void create(int[],int,int[],int,int);   //Creates segment tree

void inorder(int[],int);        //traversal
void preorder(int[],int);

int sub_min(int[],int,int,int,int,int);       //finds minimum in given subsequence

int main()
{
    int a[]={2,5,1,4,9,3},n=6,i,start,end;
    
    int *tree=(int*)calloc(sizeof(int),4*n+10);

    for(i=0;i<n;i++)
        printf("   %d",*(a+i));
    printf("\n");

    create(tree,1,a,0,n-1);

    printf(" Inorder: ");
    inorder(tree,1);
    printf("\n");

    printf("Preorder: ");
    preorder(tree,1);
    printf("\n\n");

    printf("Enter Subsequence:-\n");
    printf("Enter start of subsequence: ");
    scanf("%d",&start);
    printf("Enter end of subsequence: ");
    scanf("%d",&end);

    printf("\nMinimum = %d\n\n",sub_min(tree,1,0,n-1,start,end));

    return 0;
}

void create(int tree[],int index,int a[],int first,int last)
{
    if(first<last)
    {
        int mid=(first+last)/2;

        tree[2*index]=tree[2*index+1]=0;

        create(tree,2*index,a,first,mid);
        create(tree,2*index+1,a,mid+1,last);
    }

    if(first==last)
    {
        tree[index]=a[first];
        tree[2*index]=tree[2*index+1]=0;

    }

    if(tree[2*index]!=0&&tree[2*index+1]!=0)       //if root is not leaf node then take minimum of of its left and right child
        tree[index]=minimum(tree[2*index],tree[2*index+1]);

    return;
}

void inorder(int tree[],int index)
{
    if(tree[index]!=0)
    {
        inorder(tree,2*index);
        printf("   %d",tree[index]);
        inorder(tree,2*index+1);
    }

    return;
}

void preorder(int tree[],int index)
{
    if(tree[index]!=0)
    {
        printf("   %d",tree[index]);
        preorder(tree,2*index);
        preorder(tree,2*index+1);
    }
    return;
}

int sub_min(int tree[],int index,int first,int last,int start,int end)
{
    int mid=(first+last)/2;
    if(start<=first&&end>=last)
        return tree[index];
    if(last<start||first>end)
        return INT_MAX;

    return minimum(sub_min(tree,2*index,first,mid,start,end),sub_min(tree,2*index+1,mid+1,last,start,end));
}
