#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


#define MAX 20
int countCharOccurence(char *string, char c);
int nwords = 0;
char dictionary[80000][20];


int main()
{
	FILE *fptr;
	char fileName[] = "C:\\webster.txt";

	fptr = fopen(fileName, "r");

	if (fptr == NULL)
	{
		printf("File could not be opened !!\n");
	}
	else
	{
		while (!feof(fptr))
		{

			fscanf(fptr, "%s\n", dictionary[nwords]);
			nwords++;
		}
		fclose(fptr);
	}

	printf("%ld words read from file \n\n", nwords);

	char vowels[5] = { 'a', 'e', 'i', 'o', 'u' };
	char consonants[21] = { 'b','c','d','f','g','h','j','k','l','m','n','p','q','r','s','t','v','w','x','y','z' };
	char response[MAX];

	srand(time(NULL));
	puts("Enter a string of up to 20 v's <vowels> and c's <consonants> [E.g. vccvvcccvvcc]");
	puts("Enter 'quit' to exit");

	scanf("%s", response);

	while (strcmp(response, "quit") != 0)
	{

		int length = strlen(response);
		int i = 0;

		for (i = 0; i<length; i++)					//Generate random vowels and consonants
		{
			int randomVowel = rand() % 5;

			if (response[i] == 'v' || response[i] == 'V')
			{
				response[i] = vowels[randomVowel];
			}
			else if (response[i] == 'c' || response[i] == 'C')
			{
				int randomCon = rand() % 22;
				response[i] = consonants[randomCon];
			}
			else
			{
				printf("\nInvalid input, please enter a string of v's and c's\n\n");		//error handling
				return 0;
			}
		}

		printf("\nYour Letters are:\n%s\n\n", response);

		char bestFit[20];			//finding the best match for the generated string
		int numMatches = 0;
		int highestMatch = 0;
		int j = 0, len = 0;
		int tempCount = 0, wordCount = 0;

		for (i = 0; i < nwords; i++)
		{
			numMatches = 0;
			len = strlen(dictionary[i]);

			for (j = 0; j < len; j++)
			{
				tempCount = 0;
				wordCount = 0;
				tempCount = countCharOccurence(response, dictionary[i][j]);
				wordCount = countCharOccurence(dictionary[i], dictionary[i][j]);

				if ((tempCount > 0) && (tempCount == wordCount))
				{
					numMatches = numMatches + 1;
				}
				else
				{
					numMatches = 0;
					break;
				}
			}

			if (numMatches > highestMatch)
			{
				strcpy(bestFit, dictionary[i]);
				highestMatch = numMatches;
			}
		}

		int k = 0;
		int h = 0;
		char longest[20];
		printf("Enter the longest word you see: \n\n");			//allows user to input the longest word he sees
		fflush(stdin);
		scanf("%s", longest);

		for (k = 0; k < nwords; k++)							//Spell Checking
		{
				if (!strcmp(longest, dictionary[k]))
				{
					puts("Well Done that word is there!\n");
				}
		
		}



		printf("\n\nBest Fit for -%s- is -%s- \t[%d]\n\n", response, bestFit, highestMatch);	//Lets user know of the longest word in his string
		printf("================================================================================\n\n");

		puts("Enter a string of up to 20 v's <vowels> and c's <consonants> [E.g. vccvvcccvvcc]");
		puts("Enter 'quit' to exit");
		scanf("%s", response);
	}
	return 0;
}

int countCharOccurence(char *string, char c)
{
	int i = 0, count = 0, len = 0;
	len = strlen(string);
	for (i = 0; i<len; i++)
	{
		if (string[i] == c) count++;
	}
	return count;
}