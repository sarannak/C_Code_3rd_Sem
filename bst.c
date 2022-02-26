#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    struct node *lchild;
    int data;
    struct node *rchild;
}node;

void insert(node**,int);

void inorder(node*);
void preorder(node*);

int main()
{
    int n,item,value; node *root=NULL;

    printf("\nBINARY SEARCH TREE\n");

    do
    {
        printf("\n----------MAIN MENU-----------\n");
        printf("\n1.Insert");
        printf("\n2.Inorder");
        printf("\n3.Preorder");
        printf("\n4.Exit\n");
        printf("\nEnter Choice: ");
        scanf("%d",&n);

        switch(n)
        {
            case 1:{
                     printf("\nEnter Data: ");
                     scanf("%d",&item);
                     insert(&root,item);
                     printf("\n%d Added\n",item);

                     break;
                   }

            case 2:{
                     printf("\nINORDER:");
                     inorder(root);
                     printf("\n");
                     break;
                   }

            case 3:{
                     printf("\nPREORDER:");
                     preorder(root);
                     printf("\n");
                     break;
                   }

            case 4:  break;
            default: printf("\nWRONG CHOICE\n");
        }
    }while(n!=4);

    printf("\n");

    return 0;
}

void insert(node **root,int item)
{
    if(*root==NULL)
    {
        *root=(node*)malloc(sizeof(node));
        (*root)->data=item;
        (*root)->lchild=NULL;
        (*root)->rchild=NULL;
    }
    else if((*root)->data>item)
        insert(&((*root)->lchild),item);
    else if((*root)->data<item)
        insert(&((*root)->rchild),item);

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
