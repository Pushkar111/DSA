// write c Program to perform Linear search using Recursion

#include <stdio.h>

int linearSearch(int a[],int SIZE, int key)
{
    if (SIZE == 0)
    {
        return 0;
    }
    
    if (a[SIZE - 1] == key)
    {
        return 1;
    }
    
    return linearSearch(a,SIZE-1, key);

}

int main()
{
    int SIZE = 5;
    int a[] = {1, 2, 3, 4, 5};
    int key = 3, ans;

    ans = linearSearch(a, SIZE, key);
    printf("%d", ans);

    return 0;
}