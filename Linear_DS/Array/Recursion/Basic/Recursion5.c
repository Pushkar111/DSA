// Write a c program for if count = 5 then print => 5,4,3,2,1
// if count = 2 then print => 2,1

#include <stdio.h>

void printData(int count)
{
    if (count > 0)
    {
        printf("\n%d", count);
        printData(--count); // count - 1
    }
}

int main()
{

    printData(5);

    return 0;
}