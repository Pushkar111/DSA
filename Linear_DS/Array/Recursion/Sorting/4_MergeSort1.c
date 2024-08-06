#include <stdio.h>
#define S1 5
#define S2 5
#define S3 S1 + S2

void mergeSort(int a[], int b[], int c[])
{
    int i = 0, j = 0, k = 0;

    while (i < S1 && j < S2)
    {
        if (a[i] < b[j])
        {
            c[k++] = a[i++];
            // i++;
            // k++;
        }
        else
        {
            c[k++] = b[j++];
            // j++;
            // k++;
        }
    }

    while (i < S1)
    {
        c[k++] = a[i++];
        // i++;
        // k++;
    }

    while (j < S2)
    {
        c[k++] = b[j++];
        // j++;
        // k++;
    }
}

void dispData(int c[], int SIZE)
{
    for (int i = 0; i < SIZE; i++)
    {
        printf("%d\t", c[i]);
    }
}

int main()
{
    // int a[] = {10, 20, 30, 40, 50};
    // int b[] = {1, 2, 3, 4, 5};
    // int c[S3];

    // =>  merge sort-1

             // min                 mid         max
    int arr[] = {10, 20, 30, 40, 50, 1, 2, 3, 4, 5};
    int c[S3];

    int min = 0;
    int max = S3;
    int mid;
    mid = (min + max) / 2;

    int a[mid];
    int b[S3 - mid];

    for (int i = 0; i < mid; i++)
    {
        a[i] = arr[i];
    }

    for (int i = mid; i < S3; i++)
    {
        b[i - mid] = arr[i];
    }

    printf("\nFirst half : ");
    printf("\n--------------------------------------------------------------------------------------\n");
    dispData(a, S1);

    printf("\nSecond half : ");
    printf("\n--------------------------------------------------------------------------------------\n");
    dispData(b, S2);

    mergeSort(a, b, c);
    printf("\nThe sorted Array is : ");
    printf("\n--------------------------------------------------------------------------------------\n");
    dispData(c, S3);

    // mergeSort(a, b, c);
    // printf("\nThe sorted Array is : \n");
    // printf("--------------------------------------------------------------------------------------\n");
    // dispData(c, S3);

    return 0;
}