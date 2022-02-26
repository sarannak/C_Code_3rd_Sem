/*C Program to implement circular linked list*/

#include<stdio.h>   //Preprocessor Directive
#include<stdlib.h>

typedef struct node       //Defining node
{
    int data;
    struct node *next;
}node;

void insert(node**,int);         //Function Declaration

void add_begin(node**,int);
void add_end(node**,int);
void add_after(node**,int,node*);

void delete_begin(node**,int*);
void delete_end(node**,int*);
void delete_node(node**,int*,node*);
void delete_after(node**,int*,node*);

node* search(node**,int,int*);

void display(node**);

int main()         
{
    int option,item,value,loc; node *head=NULL,*p=NULL;   //Variable Declaration

    printf("\nCircular Linked List\n");

    do                       //Loop to Print Main Menu
    {
        printf("\n---------MAIN MENU---------\n");
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
        printf("\nEnter Option: ");
        scanf("%d",&option);

        switch(option)
        {
            case 1:{                      //Create Node
                     printf("\nEnter Element: ");
                     scanf("%d",&item);
                     insert(&head,item);
                     printf("\n%d Added\n",item);
                     break;
                   }

            case 2:{                   //Add Begin
                     if(head==NULL)
                     {
                         printf("\nLinked List is EMPTY\n");
                         break;
                     }

                     printf("\nEnter Element: ");
                     scanf("%d",&item);
                     add_begin(&head,item);
                     printf("\n%d Added as new head\n",item);
                     break;
                   }

            case 3:{                    //Add End
                     if(head==NULL)
                     {
                         printf("\nLinked List is EMPTY\n");
                         break;
                     }

                     printf("\nEnter Element: ");
                     scanf("%d",&item);
                     add_end(&head,item);
                     printf("\n%d Added at End\n",item);
                     break;
                   }

            case 4:{                    //Add After
                     if(head==NULL)
                     {
                         printf("\nLinked List is EMPTY\n");
                         break;
                     }

                     printf("\nEnter value after which node is to inserted: ");
                     scanf("%d",&value);

                     p=search(&head,value,&loc);

                     if(p==NULL)
                     {
                         printf("\n%d NOT FOUND\n",value);
                     }
                     else
                     {
                         printf("\nEnter Element: ");
                         scanf("%d",&item);

                         add_after(&head,item,p);
                         printf("\n%d Added After %d\n",item,value);
                     }
                     break;
                   }

            case 5:{                   //Delete Begin
                     if(head==NULL)
                     {
                         printf("\nLinked List is EMPTY\n");
                         break;
                     }

                     delete_begin(&head,&item);
                     printf("\n%d Deleted\n",item);

                     break;
                   }

            case 6:{                    //Delete End
                     if(head==NULL)
                     {
                         printf("\nLinked List is EMPTY\n");
                         break;
                     }

                     delete_end(&head,&item);
                     printf("\n%d Deleted\n",item);
                     break;
                   }

            case 7:{                  //Delete Node
                     if(head==NULL)
                     {
                         printf("\nLinked List is EMPTY\n");
                         break;
                     }

                     printf("\nEnter value: ");
                     scanf("%d",&value);

                     p=search(&head,value,&loc);
                     if(p==NULL)
                         printf("\n%d NOT FOUND\n",value);
                     else
                     {
                         delete_node(&head,&item,p);
                         printf("\n%d Deleted\n",item);
                     }
                     break;
                   }

            case 8:{                    //Delete After
                     if(head==NULL)
                     {
                         printf("\nLinked List is EMPTY\n");
                         break;
                     }
                     printf("\nEnter value: ");
                     scanf("%d",&value);

                     p=search(&head,value,&loc);
                     if(p==NULL)
                         printf("\n%d NOT FOUND\n",value);
                     else
                     {
                         delete_after(&head,&item,p);
                         printf("\n%d Deleted\n",item);
                     }
                     break;
                   }

            case 9:{                  //Search
                     if(head==NULL)
                     {
                         printf("\nLinked List is EMPTY\n");
                         break;
                     }

                     printf("\nEnter item: ");
                     scanf("%d",&item);

                     search(&head,item,&loc);
                     if(loc==-1)
                         printf("\n%d NOT FOUND\n",item);
                     else
                         printf("\n%d FOUND at position %d\n",item,loc+1);

                     break;
                   }

            case 10:{                    //Display
                      if(head==NULL)
                      {
                          printf("\nLinked List is EMPTY\n");
                          break;
                      }
                      printf("\nDisplaying Circular Linked List.........\n\n");
                      display(&head);
                      printf("\n");
                      break;
                    }
        }                //End of Switch
    }while(option!=11);         //End of loop

    printf("\n");
    return 0;
}                  //End of Program

