// For 'n' disks number of moves= 2^n - 1
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

//       char source, char destination, char helper

void TowerOfHanoi(int no, char rodA, char rodC, char rodB)
{
    if (no == 1)
    {
        printf("Move disk %d from %c to %c\n", no, rodA, rodC);
    }
    else
    {
        TowerOfHanoi(no - 1, rodA, rodB, rodC);
        printf("Move disk %d from %c to %c\n", no, rodA, rodC);
        TowerOfHanoi(no - 1, rodB, rodC, rodA);
    }
}

int main()
{
    int no;

    printf("Enter the number of disks: ");
    scanf("%d", &no);

    TowerOfHanoi(no, 'A', 'C', 'B');

    return 0;
}