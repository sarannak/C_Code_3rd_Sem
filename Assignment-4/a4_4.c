/*C Program to find x to the power n using recursion*/

#include<stdio.h>          //Preprocessor Directive

float power(float,int);       //Funciton Declaration

int main()
{
    int x,n;          //variable declaration

    printf("\n---------x^n---------\n");
    printf("\nEnter x: ");
    scanf("%d",&x);         //input
    printf("Enter n: ");
    scanf("%d",&n);         //input

    printf("\n%d^%d = %0.2f\n\n",x,n,power((float)x,n)); //output
    return 0;
}             //End of Program

float power(float x,int n)
{
    float p=1;

    if(n==0)        //base case
        return 1;
    if(n<0)                       //negative exponent part
        return power(1.0/x,-n);
    if(n%2==1)
        p=x;                       //if n is odd

    p=p*power(x*x,n/2);             //recursive call
    return p;
}             //end of power function
