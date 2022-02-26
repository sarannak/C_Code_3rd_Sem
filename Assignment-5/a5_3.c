/*C Program to implement various operations on doubly linked list*/

#include<stdio.h>           //Preprocessor Directive
#include<stdlib.h>

typedef struct node            //node definition
{
    struct node *prev;
    int data;
    struct node *next;
}node;

void insert(node**,int);          //Function Declaration

void add_begin(node**,int);          //Add Part
void add_end(node**,int);
void add_after(node**,int,node*);

void delete_begin(node**,int*);         //Delete Part
void delete_end(node**,int*);
void delete_node(node**,int*,node*);
void delete_after(node**,int*,node*);

node* search(node**,int,int*);         //Search

void display(node*);           //Display

int main()
{
    int n,item,value; node *head=NULL,*p=NULL;     //Variable Declaration

    printf("\nDOUBLY LINKED LIST\n");

    do
    {

        printf("\n-----------MAIN MENU------------\n");       //Main Menu
        printf("\n1.Insert");
        printf("\n2.Add Begin");
        printf("\n3.Add End");
        printf("\n4.Add After");
        printf("\n5.Delete Begin");
        printf("\n6.Delete End");
        printf("\n7.Delete Node");
        printf("\n8.Delete After");
        printf("\n9.Search");
        printf("\n10.Display");
        printf("\n11.Exit\n");
        printf("\nEnter Choice: ");
        scanf("%d",&n);

        switch(n)                         //Switch Case for Choice
        {
            case 1:{                                 //Insert or Create
                     printf("\nEnter Element: ");
                     scanf("%d",&item);

                     insert(&head,item);
                     printf("\n%d Added\n",item);
                     break;
                   }

            case 2:{                        //Add Begin
                     if(head==NULL)
                     {
                         printf("\nDOUBLY LINKED LIST IS EMPTY\n");
                         break;
                     }

                     printf("\nEnter Element: ");
                     scanf("%d",&item);

                     add_begin(&head,item);
                     printf("\n%d Added New Head\n",item);

                     break;
                   }

            case 3:{                    //Add End
                     if(head==NULL)
                     {
                         printf("\nDOUBLY LINKED LIST IS EMPTY\n");
                         break;
                     }

                     printf("\nEnter Element: ");
                     scanf("%d",&item);

                     add_end(&head,item);
                     printf("\n%d Added at end\n",item);

                     break;
                   }

            case 4:{                          //Add After
                     if(head==NULL)
                     {
                         printf("\nDOUBLY LINKED LIST IS EMPTY\n");
                         break;
                     }

                     printf("\nEnter value after which element is to be added: ");
                     scanf("%d",&value);

                     p=search(&head,value,&item);

                     if(p==NULL)
                         printf("\n%d NOT FOUND\n",value);
                     else
                     {
                         printf("\nEnter Element: ");
                         scanf("%d",&item);

                         add_after(&head,item,p);
                         printf("\n%d Added\n",item);
                     }

                     break;
                   }

            case 5:{                      //Delete Beign
                     if(head==NULL)
                     {
                         printf("\nDOUBLY LINKED LIST IS EMPTY\n");
                         break;
                     }

                     delete_begin(&head,&item);
                     printf("\n%d Deleted\n",item);

                     break;
                   }

            case 6:{                            //Delete End
                     if(head==NULL)
                     {
                         printf("\nDOUBLY LINKED LIST IS EMPTY\n");
                         break;
                     }

                     delete_end(&head,&item);
                     printf("\n%d Deleted\n",item);

                     break;
                   }

            case 7:{                             //Delete Node
                     if(head==NULL)
                     {
                         printf("\nDOUBLY LINKED LIST IS EMPTY\n");
                         break;
                     }

                     printf("\nEnter value to deleted: ");
                     scanf("%d",&value);

                     p=search(&head,value,&item);

                     if(p==NULL)
                         printf("\n%d NOT FOUND\n",value);
                     else
                     {
                         delete_node(&head,&item,p);
                         printf("\n%d Deleted\n",value);
                     }

                     break;
                   }

            case 8:{                            //Delete After
                     if(head==NULL)
                     {
                         printf("\nDOUBLY LINKED LIST IS EMPTY\n");
                         break;
                     }

                     printf("\nEnter Value: ");
                     scanf("%d",&value);

                     p=search(&head,value,&item);

                     if(p==NULL)
                         printf("\n%d NOT FOUND\n",value);
                     else
                     {
                         delete_after(&head,&item,p);
                         printf("\n%d Deleted\n",item);
                     }

                     break;
                   }

            case 9:{                             //Search
                     if(head==NULL)
                     {
                         printf("\nDOUBLY LINKED LIST IS EMPTY\n");
                         break;
                     }

                     printf("\nEnter Value to be Searched: ");
                     scanf("%d",&value);

                     search(&head,value,&item);

                     if(item==-1)
                         printf("\n%d NOT FOUND\n",value);
                     else
                         printf("\n%d FOUND at position %d\n",value,item+1);

                     break;
                   }

            case 10:{                             //Display
                      if(head==NULL)
                      {
                          printf("\nDOUBLY LINKED LIST IS EMPTY\n");
                          break;
                      }
                      printf("\nDisplaying Doubly Linked List.............\n\n");
                      display(head);
                      printf("\n");
                      break;
                    }

            case 11:break;

            default: printf("\nWRONG CHOICE\n");

        }         //End of Switch

    }while(n!=11);     //End of Do-While Loop

    printf("\n");

    return 0;
}             //End of Program

