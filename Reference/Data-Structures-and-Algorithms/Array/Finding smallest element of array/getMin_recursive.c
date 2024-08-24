// Recursive Approach using Divide and Conquer Algorithm


#include <stdio.h>

int min; // declaration of global variable "min"

void getMin(int arr[], int low, int high) {
    int minR;
    if(low == high) {
        min = arr[low];
    }
    else if(high == low+1) {
        if(arr[low] < arr[high]){
            min= arr[low];
        }
        else {
            min= arr[high];
        }
    }
    else {
        int mid = (low + (high-low)/2);
        getMin(arr, low, mid);
        minR = min;
        getMin(arr, mid+1, high);

        if(minR < min) {
            min = minR;
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
    getMin(arr, 0, arr_size-1);
    printf("\n Smallest element of array: %d", min);

    return 0;
}

