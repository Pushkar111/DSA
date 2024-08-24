/* Q1. Implementation of finding Max and Min
 * using divide and conquer technique? */

#include <stdio.h>

int min, max; // declaration of global variable "min" and "max"

void getMinMax(int arr[], int low, int high)
{
    int minR, maxR;

        // when there is only 1 element in the array.
    if(low == high) {
        min = max = arr[low];
    }

        // when there is only 2 elements in the array.
    else if(low == high-1)
    {
        if(arr[low] < arr[high]) {
            min = arr[low];
            max = arr[high];
        }
        else {
            min = arr[high];
            max = arr[low];
        }
    }

    // when there are more than 2 elements in the array.
    else {
        int mid = (low+(high-low))/2;
        getMinMax(arr, low, mid);
        minR = min;
        maxR = max;
        getMinMax(arr, mid+1, high);
        if(min > minR) {
            min = minR;
        }
        if(max < maxR) {
            max = maxR;
        }
    }
}


// main function
int main()
{
    int arr_size;
    printf("\n Enter the input array size : ");
    scanf("%d", &arr_size);
    int arr[arr_size];
    printf("\n Enter the elements of array :\n");
    for(int i=0; i<arr_size; i++) {
        scanf("%d", &arr[i]);
    }
    getMinMax(arr, 0, arr_size-1);

    printf("\n Minimum element of array : %d", min);
    printf("\n Maximum element of array : %d", max);

    return 0;
}
