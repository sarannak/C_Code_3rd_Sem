/*C Program to implement linked stack*/

#include<stdio.h>              //Preprocessor Directive
#include<stdlib.h>

typedef struct node        //defining node
{
    int data;
    struct node *next;
}node;

void push(node**,int);          //function declaration
int pop(node**,int*);
int peek(node**,int*);
void display(node*);

int main()
{
    int n,item;node *top=NULL;        //variable declaration

    do                //Main Menu
    {
        printf("\n----------MAIN MENU----------\n");
        printf("\n1.PUSH");
        printf("\n2.POP");
        printf("\n3.PEEK");
        printf("\n4.Display");
        printf("\n5.Exit\n");
        printf("\nEnter Choice: ");
        scanf("%d",&n);

        switch(n)
        {
            case 1:{                              //PUSH
                     printf("\nEnter Element: ");
                     scanf("%d",&item);

                     push(&top,item);
                     printf("\n%d Added\n",item);

                     break;
                   }

            case 2:{                            //POP
                     if(pop(&top,&item))
                         printf("\n%d deleted\n",item);
                     break;
                   }

            case 3:{                           //PEEK
                     if(peek(&top,&item))
                         printf("\nPEEK = %d\n",item);
                     break;
                   }

            case 4:{                           //DISPLAY
                     printf("\nDisplaying Stack.........\n");
                     display(top);
                     break;
                   }

            case 5: break;             //Exit
            default: printf("\nWRONG CHOICE\n");
        }
    }while(n!=5);

    printf("\n");

    return 0;
}            //end of program

void push(node **top,int item)             //push
{
    node *new_node=(node*)malloc(sizeof(node));    //memory alloction
    new_node->data=item;

    if(*top==NULL)           //if stack is empty
    {
        *top=new_node;
        new_node->next=NULL;
    }
    else                    //otherwise
    {
        new_node->next=*top;
        *top=new_node;
    }

    return;
}              //End of Push

int pop(node **top,int *item)       //Pop
{
    if(*top==NULL)
    {
        printf("\nUNDERFLOW\n");
        return 0;
    }

    node *ptr=*top;

    *item=(*top)->data;
    (*top)=(*top)->next;         //update top
    free(ptr);

    return 1;
}          //End of pop

int peek(node **top,int *item)       //peek
{
    if(*top==NULL)
    {
        printf("\nSTACK IS EMPTY\n");
        return 0;
    }

    *item=(*top)->data;        //assignment

    return 1;
}                    //end of peek

void display(node *top)           //display
{
    if(top==NULL)
    {
        printf("\nSTACK IS EMPTY\n");
        return;
    }

    for(;top!=NULL;top=top->next)
        printf("\n%d",top->data); //output
    printf("\n");
    return;
}               //end of display
