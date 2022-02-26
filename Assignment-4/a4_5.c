/*C Program to solve tower of hanoi problem using recursion*/

#include<stdio.h>         //Preprocessor Directive

void tower(int,int,int,int);    //Function Declaration

int main()
{
    int n;

    printf("\nEnter no. of discs: ");
    scanf("%d",&n);           //Input

    printf("Moves:\n");

    tower(n,1,2,3);    //function call

    return 0;
}          //End of Program

void tower(int n,int fr,int to,int spr)
{
    if(n==1)                           //Base case
    {
        printf("Move from %d to %d\n",fr,to);
        return;
    }
    else
    {
        tower(n-1,fr,spr,to);
        tower(1,fr,to,spr);
        tower(n-1,spr,to,fr);
    }
}                  //end of tower function
