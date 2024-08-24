// program to search an element in an array using interpolation search.
// used for Sorted Array
#include <stdio.h>
#include <conio.h>

#define MAX 20

// function for Interpolation Search - used for Sorted Array
int interpolation_search(int a[], int low, int high, int val)
{
    int mid;
    while(low <= high)
    {
        mid = low + (high - low)*((val - a[low]) / (a[high] - a[low]));
        if(val == a[mid])
            return mid;
        if(val < a[mid])
            high = mid - 1;
        else
        low = mid + 1;
    }
    return -1;
}


// main function
int main()
{
    int arr[MAX], i, n, val, pos;

    printf("\n Enter the number of elements in the array : ");
    scanf("%d", &n);
    printf("\n Enter the elements : ");
    for(i = 0; i <n; i++)
        scanf("%d", &arr[i]);
    printf("\n Elements of the Array are: ");
    for(i=0; i<n; i++)
        printf(" %d ", arr[i]);

    printf("\n\n Enter the value to be searched : ");
    scanf("%d", &val);

    pos = interpolation_search(arr, 0, n-1, val);
    if(pos == -1)
        printf("\n %d is not found in the array", val);
    else
        printf("\n %d is found at position %d", val, pos);

    return 0;

}
