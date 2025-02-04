#include<stdio.h>
void printArray(int* A,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
void Merging(int *A,int mid,int low,int high)
{
    int i,j,k,B[high+1];
    i=low;
    j=mid+1;
    k=low;
    while(i<=mid && j<=high)
    {
        if(A[i]<A[j])
        {
            B[k]=A[i];
            i++;
            k++;
        }
        else
        {
            B[k]=A[j];
            j++;
            k++;
        }
    }
    //Copying all remaining elements from A to C
    while(i<=mid)
    {
        B[k]=A[i];
        k++;
        i++;
    }
    //Copying all remaining elements from B to C
    while(j<=high)
    {
        B[k]=A[j];
        k++;
        j++;
    }
    //Copying all elements back to A from B
    for(int i=low;i<=high;i++)
    {
        A[i]=B[i];
    }
}
void MergeSort(int *A,int low,int high)
{
    int mid;
    if(low<high)
    {
        mid= (low+high)/2;
        MergeSort(A,low,mid);
        MergeSort(A,mid+1,high);
        Merging(A,mid,low,high);
    }
}
int main()
{
    int A[]={7,9,18,19,22,1,6,11};
    int n=8;
    printArray(A,n);
    MergeSort(A,0,7);
    printArray(A,n);
    return 0;
}
