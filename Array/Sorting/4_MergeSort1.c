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

void dispData(int c[])
{
    for (int i = 0; i < S3; i++)
    {
        printf("%d\t", c[i]);
    }
}

int main()
{
    int a[] = {10, 20, 30, 40, 50};
    int b[] = {1, 2, 3, 4, 5};
    int c[S3];

/*
=> Proper merge sort

    int a[] = {1, 2, 3, 4, 5, 10, 20, 30, 40, 50};
    int c[S3];

    int min = 0;
    int max = S3;
    int mid;
    mid = (min + max) / 2;

    int a1[mid];
    int a2[S3 - mid];

    for (int i = 0; i < mid; i++)
    {
        a1[i] = a[i];
    }

    for (int i = mid; i < S3; i++)
    {
        a2[i - mid] = a[i];
    }

    printf("\nFirst half : ");
    for (int i = 0; i < S1; i++)
    {
        printf("%d\t", a1[i]);
    }

    printf("\nSecond half : ");
    for (int i = 0; i < S2; i++)
    {
        printf("%d\t", a2[i]);
    }

    mergeSort(a1, a2, c);
    printf("\nThe sorted Array is : \n");
    printf("------------------------------------------\n");
    dispData(c);
*/

    mergeSort(a, b, c);
    printf("\nThe sorted Array is : \n");
    printf("------------------------------------------\n");
    dispData(c);

    return 0;
}