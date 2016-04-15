// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdio.h"
#include "stdlib.h"
#include "time.h"

void openfile();
void closefile();

FILE *fptr;


void main()
{

	int accountID[100];
	int accBal[100];
	int i = 0;
	float max = 60000;
	float min = -5000;
	int range = (max - min) + 1;
	srand(time(NULL));

	openfile();

	while (i < 100)
	{
		int r = min + int((range*rand()) / (RAND_MAX + 1.0));
		fprintf(fptr, "%d\t", i + 1);
		fprintf(fptr, "%.2d\n", r);
		i++;
	}

	closefile();

	fptr = fopen("F:\\Accounts.txt", "r");
	while (i < 100)
	{
		fscanf(fptr, "%d\t%d\n", &accountID[i], &accBal[i]);
		i++;
	}
	closefile();

	i = 0;
	while (i < 100)
	{
		printf("%d\t%d\n\n", accountID[i], accBal[i]);
		i++;
	}

	while (i < 100)
	{
		if (accBal[i] < 0)
		{
			printf("ID no.:%d\t Bal.:%d", accountID[i], accBal[i]);
		}
		i++;
	}
}

void openfile()
{
	fptr = fopen("F:\\Accounts.txt", "w");
	if (fptr == NULL)
	{
		printf("Error opening file \n");
	}
}

void closefile()
{
	fclose(fptr);
}