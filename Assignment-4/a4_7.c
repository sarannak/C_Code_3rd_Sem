/*C Program to Calculate nCk using recursion*/

#include<stdio.h>           //Preprocessor Directive

int nck(int,int);             //Function Declaration

int main()
{
    int n,k;           //Variable Declaration

    printf("\n-----------nCk----------\n");
    printf("\nEnter n: ");
    scanf("%d",&n);          //Input
    printf("Enter k: ");
    scanf("%d",&k);           //Input

    printf("\n%dC%d = %d\n\n",n,k,nck(n,k));    //Output

    return 0;
}                //End of Program

int nck(int n,int k)             //Function Definition
{
    if(k==0)                 //Base Condition
        return 1;
    else
        return(n/k)*nck(n,k-1);         //Recursive Call
}                  //End of nck
