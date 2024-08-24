// Iterative-Approach


#include <stdio.h>

void getMax(int *, int);

int main() {
    int arr_size;
    printf("\n Enter the size of input array: ");
    scanf("%d", &arr_size);
    int arr[arr_size];
    printf("\n Enter the elements of array:\n");
    for(int i=0; i<arr_size; i++) {
        scanf("%d", &arr[i]);
    }
    getMax(arr, arr_size);

    return 0;
}

void getMax(int arr[], int arr_size) {
    int max=arr[0];
    for(int i=1; i<arr_size; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
    }
    printf("\n Maximum element of array: %d", max);
}
