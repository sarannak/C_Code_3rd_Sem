/*C Program to implement linear queue using array*/

#include<stdio.h>        //Preprocessor Directive
#include<stdlib.h>
#define MAX 10

typedef struct queue
{
    int front;
    int q[MAX];
    int rear;
}queue;           //User Defined Datatype

queue que;       //queue Declaration
 
void enque(int);          //Function Declaration
int deque(void);
void display(void);

int main()
{
    int n,temp;

    que.front=que.rear=-1;

    do             //Main Menu
    {
        printf("\n---------MAIN MENU----------\n");
        printf("\n1.Enque");
        printf("\n2.Deque");
        printf("\n3.Display");
        printf("\n4.Exit");
        printf("\n\nEnter Choice: ");
        scanf("%d",&n);

        switch(n)
        {
            case 1:{
                     printf("\n\nEnter element: ");
                     scanf("%d",&temp);
                     enque(temp);
                     break;
                   }

            case 2:{
                     temp=deque();
                     printf("\n\n%d Deleted\n\n",temp);
                     break;
                   }

            case 3:{
                     display();
                     break;
                   }

            case 4: break;
            default: printf("\n\nWRONG CHOICE\n\n");
        }
    }while(n!=4);

    printf("\n");

    return 0;
}          //end of program

void enque(int n)     //Enque
{
    if(que.rear==MAX-1)
    {
        printf("\n\nOVERFLOW\n\n");
        exit(0);
    }

    if(que.front==-1&&que.rear==-1)
    {
        que.front=que.front+1;
        que.rear=que.rear+1;
    }
    else
    {
        que.rear=que.rear+1;
    }

    que.q[que.rear]=n;

    return;
}            //End of enque

int deque(void)    //Deque
{
    if(que.front>que.rear||que.front==-1)
    {
        printf("\n\nUNDERFLOW\n\n");
        exit(0);
    }

    int temp=que.q[que.front];

    que.front=que.front+1;

    return temp;
}            //end of deque

void display(void)          //display
{
    if(que.front>que.rear||que.front==-1)
    {
        printf("\n\nQUEUE IS EMPTY\n\n");
        exit(0);
    }

    int i;

    printf("\n\nDisplaying QUEUE:-\n\n");
    for(i=que.front;i<=que.rear;i++)
        printf("%d\n",que.q[i]);

    return;
}               //end of display
