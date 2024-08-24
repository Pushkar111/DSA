#include <stdio.h>
#include <stdlib.h>

// function to perform Selection Sort
void selectionSort(int arr[], int n) {
    int minIndex, temp;
    for(int i = 0; i < n; i++) {
        minIndex = i;
        for(int j = i + 1; j < n; j++) {
            if(arr[minIndex] > arr[j]) {
                minIndex = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }

    for(int i = 0; i < n; i++) {
        printf("  %d\t", arr[i]);
    }
    printf("\n");
}


// main function
int main() {
    int n;
    printf("\n Enter the number of Elements : ");
    scanf("%d", &n);
    int arr[n];
    printf("\n Enter the elements to be sorted :\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("\n Sorted Elements :\n");
    selectionSort(arr, n);
    return 0;
}

