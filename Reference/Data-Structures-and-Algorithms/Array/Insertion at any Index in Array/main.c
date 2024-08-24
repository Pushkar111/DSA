// Write a program to insert a number at a given location in an array.
#include <stdio.h>
#include <conio.h>


//Function to print an array
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf(" %d  ", arr[i]);
    printf("\n");
}


int main()
{
    int i, size, num, pos, arr[10];

    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &size);
    for(i=0; i<size; i++)
    {
        printf("\n arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }
    printf("\n Enter the number to be inserted : ");
    scanf("%d", &num);
    printf("\n Enter the position(index) at which the number has to be added :");
    scanf("%d", &pos);

    for(i = size-1; i >= pos; i--)
        arr[i+1] = arr[i];

    arr[pos] = num;
    size = size +1;
    printf("\n The array after insertion of %d is : ", num);
    printArray( arr, size );

    return 0;

}
