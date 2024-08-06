#include <stdio.h>

double power(double a, int b)
{
    if (b == 0)
    {
        return 1; // Base case: any number to the power of 0 is 1
    }else if (b > 0)
    { 
        return (a * power(a, b-1)); // Recursive case for positive power
    }else
    {
        return (1/ power(a, -b));   // Recursive case for negative power      
    }
}

int main()
{
    double a, ans;
    int  b;
    
    printf("Enter Base : ");
    scanf("%lf", &a);
    printf("Enter Power : ");
    scanf("%d", &b);

    ans = power(a, b);

    printf("Power : %.2lf", ans);

    return 0;
}