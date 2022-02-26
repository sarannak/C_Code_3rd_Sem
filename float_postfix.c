/*C Program to evaluate postfix expression using floating point numbers*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 20

float st[MAX];int top=-1;

float eval_postfix(char[]);

void push(float);
float pop();

int main()
{
    char s[MAX]; float r;

    printf("\nEnter Postfix Expression: ");
    scanf(" %[^\n]s",s);

    r=eval_postfix(s);

    printf("\nAnswer:- %f\n\n",r);

    return 0;
}

float eval_postfix(char s[])
{
    char *t;float a,b;

    t=strtok(s," ");

    while(t!=NULL)
    {
        if(isdigit(t[0]))
            push(atof(t));
        else
        {
            a=pop();b=pop();

            switch(t[0])
            {

                case '+':{
                             push(b+a);
                             break;
                         }

                case '-':{
                             push(b-a);
                             break;
                         }

                case '/':{
                             push(b/a);
                             break;
                         }

                case '*':{
                             push(b*a);
                             break;
                         }

                case '%':{
                             push((int)b%(int)a);
                             break;
                         }

            }   //end of switch
        }   //end of else

        t=strtok(NULL," ");
    }    //end of loop

    return st[top];
}

void push(float n)
{
    if(top==MAX)
    {
        printf("\nOVERFLOW\n");
        return;
    }

    top++;
    st[top]=n;
}

float pop(void)
{
    if(top==-1)
    {
        printf("\nUNDERFLOW\n");
        return -100;
    }

    float temp=st[top];
    top--;
    return temp;
}
