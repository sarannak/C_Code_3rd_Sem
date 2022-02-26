/*C program to convert infix to postfix expression*/

#include<stdio.h>      //Preprocessor Directive
#include<stdlib.h>
#include<ctype.h>
#define MAX 50

typedef struct STACK
{
    int top;
    char st[MAX];
}stack;            //User Defined Datatype

stack stk;        //Declaring Stack

void push(char);         //Function Declaration
char pop(void);
void infix_postfix(char[],char[]);
int precedence(char);

int main()
{
    char s[MAX],t[MAX];int i;
    stk.top=-1;

    printf("Enter an infix expression: ");
    scanf(" %[^\n]s",s);

    for(i=0;s[i]!='\0';i++);
    s[i++]=')';s[i]='\0';          //adding right parenthesis
    push('(');              //push left parenthesis

    infix_postfix(s,t);

    printf("\nPostfix expression: %s\n\n",t);          //print postfix

    return 0;
}

void infix_postfix(char s[],char t[])
{
    int i,j=0;

    for(i=0;s[i]!='\0';i++)
    {
	if(s[i]=='(')
	    push(s[i]);
	else if(isdigit(s[i])||isalpha(s[i]))
            t[j++]=s[i];
	else if(s[i]==')')
	{
	    while(stk.st[stk.top]!='(')
		t[j++]=pop();
	    pop();
    }
	else if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*'||s[i]=='%'||s[i]=='^')
	{
	    while(stk.st[stk.top]!='('&&precedence(stk.st[stk.top])>=precedence(s[i]))
	        t[j++]=pop();
	    push(s[i]);
	}
    }

    t[j]='\0';

    return;
}

int precedence(char a)     //defining precedence
{
	if(a=='^')
	    return 3;
    if(a=='*'||a=='/'||a=='%')
	    return 2;
    if(a=='+'||a=='-')
	    return 1;
}       //end of precedence

void push(char c)      //push
{
    stk.top=stk.top+1;

    stk.st[stk.top]=c;
}

char pop(void)          //pop
{
    if(stk.top==-1)
    {
	printf("\n\nUNDERFLOW\n\n");
	exit(0);
    }

    char temp=stk.st[stk.top];

    stk.top=stk.top-1;

    return temp;
}