void insert(node **head,int item)                   //Insert Definition
{
    node *new_node=(node*)malloc(sizeof(node)),*ptr=NULL;

    new_node->data=item;
    new_node->next=NULL;

    if(*head==NULL)
    {
        *head=new_node;
        new_node->prev=NULL;
    }
    else
    {
        for(ptr=*head;ptr->next!=NULL;ptr=ptr->next);
        new_node->prev=ptr;
        ptr->next=new_node;
    }
    return;
}                     //End of Insert

void add_begin(node **head,int item)                 //Add Begin
{
    node *new_node=(node*)malloc(sizeof(node));

    new_node->data=item;
    new_node->next=*head;
    new_node->prev=NULL;

    *head=new_node;
    return;
}                  //End of Add Begin

void add_end(node **head,int item)               //Add End
{
    node *new_node=(node*)malloc(sizeof(node)),*ptr=*head;

    new_node->data=item;
    new_node->next=NULL;

    for(;ptr->next!=NULL;ptr=ptr->next);

    ptr->next=new_node;
    new_node->prev=ptr;

    return;
}                        //End of Add End

void add_after(node **head,int item,node *p)      //Add After
{
    node *new_node=(node*)malloc(sizeof(node));

    new_node->data=item;
    new_node->next=p->next;

    new_node->prev=p;
    p->next=new_node;
    return;
}                     //End of Add After

void delete_begin(node **head,int *item)            //Delete Begin
{
    node *ptr=*head;

    *head=(*head)->next;
    *item=ptr->data;
    free(ptr);
    if(*head!=NULL)
        (*head)->prev=NULL;

    return;
}                   //End of Delete Begin

void delete_end(node **head,int *item)            //Delete End
{
    if((*head)->next==NULL)
    {
        delete_begin(head,item);
        return;
    }

    node *ptr=*head;

    for(;ptr->next->next!=NULL;ptr=ptr->next);

    *item=ptr->next->data;
    free(ptr->next);
    ptr->next=NULL;

    return;
}                         //End of Delete End

void delete_node(node **head,int *item,node *p)         //Delete Node
{
    if(p==*head)
    {
        delete_begin(head,item);
        return;
    }
    if(p->next==NULL)
    {
        delete_end(head,item);
        return;
    }
    node *ptr=p->prev;

    ptr->next=p->next;
    ptr->next->prev=ptr;

    return;
}                    //End of Delete Node

void delete_after(node **head,int *item,node *p)      //Delete After
{
    if(p->next==NULL)
    {
        printf("\nCANNOT DELETE AFTER %d\n",p->data);
        *item=0;
        return;
    }

    *item=p->next->data;
    p->next=p->next->next;

    free(p->next);
    return;
}                      //End of Delete After

node* search(node **head,int value,int *loc)           //Search
{
    node *ptr=*head,*p=NULL;*loc=0;

    for(;ptr!=NULL&&ptr->data!=value;ptr=ptr->next,*loc=*loc+1);

    if(ptr==NULL)
        *loc=-1;
    else
        p=ptr;

    return p;
}                   //End of Search

void display(node *head)              //Display
{
    for(;head!=NULL;head=head->next)
        printf("   %d",head->data);
    return;
}               //End of Display
