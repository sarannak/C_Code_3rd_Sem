/*C Program to perform various operations on singly linked list*/

#include<stdio.h>       //Preprocessor Directive
#include<stdlib.h>

typedef struct node      //defining node datatype
{
    int data;
    struct node *next;
}node;

void create(node**,int);       //Function Declaration

int add_begin(node**,int);
int add_end(node**,int);
void add_after(node**,int,node*);
void add_before(node**,int,node*);

int delete_begin(node**);
int delete_end(node**);
void delete_node(node**,node*);
int delete_after(node**,node*);

node* search(node**,int,int*);
void display(node*);

int main()
{
    int n,item,loc,c,value; node *head=NULL,*p=NULL;   //Variable Declaration

    do                //Loop to print main menu
    {
        printf("\n------------MAIN MENU------------\n");
        printf("\n1.Create Singly Linked List");
        printf("\n2.Add Begin");
        printf("\n3.Add End");
        printf("\n4.Add After");
        printf("\n5.Add Before");
        printf("\n6.Delete Begin");
        printf("\n7.Delete End");
        printf("\n8.Delete Node");
        printf("\n9.Delete After");
        printf("\n10.Search");
        printf("\n11.Display");
        printf("\n12.Exit");
        printf("\n\nEnter Choice: ");
        scanf("%d",&n);

        switch(n)
        {
            case 1:{                           //Create Node
                     printf("\nEnter Data: ");
                     scanf("%d",&item);
                     create(&head,item);
                     printf("\nNode Created with data: %d\n",item);
                     break;
                   }

            case 2:{                            //Add Begin
                     printf("\nEnter Data: ");
                     scanf("%d",&item);
                     c=add_begin(&head,item);
                     if(c==1)
                         printf("\nNew Header Node Created with data: %d\n",item);
                     break;
                   }

            case 3:{                            //Add End
                     printf("\nEnter Data: ");
                     scanf("%d",&item);
                     c=add_end(&head,item);
                     if(c==-1)
                         printf("\nAdded Node at end with data: %d\n",item);
                     break;
                   }

            case 4:{                        //Add After
                     printf("\nEnter value after which node is to be added: ");
                     scanf("%d",&value);
                     p=search(&head,value,&loc);
                     if(p==NULL)
                         printf("\n%d NOT FOUND\n",value);
                     else
                     {
                         printf("\nEnter Data: ");
                         scanf("%d",&item);
                         add_after(&head,item,p);
                         printf("\nAdded Node with data: %d\n",item);
                     }
                     break;
                   }

            case 5:{                        //Add Before
                     printf("\nEnter value before which node is to be added: ");
                     scanf("%d",&value);
                     p=search(&head,value,&loc);
                     if(p==NULL)
                         printf("\n%d NOT FOUND\n",value);
                     else
                     {
                         printf("\nEnter Data: ");
                         scanf("%d",&item);
                         add_before(&head,item,p);
                         printf("\nAdded Node with data: %d\n",item);
                     }
                     break;
                   }

            case 6:{                       //Delete Begin
                     c=delete_begin(&head);
                     if(c!=-1)
                         printf("\n%d Deleted\n",c);
                     break;
                   }

            case 7:{                        //Delete End
                     c=delete_end(&head);
                     if(c!=-1)
                         printf("\n%d Deleted\n",c);
                     break;
                   }

            case 8:{                           //Delete Node
                     printf("\nEnter value to be deleted: ");
                     scanf("%d",&value);
                     p=search(&head,value,&loc);
                     if(p==NULL)
                         printf("\n%d NOT FOUND\n",value);
                     else
                     {
                         delete_node(&head,p);
                         printf("\n%d Deleted\n",value);
                     }
                     break;
                   }

            case 9:{                             //Delete After
                     printf("\nEnter value to be deleted: ");
                     scanf("%d",&value);
                     p=search(&head,value,&loc);
                     if(p==NULL)
                         printf("\n%d NOT FOUND\n",value);
                     else if(p->next==NULL)
                         printf("\nCannot Delete After %d\n",value);
                     else
                     {
                         c=delete_after(&head,p);
                         printf("\n%d Deleted\n",c);
                     }
                     break;
                   }

            case 10:{                            //Search
                     printf("\nEnter value to be searched: ");
                     scanf("%d",&value);
                     p=search(&head,value,&loc);
                     if(p==NULL)
                         printf("\n%d NOT FOUND\n",value);
                     else
                         printf("\n%d FOUND at position %d\n",value,loc+1);
                     break;
                    }

            case 11:{
                     display(head);
                     break;
                    }

            case 12: break;

            default: printf("\nWRONG CHOICE\n");
        }//end of switch case

    }while(n!=12);             //end of do-while loop

    printf("\n");

    return 0;
}           //end of program

