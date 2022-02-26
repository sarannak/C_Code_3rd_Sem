/*C Program to create segment tree of a given array*/

#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define minimum(x,y) (x<y)?x:y

typedef struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
}node;

void create(node**,int[],int,int);   //Creates segment tree

void inorder(node*);        //traversal
void preorder(node*);

int sub_min(node*,int,int,int,int);       //finds minimum in given subsequence

int main()
{
    int a[]={2,5,1,4,9,3},n=6,i,start,end;node *root=NULL;

    for(i=0;i<n;i++)
        printf("   %d",*(a+i));
    printf("\n");

    create(&root,a,0,n-1);

    printf(" Inorder: ");
    inorder(root);
    printf("\n");

    printf("Preorder: ");
    preorder(root);
    printf("\n\n");

    printf("Enter Subsequence:-\n");
    printf("Enter start of subsequence: ");
    scanf("%d",&start);
    printf("Enter end of subsequence: ");
    scanf("%d",&end);

    printf("\nMinimum = %d\n\n",sub_min(root,0,n-1,start,end));

    return 0;
}

void create(node **root,int a[],int first,int last)
{
    if(first<last)
    {
        int mid=(first+last)/2;

        *root=(node*)malloc(sizeof(node));
        (*root)->lchild=(*root)->rchild=NULL;

        create(&((*root)->lchild),a,first,mid);
        create(&((*root)->rchild),a,mid+1,last);
    }

    if(first==last)
    {
        *root=(node*)malloc(sizeof(node));
        (*root)->data=a[first];
        (*root)->lchild=(*root)->rchild=NULL;

    }

    if((*root)->lchild!=NULL&&(*root)->rchild!=NULL)       //if root is not leaf node then take minimum of of its left and right child
        (*root)->data=minimum((*root)->lchild->data,(*root)->rchild->data);

    return;
}

void inorder(node *root)
{
    if(root!=NULL)
    {
        inorder(root->lchild);
        printf("   %d",root->data);
        inorder(root->rchild);
    }

    return;
}

void preorder(node *root)
{
    if(root!=NULL)
    {
        printf("   %d",root->data);
        preorder(root->lchild);
        preorder(root->rchild);
    }
    return;
}

int sub_min(node *root,int first,int last,int start,int end)
{
    int mid=(first+last)/2;
    if(start<=first&&end>=last)
        return root->data;
    if(last<start||first>end)
        return INT_MAX;

    return minimum(sub_min(root->lchild,first,mid,start,end),sub_min(root->rchild,mid+1,last,start,end));
}
