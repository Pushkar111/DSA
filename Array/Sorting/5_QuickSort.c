#include <stdio.h>

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

int partition(int arr[], int min, int max)
{
    int pivot = arr[max];
    int i = min - 1;
    for (int j = min; j <= max - 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, max);

    return i + 1;
}

void QuickSort(int arr[], int min, int max)
{
    if (min < max)
    {
        int pi = partition(arr, min, max);
        QuickSort(arr, min, pi - 1);
        QuickSort(arr, pi + 1, max);
    }
}

void dispData(int arr[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t", arr[i]);
    }
}

int main()
{
    int arr[] = {11, 122, 31, 4, 115, 600, 700, 85, 91, 100};
    int SIZE = sizeof(arr) / sizeof(int);
    int min = 0, mid, max = SIZE - 1;

    printf("\nUnsorted array : ");
    printf("\n--------------------------------------------------------------------------------------\n");
    dispData(arr, SIZE);

    // Quick Sort
    QuickSort(arr, min, max);
    printf("\n\nsorted array : ");
    printf("\n-------------------------------------------------------------------------------------\n");
    dispData(arr, SIZE);
    return 0;
}