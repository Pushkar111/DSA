// Write a c program for if count = 5 then print => 1,2,3,4,5

#include <stdio.h>

void printData(int count)
{
    if (count == 0)
    {
        return;
    }
    printData(count-1);
    printf("\n%d", count);
}

int main()
{

    printData(5);
    return 0;
}