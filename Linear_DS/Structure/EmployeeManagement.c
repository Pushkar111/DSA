#include <stdio.h>
#include <stdlib.h>
#define SIZE 2

void Create();
void Display();
void DisplayParticular(int id);
int Search(int id);
void Update(int id);
void del(int id);

struct Employee
{
    int eid;
    char name[30];
    float salary;
    char department[30];
    int flag;
} e[SIZE];

void Create()
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        printf("\nEnter the eid, name, salary, department of Employee: ");
        scanf("%d", &e[i].eid);
        scanf("%s", e[i].name);
        scanf("%f", &e[i].salary);
        scanf("%s", e[i].department);
        e[i].flag = 0;
    }
}

void Display()
{
    int i;

    printf("\nEID\tNAME\tSALARY\tDEPARTMENT");

    for (i = 0; i < SIZE; i++)
    {
        if (e[i].flag != -1)
        {
            printf("\n%d\t%s\t%.2f\t%s", e[i].eid, e[i].name, e[i].salary, e[i].department);
        }
    }
}

void DisplayParticular(int index)
{
    if (e[index].flag != -1)
    {
        printf("\nEID\tNAME\tSALARY\tDEPARTMENT");
        printf("\n%d\t%s\t%.2f\t%s", e[index].eid, e[index].name, e[index].salary, e[index].department);
    }
}

int Search(int id)
{
    int i;

    for (i = 0; i < SIZE; i++)
    {
        if (e[i].eid == id)
        {
            return i;
        }
    }
    return -1;
}

void Update(int id)
{
    int choice;
    int index = -1;

    index = Search(id);

    if (index == -1)
    {
        printf("\nRecord not Found!");
    }
    else
    {
        printf("\n1. Name");
        printf("\n2. Salary");
        printf("\n3. Department");
        printf("\n4. Update All");
        printf("\n5. Exit");

        printf("\nEnter the Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("\nEnter the New Name: ");
            scanf("%s", e[index].name);
            break;

        case 2:
            printf("\nEnter the New Salary: ");
            scanf("%f", &e[index].salary);
            break;

        case 3:
            printf("\nEnter the New Department: ");
            scanf("%s", e[index].department);
            break;

        case 4:
            printf("\nEnter the New Name, Salary & Department: ");
            scanf("%s", e[index].name);
            scanf("%f", &e[index].salary);
            scanf("%s", e[index].department);
            break;

        case 5:
            exit(0);
        }
    }
}

void del(int id)
{
    int index = -1;

    index = Search(id);

    if (index == -1)
    {
        printf("\nRecord not Found!");
    }
    else
    {
        e[index].flag = -1;
    }
}

int main()
{
    int choice, id, index;
    while (1)
    {
        printf("\n============================================================");
        printf("\n        Employee Management System");
        printf("\n============================================================");
        printf("\n1. Create");
        printf("\n2. Display");
        printf("\n3. Search");
        printf("\n4. Update");
        printf("\n5. Delete");
        printf("\n6. Exit");
        printf("\n============================================================");

        printf("\nEnter the Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            Create();
            break;

        case 2:
            Display();
            break;

        case 3:
            printf("\nEnter the id: ");
            scanf("%d", &id);

            index = Search(id);

            if (index == -1)
            {
                printf("\nRecord not Found!");
            }
            else
            {
                DisplayParticular(index);
            }
            break;

        case 4:
            printf("\nEnter the id: ");
            scanf("%d", &id);

            Update(id);
            break;

        case 5:
            printf("\nEnter the id: ");
            scanf("%d", &id);

            del(id);
            break;

        case 6:
            exit(0);
        }
    }
    return 0;
}
