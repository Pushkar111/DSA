#include <stdio.h>
#include <conio.h>
#define SIZE 2

void Create();
void Display();
void DisplayParticular(int id);
int Search(int id);
void Update(int id);
void CalculateGrade(int i);
void del(int id);

struct Student
{
	int sid;
	char name[30];
	float fees;
	float maths, eng, comp, total, per;
	char grade;
	int flag;
} s[SIZE];

void Create()
{
	int i;
	float temp;

	for (i = 0; i < SIZE; i++)
	{
		float temp;

		printf("\nEnter the sid,name,fees,maths,end,comp marks of Student : ");
		scanf("%d", &s[i].sid);
		scanf("%s", s[i].name);
		scanf("%f", &temp);
		s[i].fees = temp;
		scanf("%f", &temp);
		s[i].maths = temp;
		scanf("%f", &temp);
		s[i].eng = temp;
		scanf("%f", &temp);
		s[i].comp = temp;

		CalculateGrade(i);

	} // end of for
} // end of Create

void Display()
{
	int i, id;

	printf("\nSID\tNAME\tFEES\tMATHS\tENG\tCOMP\tTOTAL\tPER\tGRADE");

	for (i = 0; i < SIZE; i++)
	{
		if (s[i].flag != -1)
		{
			printf("\n%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%.2f\t%c", s[i].sid, s[i].name, s[i].fees, s[i].maths, s[i].eng, s[i].comp, s[i].total, s[i].per, s[i].grade);
		}
	}

} // end of Display

void DisplayParticular(int index)
{
	int i;

	if (s[index].flag != -1)
	{
		printf("\nSID\tNAME\tFEES\tMATHS\tENG\tCOMP\tGRADE");
		printf("\n%d\t%s\t%.2f\t%.2f\t%.2f\t%.2f\t%c", s[i].sid, s[i].name, s[i].fees, s[i].maths, s[i].eng, s[i].comp, s[i].grade);
	} // end of if
} // end of DisplayParticular

int Search(int id)
{
	int i;

	for (i = 0; i < SIZE; i++)

	{
		if (s[i].sid == id)
		{
			return i;
		}

	} // end of for

	return -1;

} // end of Search

void CalculateGrade(int i)
{
	s[i].total = s[i].maths + s[i].eng + s[i].comp;

	s[i].per = s[i].total / 3;

	if (s[i].per > 90)
	{
		s[i].grade = 'A';
	}
	else if (s[i].per > 80)
	{
		s[i].grade = 'B';
	}
	else
	{
		s[i].grade = 'C';
	}
} // end of CalculateGrade

void Update(int id)
{
	int choice;
	int index = -1;

	index = Search(id);

	if (index == -1)
	{
		printf("\nRecord not Found !");
	}
	else
	{
		printf("\n1.Maths");
		printf("\n2.English");
		printf("\n3.Computer");
		printf("\n4.Update For All");
		printf("\n5.Exit");

		printf("\nEnter the Choice : ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 1:
			printf("\nEnter the New Marks of Maths : ");
			scanf("%f", &s[index].maths);

			CalculateGrade(index);

			break;

		case 2:
			printf("\nEnter the New Marks of English : ");
			scanf("%f", &s[index].eng);

			CalculateGrade(index);

			break;

		case 3:
			printf("\nEnter the New Marks of Computer : ");
			scanf("%f", &s[index].eng);

			CalculateGrade(index);

			break;

		case 4:
			printf("\nEnter the New Marks of Maths , English & Computer : ");
			scanf("%f", &s[index].maths);
			scanf("%f", &s[index].eng);
			scanf("%f", &s[index].comp);

			CalculateGrade(index);

			break;

		case 5:
			exit(0);
		} // end of switch
	} // end of else
} // end of Update

void del(int id)
{
	int index = -1;

	index = Search(id);

	printf("del = %d", index);
	if (index == -1)
	{
		printf("\nRecord not Found !");
	}
	else
	{
		s[index].flag = -1;
	}
} // end of del

void main()
{
	int i, choice, id, index;
	while (1)
	{
		printf("\n--------------------------------------------");
		printf("\n			Student Management System");
		printf("\n--------------------------------------------");
		printf("\n1.Create");
		printf("\n2.Display");
		printf("\n3.Search");
		printf("\n4.Update");
		printf("\n5.Delete");
		printf("\n6.Exit");
		printf("\n--------------------------------------------");

		printf("\nEnter the Choice : ");
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
			printf("\nEnter the id : ");
			scanf("%d", &id);

			index = Search(id);

			if (index == -1)
			{
				printf("\nRecord not Found !");
			}
			else
			{
				DisplayParticular(index);
			} // end of else
			break;

		case 4:
			printf("\nEnter the id : ");
			scanf("%d", &id);

			Update(id);

			break;

		case 5:
			printf("\nEnter the id : ");
			scanf("%d", &id);

			del(id);

			break;

		case 6:
			exit(0);
		} // end of switch
		getch();
	} // end of while
} // end of main
