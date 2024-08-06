/*
Bubble Sort
    Best Case: O(n) [(when the array is already sorted)]
    Average Case: O(n^2)
    Worst Case: O(n^2)

Selection Sort:
    Best Case: 𝑂(𝑛2)
    Average Case: O(n2)
    Worst Case: O(n2)

insertion sort
    Best Case: O(n) [(when the array is already sorted)]
    Average Case: O(n^2)
    Worst Case: O(n^2)

Merge sort
    Time Complexity: T(n) = n logn
*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

#define SIZE 7

// merge sort-1
#define S1 5
#define S2 5
#define S3 S1 + S2

// merge sort-2
#define SIZE_MERGE 10

// 55 87 65 43 45 67 89

int a[SIZE];

// ----------------------------------------------------------------

void scanData()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("\nEnter the value of a[%d] : ", i);
        scanf("%d", &a[i]);
    }
}

void dispData()
{
    int i;
    for (i = 0; i < SIZE; i++)
    {
        printf("%d\t", a[i]);
    }
}

// ----------------------------------------------------------------

void bubbleSort()
{
    int i, j, temp;
    for (i = 0; i < SIZE; i++)
    {
        for (j = 0; j < SIZE - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
        printf("\n\nPass: %d => ", i + 1);
        dispData(); // print the array after each pass
    }
    printf("\n\nSorted Array\n");
    printf("------------------------------------------------------------------------\n");
    dispData();
}

// ----------------------------------------------------------------

void selectionSort()
{
    int i, j, min, temp;

    for (i = 0; i < SIZE; i++)
    {
        min = i;
        for (j = i + 1; j < SIZE; j++)
        {
            if (a[min] > a[j])
            {
                min = j;
            }
        }
        temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        printf("\n\nPass: %d => ", i + 1);
        dispData(); // print array of each pass
    }
    printf("\n\nSorted Array\n");
    printf("------------------------------------------------------------------------\n");
    dispData();
}

// ----------------------------------------------------------------

void insertionSort()
{
    int i, j, temp;
    for (i = 1; i < SIZE; i++)
    {
        temp = a[i];
        for (j = i - 1; j >= 0; j--)
        {
            if (a[j] > temp)
            {
                a[j + 1] = a[j];
            }
            else
            {
                break;
            }
        }
        a[j + 1] = temp;
        printf("\n\nPass: %d => ", i);
        dispData();
    }
    printf("\n\nSorted Array\n");
    printf("------------------------------------------------------------------------\n");
    dispData();
}

// ----------------------------------------------------------------

// mergeSort - 1
void mergeSort1(int a[], int b[], int c[])
{
    int i = 0, j = 0, k = 0;

    while (i < S1 && j < S2)
    {
        if (a[i] < b[j])
        {
            c[k++] = a[i++];
            // k++;
            // i++;
        }
        else
        {
            c[k++] = b[j++];
            // k++;
            // j++;
        }
    }

    while (i < S1)
    {
        c[k++] = a[i++];
        // k++;
        // i++;
    }

    while (j < S2)
    {
        c[k++] = b[j++];
        // k++;
        // j++;
    }
}

void dispMergeSort1(int c[])
{
    for (int i = 0; i < S3; i++)
    {
        printf("%d\t", c[i]);
    }
}
// ----------------------------------------------------------------
// merge sort-2

void merge(int arr[], int min, int mid, int max)
{
    int SIZE1 = mid - min + 1;
    int SIZE2 = max - mid;

    int a[SIZE1];
    int b[SIZE2];

    for (int i = 0; i < SIZE1; i++)
    {
        a[i] = arr[min + i];
    }

    for (int i = 0; i < SIZE2; i++)
    {
        b[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = min;

    while (i < SIZE1 && j < SIZE2)
    {
        if (a[i] < b[i])
        {
            arr[k++] = a[i++];
            // k++;
            // i++;
        }
        else
        {
            arr[k++] = b[j++];
            // k++;
            // j++;
        }
    }

    while (i < SIZE1)
    {
        arr[k++] = a[i++];
        // k++;
        // i++;
    }

    while (j < SIZE2)
    {
        arr[k++] = b[j++];
        // k++;
        // j++;
    }
}

void mergeSort2(int arr[], int min, int max)
{
    if (min < max)
    {
        int mid = (min + max) / 2;
        mergeSort2(arr, min, mid); // first part
        mergeSort2(arr, mid + 1, max);// second part
        merge(arr, min, mid, max);
    }
}

void dispMergeSort2(int arr[])
{
    for (int i = 0; i < SIZE_MERGE; i++)
    {
        printf("%d\t", arr[i]);
    }
}

// ----------------------------------------------------------------
int main()
{

    int choice;
    // merge sort-1
    int a[] = {10, 20, 30, 40, 50};
    int b[] = {1, 2, 3, 4, 5};
    int c[S3];
    // merge sort-2
    int arr[] = {1, 2, 3, 4, 5, 50, 40, 30, 20, 10};
    int min = 0, mid, max = SIZE_MERGE - 1;

    while (1)
    {
        printf("\n---------------------------------------------------------------------------");
        printf("\n                              Sorting                                      ");
        printf("\n---------------------------------------------------------------------------");
        printf("\n1. Bubble Sort");
        printf("\n2. Selection Sort");
        printf("\n3. Insertion Sort");
        printf("\n4. Merge Sort 1");
        printf("\n5. Merge Sort 2");
        printf("\n6. Heap Sort");
        printf("\n7. Quick Sort");
        printf("\n8. Bucket Sort");
        printf("\n9. Exit");
        printf("\n---------------------------------------------------------------------------");

        printf("\nEnter the choice : ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            scanData();

            printf("\nUnSorted Array\n");
            printf("------------------------------------------------------------------------\n");

            dispData();

            bubbleSort();
            break;

        case 2:
            scanData();

            printf("\nUnSorted Array\n");
            printf("------------------------------------------------------------------------\n");

            dispData();

            selectionSort();
            break;

        case 3:
            scanData();

            printf("\nUnSorted Array\n");
            printf("------------------------------------------------------------------------\n");

            dispData();

            insertionSort();
            break;

        case 4:
            mergeSort1(a, b, c);
            printf("\nThe sorted Array is : \n");
            printf("------------------------------------------\n");
            dispMergeSort1(c);
            break;

        case 5:
            mergeSort2(arr, min, max);
            dispMergeSort2(arr);
            break;

        case 6:
            break;

        case 7:
            break;

        case 8:
            break;

        case 9:
            exit(0);
            break;
        }
        getch();
    }
    return 0;
}