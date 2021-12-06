#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "fuggveny.h"
#ifdef _WIN32
#include <windows.h>
#endif

//a receptek adatbazisa



Recept* data(Recept* head)
{
	
		SetConsoleCP(1250);
		SetConsoleOutputCP(1250);
		FILE* file;
		Recept* tmp = create_listelement();
		Recept dp;
		int c=0;
		char* string = (char*)malloc(sizeof(char) * 1);
		int i = 0, j;
		file = fopen("data.txt", "r");
		if (file == NULL)
		{
			fprintf(stderr, "\nFILEFATALerror'\n");
			exit(1);
		}
		while (c !=EOF)
		{
			for (j = 0; j < 4; j++)
			{
				i = 0;
				while (((c = fgetc(file)) != ';')&&(c!=EOF))
				{
					if (j == 3)
					{
						if (c == '\n')
							continue;
					}
					string = realloc(string, (i + 2) * sizeof(char));
					if (string == NULL)
					{
						fprintf(stderr, "\nmallocFATALerror'\n");
						exit(1);
					}
					string[i] = (char)c;
					string[i + 1] = '\0';
					i++;
				}

				if (j == 0)
				{
					dp.name = malloc(sizeof(char) * (strlen(string) + 1));
					strcpy(dp.name, string);
				}
				if (j == 1)
				{
					dp.ossze = malloc(sizeof(char) * (strlen(string) + 1));
					strcpy(dp.ossze, string);
				}
				if (j == 2)
				{
					dp.elkeszit = malloc(sizeof(char) * (strlen(string) + 1));
					strcpy(dp.elkeszit, string);
				}
				if (j == 3)
				{
					dp.osszcucc = atoi(string);
				}
				fgetc(file);
			}
			tmp = create_listelement();
			tmp->name = (char*)malloc(sizeof(char) * (strlen(dp.name) + 1));
			strcpy(tmp->name, dp.name);
			tmp->ossze = (char*)malloc(sizeof(char) * (strlen(dp.ossze) + 1));
			strcpy(tmp->ossze, dp.ossze);
			tmp->elkeszit = (char*)malloc(sizeof(char) * (strlen(dp.elkeszit) + 1));
			strcpy(tmp->elkeszit, dp.elkeszit);
			tmp->osszcucc = dp.osszcucc;
			add_element(&head, tmp);

		}
		fclose(file);
	return head;
}
//"tojás,só,cukor,vaj, liszt, sütőpor, csoki"
