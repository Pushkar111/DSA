#include <stdio.h>

int fact(int n)
{
    if (n == 0 || n == 1)
    {
        return 1;
    }
    else
    {
        return n * fact(n - 1);
    }
}

int main()
{
    int n, ans;
    
    printf("Enter No : ");
    scanf("%d", &n);
    
    ans = fact(n);

    printf("Factorial : %d", ans);
    return 0;
}