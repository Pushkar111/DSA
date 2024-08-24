// program to search an element in an array
// using the Binary Search technique.(used for "sorted Arrays")

#include <stdio.h>


//Function to print the array
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}


void binarySearch(int arr[], int size, int key)
{
    int low, high, mid;
    low=0;
    high=size-1;

    while(low <= high) {
        mid = (low + high) / 2;

        if(key == arr[mid]) {
            printf("\n %d is found at  index-%d of the Array.", key, mid);
            break;
        }
        else if(key < arr[mid]) {
            high = mid-1;
        }
        else { // else if(key > arr[mid])
            low = mid+1;
        }
    }
}


// main function
int main()
{
    int i, size, key;

    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &size);
    int arr[size]; // declaring the array

    printf("\n Enter the elements in Sorted order(Ascending Order) :\n");
    for(i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("\n Entered array is : ");
    printArray( arr, size);

    printf("\n\n Enter the number that has to be searched : ");
    scanf("%d", &key);

    binarySearch(arr, size, key);

    return 0;
}