void insert(node **head,int item)            //Insert
{
    node *new_node=(node*)malloc(sizeof(node)),*ptr=NULL;
    new_node->data=item;

    if(*head==NULL)
        *head=new_node;
    else
    {
        for(ptr=*head;ptr->next!=*head;ptr=ptr->next);
        ptr->next=new_node;
    }

    new_node->next=*head;

    return;
}                //End of Insert

void display(node **head)         //Display
{
    node *ptr=*head;

    for(;ptr->next!=*head;ptr=ptr->next)
        printf("   %d",ptr->data);
    printf("   %d",ptr->data);
    return;
}                //End of Display

void add_begin(node **head,int item)           //Add Begin
{
    node *new_node=(node*)malloc(sizeof(node)),*ptr=NULL;
    new_node->next=*head;
    new_node->data=item;

    for(ptr=*head;ptr->next!=*head;ptr=ptr->next);

    ptr->next=new_node;
    *head=new_node;

    return;
}                //End of Add Begin

void add_end(node **head,int item)            //Add End
{
    node *new_node=(node*)malloc(sizeof(node)),*ptr=*head;
    new_node->data=item;
    new_node->next=*head;

    for(;ptr->next!=*head;ptr=ptr->next);
    ptr->next=new_node;
    return;
}                 //End of Add end

node* search(node **head,int item,int *loc)        //Search
{
    node *ptr=*head,*p=NULL; *loc=0;

    while(ptr->data!=item&&ptr->next!=*head)
    {
        *loc=(*loc)+1;
        ptr=ptr->next;
    }
    if(ptr->data==item)
    {
        return ptr;
    }
    else
    {
        *loc=-1;
        return NULL;
    }
}            //End of Search

void add_after(node **head,int item,node *p)        //Add After
{
    node *new_node=(node*)malloc(sizeof(node));
    new_node->data=item;
    new_node->next=p->next;
    p->next=new_node;

    return;
}                  //End of Add After

void delete_begin(node **head,int *item)       //Delete Begin
{
    node *ptr=*head;*item=(*head)->data;

    if(ptr->next==*head)
    {
        *head=NULL;
        free(ptr);
        return;
    }

    for(;ptr->next!=*head;ptr=ptr->next);
    ptr->next=(*head)->next;
    ptr=*head;
    *head=(*head)->next;
    free(ptr);
    return;
}                  //End of Delete Begin

void delete_end(node **head,int *item)          //Delete End
{
    node *ptr=*head,*p=NULL;

    if(ptr->next==*head)
    {
        delete_begin(head,item);
        return;
    }

    for(;ptr->next->next!=*head;ptr=ptr->next);

    p=ptr->next;
    *item=ptr->next->data;
    ptr->next=*head;
    free(p);
    return;
}                //End of Delete End

void delete_node(node **head,int *item,node *p)        //Delete Node
{
    node *ptr=*head; *item=p->data;

    if(p==*head)
    {
        delete_begin(head,item);
        return;
    }

    for(;ptr->next!=p;ptr=ptr->next);

    ptr->next=p->next;
    free(p);
    return;
}                   //End of Delete Node

void delete_after(node **head,int *item,node *p)      //Delete After
{
    node *ptr=NULL;

    if(p->next==*head)
    {
        delete_begin(head,item);
        return;
    }

    ptr=p->next;
    p->next=ptr->next;
    free(ptr);
    return;
}                      //End of Delete After
