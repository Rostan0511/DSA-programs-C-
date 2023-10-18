#include<stdio.h>
void swap(int *x,int *y)
{
    int temp=*x;
    *x=*y;
    *y=temp;
}
void Bubble(int A[],int n)
{
    int i,j,flag=0;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1-i;j++)
        {
            if(A[j]>A[j+1])
            {
                swap(&A[j],&A[j+1]);
            }
        }
        if(flag==0)
        break;
    }
}
int main()
{
    int A[]={7,3,5,6,8,4,9,11,18,13},n=10,i;
    Bubble(A,n);
    printf("\nElements are:\n");
    for(i=0;i<n-1;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
    return 0;
}