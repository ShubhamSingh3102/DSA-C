#include<stdio.h>
void printArray(int* A,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
void BubbleSort(int *A,int n)
{
    int temp;
    for(int i=0;i<n-1;i++)//For number of passes
    {
        for(int j=0;j<n-1-i;j++)//For comparison in each pass
        {
            if(A[j]>A[j+1])
            {
               temp=A[j];
               A[j]=A[j+1];
               A[j+1]=temp;
            }
        }
    }
}
void BubbleSortAdaptive(int *A,int n)
{
    int temp;
    int isSorted=0; //not sorted
    for(int i=0;i<n-1;i++)//For number of passes
    {
        printf("Working on pass number %d\n",i+1);
        isSorted=1; //already sorted
        for(int j=0;j<n-1-i;j++)//For comparison in each pass
        {
            if(A[j]>A[j+1])
            {
               temp=A[j];
               A[j]=A[j+1];
               A[j+1]=temp;
               isSorted=0;
            }
        }
        if(isSorted)
        {
            return;
        }
    }
}
int main()
{
    // int A[]={12,54,65,7,23,9};
    int A[]={2,1,3,4,5,6};
    int n=6;
    printArray(A,n);
    BubbleSort(A,n);
    printArray(A,n);
    BubbleSortAdaptive(A,n);
    printArray(A,n);
    return 0;
}