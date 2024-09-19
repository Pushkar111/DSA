// For 'n' disks number of moves= 2^n - 1
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//                          char source, char helper, char destination

void TowerOfHanoi(int no, char rodA, char rodB, char rodC)
{
    if (no == 1)
    {
        printf("Move disk %d from %c to %c\n", no, rodA, rodC);
    }
    else
    {
        TowerOfHanoi(no - 1, rodA, rodC, rodB);
        printf("Move disk %d from %c to %c\n", no, rodA, rodC);
        TowerOfHanoi(no - 1, rodB, rodA, rodC);
    }
}

int main()
{
    int no;

    printf("Enter the number of disks: ");
    scanf("%d", &no);

    TowerOfHanoi(no, 'A', 'B', 'C');

    return 0;
}