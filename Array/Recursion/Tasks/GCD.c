// Greatest Common Divisor (GCD)
#include <stdio.h>

// int gcd(int a, int b)
// {
//     while (a != b)
//     {
//         if (a > b)
//         {
//             return gcd(a - b, b);
//         }
//         else
//         {
//             return gcd(a, b - a);
//         }
//     }
// }

/* Recursion Approach */
// -> 2 and 5 GCD
// 2    5
// 5    2
// 2    1
// 1    0

// -> 20 and 12 GCD
// 20   12
// 12   8
// 8    4
// 4    0

// -> 20 and 15 GCD
// 20   15
// 15   5
// 5    0
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    else
    {
        return gcd(b, a % b);
    }
}

int main()
{
    int a, b, ans;

    printf("Enter a : ");
    scanf("%d", &a);
    printf("Enter b : ");
    scanf("%d", &b);

    ans = gcd(a, b);

    printf("GCD : %d", ans);
    return 0;
}