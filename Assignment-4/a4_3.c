/*C Program to calculate GCD using recursion*/

#include<stdio.h>   //Preprocessor Directive

int gcd(int,int);

int main()
{
    int a,b;

    printf("\nEnter a: ");
    scanf("%d",&a);        //input
    printf("Enter b: ");
    scanf("%d",&b);         //input

    printf("\nGCD of %d and %d = %d\n\n",a,b,gcd(a,b));   //output

    return 0;
}                 //End of program

int gcd(int a,int b)             //function definition
{
    if(a%b==0)             //base case
        return b;
    else
        return gcd(b,a%b);            //recursive call
}         //end of gcd function
