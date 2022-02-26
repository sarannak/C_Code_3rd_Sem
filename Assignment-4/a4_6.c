/*C Program to Solve N Queen Problem using recursion through backtracking*/

#include<stdio.h>          //Preprocessor Directive
#include<math.h>
#include<stdlib.h>
#define MAX 10

void queen(int[],int,int);          //Function Definition
int place(int[],int,int,int);

void display(int[],int);       //Function of Box Display
void printdash(int);

int main()
{
    int a[MAX],n;

    printf("Enter no. of queens: ");
    scanf("%d",&n);

    printf("\n-------NON ATTACKING %d QUEEN PROBLEM--------\n",n);

    queen(a,n,0);          //Function call

    return 0;
}           //End of Program

void queen(int a[],int n,int row)
{
    int col;

    for(col=0;col<n;col++)             //Backtracking
    {
        if(place(a,n,row,col))
        {
            a[row]=col;
            if(row==n-1)
                display(a,n);
            else
                queen(a,n,row+1);
        }
    }

    return;
}               //End of queen function

int place(int a[],int n,int row,int col)
{
    int i,j;

    for(i=0;i<row;i++)
    {
        if(abs(row-i)==abs(col-a[i]))
            return 0;
        if(a[i]==col)
            return 0;
    }

    return 1;
}         //End of Place function

void display(int a[],int n)
{
    int i,j;

    printdash(n);

    for(i=0;i<n;i++)
    {   
        for(j=0;j<n;j++)
        {
            printf("|");
            if(a[i]==j)
                printf("  Q");
            else
                printf("   ");
        }
        printf("|");
        printdash(n);
    }

    printf("\n");

    exit(0);
}            //End of display function

void printdash(int n)
{
    int i;

    printf("\n");
    for(i=1;i<=n;i++)
        printf(" ---");
    printf("\n");

    return;
}               //End of printdash function
