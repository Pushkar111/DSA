// program to merge two unsorted arrays.
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

    int arr1[10], arr2[10], arr3[20];
    int i, n1, n2, m, index=0;

    printf("\n Enter the number of elements in array1 : ");
    scanf("%d", &n1);
    printf("\n\n Enter the elements of the first array");
    for(i=0; i<n1; i++) {
        printf("\n arr1[%d] = ", i);
        scanf("%d", &arr1[i]);
    }
    printf("\n Elements of 1st Array is : ");
    printArray(arr1, n1);
    printf("\n Enter the number of elements in array2 : ");
    scanf("%d", &n2);
    printf("\n\n Enter the elements of the second array");
    for(i=0; i<n2; i++) {
        printf("\n arr2[%d] = ", i);
        scanf("%d", &arr2[i]);
    }
    printf("\n Elements of 2nd Array is : ");
    printArray(arr2, n2);
    m = n1+n2;
    for(i=0; i<n1; i++) {
        arr3[index] = arr1[i];
        index++;
    }
    for(i=0;i<n2;i++) {
        arr3[index] = arr2[i];
        index++;
    }
    printf("\n\n The merged array is : ");
    printArray(arr3, m);
    return 0;

}
