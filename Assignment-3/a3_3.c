/*C program to evaluate postfix expression*/

#include<stdio.h>          //Preprocessor Directive
#include<stdlib.h>
#include<ctype.h>
#define MAX 50

typedef struct STACK
{
    int top;
    int st[MAX];
}stack;       //User Defined Datatype

stack stk;

void push(int);        //Function Definition
int pop(void);
int eval_postfix(char[]);

int main()
{
    char s[MAX];int n;
    stk.top=-1;

    printf("Enter a postfix expression: ");
    scanf(" %[^\n]s",s);

    n=eval_postfix(s);

    printf("\nAns: %d\n\n",n);       //Output Result

    return 0;
}

int eval_postfix(char s[])        //Function Definition
{
    int i,n;char a,b;

    for(i=0;s[i]!='\0';i++)
    {
	if(isdigit(s[i]))
	    push(s[i]-'0');
	else if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*'||s[i]=='%')
	{
	    a=pop();b=pop();

	    switch(s[i])
	    {
		case '+': push(b+a);
			  break;
		case '-': push(b-a);
			  break;
		case '/': push(b/a);
			  break;
		case '*': push(b*a);
			  break;
		case '%': push(b%a);
			  break;
	    }
	}
    }

    n=pop();

    return n;
}          //end of eval_postfix

void push(int a)
{
    stk.top=stk.top + 1 ;

    stk.st[stk.top]=a;
}          //end of push

int pop()
{
    int temp;

    temp=stk.st[stk.top];

    stk.top=stk.top - 1;

    return temp;
}             //end of pop
