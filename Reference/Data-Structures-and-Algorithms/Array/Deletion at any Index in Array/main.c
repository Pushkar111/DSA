// program to delete a number from a given location in an array.
#include <stdio.h>
#include <conio.h>


//Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("  %d  ", arr[i]);
    printf("\n");
}


// main function
int main()
{
    int i, size, pos, arr[10];

    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &size);
    for(i=0; i<size; i++)
    {
        printf("\n arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("\nEnter the position(index) from which the number has to be deleted : ");
    scanf("%d", &pos);
    for(i=pos; i<size-1; i++)
        arr[i] = arr[i+1];
    size = size-1;
    printf("\n The array after deletion is : ");
    printArray(arr, size);

    return 0;
}