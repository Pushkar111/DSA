// For 'n' disks number of moves= 2^n - 1
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//                          char source, char helper, char destination

void TowerOfHanoi(int n, char rodA, char rodB, char rodC)
{
    if (n == 1)
    {
        printf("Move disk %d from %c to %c\n", n, rodA, rodC);
    }
    else
    {
        TowerOfHanoi(n - 1, rodA, rodC, rodB);
        printf("Move disk %d from %c to %c\n", n, rodA, rodC);
        TowerOfHanoi(n - 1, rodB, rodA, rodC);
    }
}

int main()
{
    int n;

    printf("Enter the number of disks: ");
    scanf("%d", &n);

    TowerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}