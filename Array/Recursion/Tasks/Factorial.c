#include <stdio.h>

int fact(int no)
{
    if (no == 1)
    {
        return 1;
    }
    else
    {
        return no * fact(no - 1);
    }
}

int main()
{
    int no, ans;
    
    printf("Enter No : ");
    scanf("%d", &no);
    
    ans = fact(no);

    printf("Factorial : %d", ans);
    return 0;
}