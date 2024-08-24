// program to enter n numbers in an array.
// Redisplay the array with elements being sorted in ascending order.

// Bubble Sort method (With improved Time Complexity).

#include <stdio.h>
#include <stdlib.h>


// function for Bubble Sort(With improved Time Complexity!)
void BubbleSort(int arr[], int size)
{
    int i, j, temp, flag = 0;
    for(i=0; i<size; i++)
    {
        for(j=0; j<size-i-1; j++)
        {
            if(arr[j]>arr[j+1])
            {
                flag = 1;
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
        if(flag == 0) // array is already sorted
        {
            printf("\n Array is already Sorted!!");
            exit(0);
        }
    }

    printf("\n The array Sorted in ascending order is :\n");
    for (i = 0; i < size; i++)
        printf(" %d\t", arr[i]);

}


// main function
int main()
{
    int i, size, arr[10];

    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &size);
    printf("\n Enter the elements: ");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    // function bubble sorting(with improved Time Complexity)
    BubbleSort(arr, size);

    return 0;
}
