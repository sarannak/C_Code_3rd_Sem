/*C program display 3 tuple form of a sparse matrix*/

#include<stdio.h>
#define row 50
#define col 50

int three_tuple(int[][col],int,int,int[][3]);   //Fucntion Declaration

int main()
{
    int sparse[row][col],t[50][3],i,j,m,n,m1;

    printf("Enter no. of rows and cols of a sparse matrix:\n");
    scanf("%d%d",&m,&n);

    printf("Enter elements of the sparse matrix:\n");
    for(i=0;i<m;i++)
    {
	for(j=0;j<n;j++)
	{
	    printf("a%d%d=",i+1,j+1);
	    scanf("%d",&sparse[i][j]);    //Input sparse matrix
	}
    }

    m1=three_tuple(sparse,m,n,t);    //Fucntion call

    printf("\nDisplaying 3 tuple form:\n");
    for(i=0;i<m1;i++)
    {
	for(j=0;j<3;j++)
	    printf("   %d",t[i][j]);    //Printing 3-tuple form
	printf("\n");
    }

    printf("\n");

    return 0;
}      //End of program

int three_tuple(int sparse[][col],int m,int n,int t[][3])   //Fucntion Definition
{
    int i,j,k=1;

    for(i=0;i<m;i++)
    {
	for(j=0;j<n;j++)
	{
	    if(sparse[i][j]>0)
	    {
		t[k][0]=i+1;
		t[k][1]=j+1;
		t[k][2]=sparse[i][j];
		k++;
	    }
	}
    }
    k=k-1;

    t[0][0]=i;
    t[0][1]=j;
    t[0][2]=k;

    return k+1;   //returning no. of rows of 3 tuple form
}      //End of function
