#include <stdio.h>

int sumOfDigit(int no)
{
    if (no == 0)
    {
        return 0; // base case 
    }
    else
    {
        return (no % 10) + sumOfDigit(no / 10); // Recursive case
    }
}

int main()
{
    int no, ans;

    printf("Enter No : ");
    scanf("%d", &no);

    ans = sumOfDigit(no);

    printf("Sum : %d", ans);
    return 0;
}