/*C Program to implement circular queue using array*/

#include<stdio.h>        //Preprocessor Directive
#define MAX 5

typedef struct queue
{
    int front;
    int q[MAX];
    int rear;
}queue;                //User Defined Datatype

queue que;int count=0;       //Global Declaration

void enque(int);         //Function Declaration
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
}              //End of program

void enque(int n)              //enque
{
    if(count==MAX)
    {
        printf("\n\nOVERFLOW\n\n");
        return;
    }

    if(que.front==-1&&que.rear==-1)
    {
        que.front=que.front+1;
        que.rear=que.rear+1;
    }
    else
    {
        que.rear=(que.rear+1)%MAX;    //updation of rear
    }

    que.q[que.rear]=n;
    count++;

    return;
}              //end of enque

int deque(void)            //deque
{
    if(count==0)
    {
        printf("\n\nUNDERFLOW\n\n");
        return 0;
    }

    int temp=que.q[que.front];

    que.front=(que.front+1)%MAX;        //updation of front
    count--;

    return temp;
}                //end of deque

void display(void)             //display
{
    if(count==0)
    {
        printf("\n\nQUEUE IS EMPTY\n\n");
        return;
    }

    int i,j;

    printf("\n\nDisplaying QUEUE:-\n\n");
    for(i=que.front,j=1;j<=count;i++,j++)
    {
        if(i==MAX)
            i=0;
        printf("%d\n",que.q[i]);
    }

    return;
}                   //end of display
