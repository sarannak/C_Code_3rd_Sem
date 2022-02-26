/*C program to implement stack*/

#include<stdio.h>   //Preprocessor Direcitve
#include<stdlib.h>
#define MAX 50

typedef struct STACK 
{
  int st[MAX];
  int top;
}stack;        //User Defined datatype

void push(stack*,int);       //Function Declaration
int pop(stack*);
int peek(stack*);
void display(stack*);

int main()
{
    stack stk;      //Declaraing stack type variable
    stk.top=-1;

    int n,k;

    do                     //Main Menu
    {
	    printf("\n\n------MAIN MENU-------");
	    printf("\n1.PUSH");
	    printf("\n2.POP");
        printf("\n3.PEEK");
	    printf("\n4.Display Stack");
	    printf("\n5.Exit");
	    printf("\n\nEnter Choice: ");
	    scanf("%d",&n);

	switch(n)
	{
	    case 1:{
			printf("\nEnter Value: ");
			scanf("%d",&k);
			push(&stk,k);
			break;
		   }

	    case 2:{
			printf("\nPOP = %d\n",pop(&stk));
			break;
		   }

	    case 3:{
			printf("\nPEEK = %d\n",peek(&stk));
			break;
		   }

	    case 4:{
			display(&stk);
			break;
		   }

	    case 5: break;

	    default:    printf("\n\nWRONG CHOICE\n\n");
	}

    }while(n!=5);

    return 0;
}           //end of program

void push(stack *stk,int a)     //Function Definition
{
    if(stk->top==MAX)
    {
	printf("\n\nOVERFLOW\n\n");
	exit(0);
    }
    stk->top=(stk->top)+1;

    stk->st[stk->top] = a;
}        //end of push

int pop(stack *stk)        //POP Operation
{
    if(stk->top==-1)
    {
	printf("\n\nUNDERFLOW\n\n");
	exit(0);
    }
    int temp = stk->st[stk->top];

    stk->top=(stk->top)-1;

    return temp;
}        //end of pop

int peek(stack *stk)           //PEEK Operation
{
    return stk->st[stk->top];
}        //end of peek

void display(stack *stk)      //Display Operation
{
    if(stk->top==-1)
    {
	printf("\n\nUNDERFLOW\n\n");
	exit(0);
    }
    int i=stk->top;

    printf("\nDiplaying Stack.......\n\n");

    for(;i>=0;i--)
	printf("%d\n",stk->st[i]);

    printf("\n");
}          //end of display
