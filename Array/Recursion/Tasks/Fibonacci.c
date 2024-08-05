#include <stdio.h>

int fibonacci(int no)
{
    if (no <= 1)
    {
        return no; // Base cases: fibonacci(0) = 0, fibonacci(1) = 1
    }
    else
    {
        return fibonacci(no - 1) + fibonacci(no - 2); // Recursive case
    }
}

int main()
{
    int no;

    printf("Enter the number of terms in the Fibonacci sequence: ");
    scanf("%d", &no);

    printf("\nFibonacci sequence up to %d terms:\n", no);
    printf("------------------------------------------------------------------------------\n");
    for (int i = 0; i < no; i++)
    {
        printf("%d\t", fibonacci(i));
    }
    printf("\n");

    return 0;
}