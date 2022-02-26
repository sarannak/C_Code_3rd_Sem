/*C Program to Add To Add 2 Polynomial using Linked List Representation*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
    int pow;
    int coef;
    struct node *next;
}node;

void create(node**);

void add(node*,node*,node**);
void insert(node**,int,int);

void display(node*);

int main()
{

    int n,i,temp,pow,coef; node *head[3]={NULL,NULL,NULL};

    printf("\nPOLYNOMIAL ADDITION\n");

    do
    {
        printf("\n---------MAIN MENU----------\n");
        printf("\n1.Create 1st Polynomial");
        printf("\n2.Create 2nd Polynomial");
        printf("\n3.Add to Polynomials");
        printf("\n4.Display");
        printf("\n5.Exit\n");
        printf("\nEnter Choice: ");
        scanf("%d",&n);

        switch(n)
        {
            case 1:{
                     printf("\nEnter terms in decreasing power of x\n");
                     create(&head[0]);
                     printf("\nNew Polynomial Created\n");
                     break;
                   }

            case 2:{
                     printf("\nEnter terms in decreasing power of x\n");
                     create(&head[1]);
                     printf("\nNew Polynomial Created\n");
                     break;
                   }

            case 3:{
                     if(head[0]==NULL)
                         head[2]=head[1];
                     else if(head[1]==NULL)
                         head[2]=head[0];
                     else
                         add(head[0],head[1],&head[2]);
                     printf("\nAddition Completed\n");
                     break;
                   }

            case 4:{
                     printf("\n1.Display 1st Polynomial");
                     printf("\n2.Display 2nd Polynomial");
                     printf("\n3.Display Addition\n");
                     printf("\nEnter Choice: ");
                     scanf("%d",&i);

                     if(head[i-1]==NULL)
                     {
                         printf("\nEMPTY LIST\n");
                         break;
                     }

                     printf("\nDisplaying..............\n\n");
                     display(head[i-1]);
                     printf("\n");

                     break;
                   }

            case 5: break;
            default: printf("\nWRONG CHOICE\n");
        }

    }while(n!=5);

    printf("\n");

    return 0;
}

void create(node **head)
{
    int n; node *new_node=NULL,*ptr=NULL;

    do
    {
        new_node=(node*)malloc(sizeof(node));

        printf("\nEnter Power: ");
        scanf("%d",&new_node->pow);
        printf("Enter Coefficient: ");
        scanf("%d",&new_node->coef);
        new_node->next=NULL;

        if(*head==NULL)
        {
            *head=new_node;
            ptr=new_node;
        }
        else
        {
            ptr->next=new_node;
            ptr=new_node;
        }

        printf("\n1.Enter data");
        printf("\n2.Mark as completed\n");
        printf("\nEnter Choice: ");
        scanf("%d",&n);
    }while(n!=2);

    return;
}

void add(node *p1,node *p2,node **head)
{
    while(p1!=NULL&&p2!=NULL)
    {
        if(p1->pow>p2->pow)
        {
            insert(head,p1->pow,p1->coef);
            p1=p1->next;
        }
        else if(p2->pow>p1->pow)
        {
            insert(head,p2->pow,p2->coef);
            p2=p2->next;
        }
        else
        {
            if(p1->coef+p2->coef!=0)
                insert(head,p1->pow,p1->coef+p2->coef);
            p1=p1->next;
            p2=p2->next;
        }
    }

    while(p1!=NULL)
    {
        insert(head,p1->pow,p1->coef);
        p1=p1->next;
    }

    while(p2!=NULL)
    {
        insert(head,p2->pow,p2->coef);
        p2=p2->next;
    }

    return;
}

void insert(node **head,int pow,int coef)
{
    node *new_node=(node*)malloc(sizeof(node)),*ptr=NULL;

    new_node->next=NULL;
    new_node->pow=pow;
    new_node->coef=coef;

    if(*head==NULL)
        *head=new_node;
    else
    {
        for(ptr=*head;ptr->next!=NULL;ptr=ptr->next);
        ptr->next=new_node;
    }
    return;
}

void display(node *head)
{
    for(;head!=NULL;head=head->next)
        printf("%+dx^%d",head->coef,head->pow);
    return;
}
