/*C Program to calculate factorial using tail recursion*/

#include<stdio.h>          //Preprocessor Directive

int fact(int);             //Function Declaration
int fact_aux(int,int);

int main()
{
    int n;

    printf("Enter an integer: ");
    scanf("%d",&n);            //Input

    printf("%d! = %d\n",n,fact(n));          //Output

    return 0;
}              //End of program

int fact(int n)         //Function Defition
{
    if(n==0)
        return 1;
    else
        fact_aux(n,1);
}           //End of fact

int fact_aux(int n,int res)      //Function Defition
{
    if(n==1)
        return res;
    else
        return fact_aux(n-1,n*res);         //recursive call
}               //End of fact_aux
