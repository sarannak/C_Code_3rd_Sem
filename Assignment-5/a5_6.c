/*C Program to implement linked queue*/

#include<stdio.h>       //preprocessor directive
#include<stdlib.h>

typedef struct node     //defining node
{
    int data;
    struct node *next;
}node;

void enque(node**,node**,int);     //function declaration
int deque(node**,node**,int*);
int peek(node*,int*);

void display(node*);

int main()
{
    int n,item;node *front=NULL,*rear=NULL;    //variable declaration

    do             //main menu
    {
        printf("\n----------MAIN MENU----------\n");
        printf("\n1.ENQUEUE");
        printf("\n2.DEQUEUE");
        printf("\n3.PEEK");
        printf("\n4.Display");
        printf("\n5.Exit\n");
        printf("\nEnter Choice: ");
        scanf("%d",&n);

        switch(n)
        {
            case 1:{                             //enqueue
                     printf("\nEnter Element: ");
                     scanf("%d",&item);

                     enque(&front,&rear,item);
                     printf("\n%d Added\n",item);
                     break;
                   }

            case 2:{                               //dequeue
                     if(deque(&front,&rear,&item))
                         printf("\n%d Deleted\n",item);
                     break;
                   }

            case 3:{                        //peek
                     if(peek(front,&item))
                         printf("\nPEEK = %d\n",item);
                     break;
                   }

            case 4:{                                 //display
                     printf("\nDispalying Queue............\n");
                     display(front);
                     break;
                   }
            case 5:  break;         //exit
            default: printf("\nWRONG CHOICE\n");
        }

    }while(n!=5);       //end of do-while loop

    printf("\n");
    return 0;
}              //end of program

void enque(node **front,node **rear,int item)       //enqueue
{
    node *new_node=(node*)malloc(sizeof(node));       //memory allocation

    new_node->data=item;
    new_node->next=NULL;

    if(*front==NULL)             //if front is null
    {
        *front=new_node;
        *rear=new_node;
        return;
    }

    (*rear)->next=new_node;
    *rear=new_node;               //update rear

    return;
}               //end of enqueue

int deque(node **front,node **rear,int *item)           //dequeue
{
    if(*front==NULL)           //underflow checking
    {
        printf("\nUNDERFLOW\n");
        return 0;
    }

    node *ptr=*front;

    *item=(*front)->data;

    if(*front==*rear)      //if only 1 node exists
    {
        *front=*rear=NULL;
        free(*front);
        return 1;
    }

    *front=(*front)->next;        //update front
    free(ptr);
    return 1;
}             //end of dequeue

int peek(node *front,int *item)        //peek
{
    if(front==NULL)
    {
        printf("\nQUEUE IS EMPTY\n");
        return 0;
    }

    *item=front->data;

    return 1;
}                //end of peek

void display(node *front)       //display
{
    if(front==NULL)
    {
        printf("\nQUEUE IS EMPTY\n");
        return;
    }

    printf("\n");
    for(;front!=NULL;front=front->next)
        printf("   %d",front->data);       //output

    printf("\n");

    return;
}             //end of display
