#include<stdio.h>
#include<stdlib.h>
struct Array
{
    int A[10];
    int size;
    int length;
};

int isSorted(struct Array arr)
{
    int i;
    for(i=0;i<arr.length-1;i++)
    {
        if(arr.A[i]>arr.A[i+1])
        return 0;
    }
    return 1;
}
int BinarySearch(struct Array arr,int key)
{
    int l,h,mid;
    l=0;
    h=arr.length-1;
    while(l<=h)
    {
        mid=(l+h)/2;
        if(key==arr.A[mid])
        return mid;
        else if(key<arr.A[mid])
        {
            h=mid-1;
        }
        else
        {
            l=mid+1;
        }
    }
return -1;
}
void Display(struct Array arr)
{
    int i;
    printf("\nElemets are\n");
    for(i=0;i<arr.length;i++)
    {
    printf("%d ",arr.A[i]);
    }
}

int main()
{
    struct Array arr = {{1,33,5,7,13,15,16,18,21,23},10,10};
    if(IsSorted(arr))
    {
    printf("Binary Search Implementation is availabe\n");
    int x =BinarySearch(arr,7);
    if(x!=(-1))
    printf("Element found at index %d\n",x);
    else
    printf("Element not found\n");
    }
    else
    printf("Array not sorted\n");
    
    Display(arr);

}





