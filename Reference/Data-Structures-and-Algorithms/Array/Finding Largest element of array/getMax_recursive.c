// Recursive Approach using Divide and Conquer Algorithm


#include <stdio.h>

int max; // declaration of global variable "max"

void getMax(int arr[], int low, int high) {
    int maxR;
    if(low == high) {
        max = arr[low];
    }
    else if(high == low+1) {
        if(arr[low] > arr[high]){
            max= arr[low];
        }
        else {
            max= arr[high];
        }
    }
    else {
        int mid = (low + (high-low)/2);
        getMax(arr, low, mid);
        maxR = max;
        getMax(arr, mid+1, high);

        if(maxR > max) {
            max = maxR;
        }
    }
}


int main() {
    int arr_size;
    printf("\n Enter the size of input array: ");
    scanf("%d", &arr_size);
    int arr[arr_size];
    printf("\n Enter the elements of array:\n");
    for(int i=0; i<arr_size; i++) {
        scanf("%d", &arr[i]);
    }
    getMax(arr, 0, arr_size-1);
    printf("\n Largest element of array: %d", max);

    return 0;
}
