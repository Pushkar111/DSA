// Quick-Sort program

#include <stdio.h>
#include <malloc.h>


void QuickSort(int A[], int low, int high);
int Partition(int A[], int low, int high);
void swap(int *a, int *b);
void printArray(int arr[], int size);


// function for Quick-Sort
// A – input array, p is the lower limit of A and q is the higher limit of A
void QuickSort(int A[], int low, int high)
{
    if (low < high) // If there are more than one element
    {
        int p = Partition(A, low, high);

        // call the merge sort on first half of the elements of A
        QuickSort(A, low, p-1);

        // call the merge sort on second half of the elements of A
        QuickSort(A, p+1, high);

    }

}



// function for partitioning of Array
// A – input array, low – lower index, high – higher index
int Partition(int A[], int low, int high)
{
    int pivot = A[low], left = low, right = high;

    while(left < right) {
        while( left < high && A[left] <= pivot) {
            left = left+1;
        }
        while( right > low && A[right] > pivot) {
            right = right-1;
        }
        if(left < right) {
            swap(&A[left], &A[right]);
        }
    }
    swap(&A[low], &A[right]);
    return right;
}


// A utility function to swap two elements
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


/* Function to print an array */
void printArray(int A[], int size)
{
    for ( int i=0; i < size; i++)
        printf(" %d\t", A[i]);
    printf("\n");
}


// main function
int main()
{
    int size;
    printf("\n Enter the no. of elements in Array : ");
    scanf("%d", &size);

    int A[size];
    int low=0;
    int high=size-1;

    printf("\n Enter the elements of the Array :\n");
    for(int i=0; i<size; i++){
        scanf("%d", &A[i]);
    }

    QuickSort(A, low, high);
    printf("\n Sorted Array is :\n");
    printArray(A, size);

    free(A);
    return 0;
}
