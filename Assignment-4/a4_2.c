/*C Program to display fibonacci series*/

#include<stdio.h>        //Preprocessor Directive

int fibo(int);         //Function Prototype

int main()
{
    int n,i;

    printf("\nEnter no. of terms: ");
    scanf("%d",&n);          //Input

    printf("\nFibonacci series of %d terms:\n",n);
    for(i=0;i<n;i++)
        printf("  %d",fibo(i));        //Output
    printf("\n\n");

    return 0;
}             //End of Program

int fibo(int n)
{
    if(n==0)              //Base case
        return 0;
    else if(n==1||n==2)       //Base Case
        return 1;
    else
        return (fibo(n-1)+fibo(n-2));   //Binary Recursion
}            //End of Fibo Function
