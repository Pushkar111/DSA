// program to calculate the factorial of a given number
// using RECURSION Method

#include <stdio.h>

int Factorial(int); // FUNCTION DECLARATION


int main()
{
    int num, val;
    printf("\n Enter the number: ");
    scanf("%d", &num);
    val = Fact(num);
    printf("\n Factorial of %d = %d", num, val);
    return 0;
}


// function for finding Factorial of a given no.
int Factorial(int n)
{
    if(n==1)
        return 1;
    else
        return (n * Factorial(n-1));
}
