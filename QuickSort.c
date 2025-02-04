#include <stdio.h>
void printArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
int Partition(int *A, int low, int high)
{
    int pivot = A[low];
    int i = low + 1;
    int j = high;
    int temp;

    do
    {
        while (A[i] <= pivot) // pivot se baara element chahiye
        {
            i++;
        }
        while (A[j] > pivot) // pivot se chota element chahiye
        {
            j--;
        }

        if (i < j)
        {
            temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
    } while (i < j);

    //Swapping A[low] with A[j]
    temp = A[low];
    A[low] = A[j];
    A[j] = temp;
    return j;
}
void QuickSort(int *A, int low, int high)
{
    int PartitionIndex; // Index of pivot after partition
    if (low < high)
    {
        PartitionIndex = Partition(A, low, high);
        // printArray(A,5);
        QuickSort(A, low, PartitionIndex - 1);  // Quick sort for left subarray
        QuickSort(A, PartitionIndex + 1, high); // Quick sort for right subarray
    }
}
int main()
{
    //int A[] = {3, 5, 2, 13, 12, 3, 2, 13, 45};

    // 3, 5, 2, 13, 12, 3, 2, 13, 45
    // 3, 2, 2, 13i, 12, 3j, 5, 13, 45
    // 3, 2, 2, 3j, 12i, 13, 5, 13, 45 --> first call to partition returns 3
    int A[] = {6, 2, 8, 4, 10};
    int n = 5;
    printArray(A, n);
    QuickSort(A, 0, n - 1);
    printArray(A, n);
    return 0;
}