void create(node **head,int item)           //Function to create node
{
    node *ptr=NULL,*new_node=(node*)malloc(sizeof(node));
    new_node->data=item;

    if(*head==NULL)
        *head=new_node;
    else
    {
        for(ptr=*head;ptr->next!=NULL;ptr=ptr->next);
        ptr->next=new_node;
    }

    new_node->next=NULL;
    return;
}    //end of create

int add_begin(node **head,int item)
{
    if(*head==NULL)
    {
        printf("\nLINKED LIST IS EMPTY\n");
        return 0;
    }
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=item;

    new_node->next=*head;
    *head=new_node;

    return 1;
}

int add_end(node **head,int item)        //Function to add at end
{
    if(*head==NULL)
    {
        printf("\nLINKED LIST IS EMPTY\n");
        return 0;
    }

    node *new_node=(node*)malloc(sizeof(node)),*ptr=NULL;
    new_node->data=item;

    for(ptr=*head;ptr->next!=NULL;ptr=ptr->next);

    ptr->next=new_node;
    new_node->next=NULL;

    return 1;
}          //end of add end

void add_after(node **head,int item,node *p)      //function to add after a node
{
    node *new_node=(node*)malloc(sizeof(node)),*ptr=p->next;
    new_node->data=item;

    p->next=new_node;
    new_node->next=ptr;

    return;
}     //end of add after

void add_before(node **head,int item,node *p)        //function to add before
{
    if(*head==p)
    {
        add_begin(head,item);
        return;
    }
    node *new_node=(node*)malloc(sizeof(node)),*ptr=*head,*pptr=*head;
    new_node->data=item;

    for(;ptr!=p;ptr=ptr->next)
        pptr=ptr;

    new_node->next=p;
    pptr->next=new_node;

    return;
}            //end of add before function

int delete_begin(node **head)       //function to delete begin
{
    if(*head==NULL)
    {
        printf("\nLINKED LIST IS EMPTY\n");
        return -1;
    }

    int temp=(*head)->data;node *ptr=*head;

    *head=(*head)->next;
    free(ptr);

    return temp;
}         //end of delete begin

int delete_end(node **head)       //function to delete end
{
    if(*head==NULL)
    {
        printf("\nLINKED LIST IS EMPTY\n");
        return -1;
    }

    int temp; node *ptr=*head,*pptr=*head;

    for(;ptr->next!=NULL;ptr=ptr->next)
        pptr=ptr;

    temp=ptr->data;
    pptr->next=NULL;
    free(ptr);

    return temp;
}          //end of delete end

void delete_node(node **head,node *p)          //function to delete a node
{
    node *ptr=*head,*pptr=*head;

    if(*head==p)
    {
        delete_begin(head);
        return;
    }

    for(;ptr!=p;ptr=ptr->next)
        pptr=ptr;

    pptr->next=ptr->next;
    free(ptr);
    return;
}        //end of delete node

int delete_after(node **head,node *p)  //function to delete after
{
    node *ptr=p->next;int temp=p->next->data;

    p->next=ptr->next;
    free(ptr);

    return temp;
}        //end of delete after

node* search(node **head,int value,int *loc)         //function to search
{
    if(*head==NULL)
    {
        printf("\nLINKED LIST IS EMPTY\n");
        *loc=-1;
        return NULL;
    }

    node *ptr=*head;
    *loc=0;

    for(;ptr!=NULL&&ptr->data!=value;ptr=ptr->next)
        *loc=*loc+1;

    return ptr;
}           //end of search

void display(node *head)           //function to display linked list
{
    if(head==NULL)
    {
        printf("\nLINKED LIST IS EMPTY\n");
        return;
    }

    node *ptr=head;

    printf("\n");

    for(;ptr!=NULL;ptr=ptr->next)
        printf("   %d",ptr->data);

    printf("\n");

    return;
}            //end of display function
