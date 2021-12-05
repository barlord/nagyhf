#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "fuggveny.h"
#include "data.h"
#include <locale.h>
#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
	//magyar betük csak windowson
	SetConsoleCP(1250);
	SetConsoleOutputCP(1250);

	char*keresd='\0';
	int nf = 0; //not found
	int t = 0;//találatok száma
	Recept* head = NULL;
	
	head=data(head);
	
	printf("ami van otthon:\n");
	// beolvas dinam
	keresd=beolvas(keresd);

	//error kezelés
	if (keresd == NULL)
	{
		fprintf(stderr, "FattalERRRORRRR");
		return 0;
	}

	char* natur = str_spacedel(keresd);
	//végig megy a listán és kiírja a találatokat strcmpvel, ha ninsc találat bad luck...
	for (; head != NULL; head = head->next)
	{

		if (recept_search(keresd, head))
		{
			if (t == 0)
			printf("\n ehez van minden otthon:");
			if(t!=0)
			{ 
				printf("\n ehez is van minden otthon:");
			}
			printf("\n%s", head->name);
			printf("\n%s", head->ossze);
			printf("\n%s", head->elkeszit);
			printf("\n");
			nf++;
			t++;
		}
	}
	//ha nincs találat
	if (nf == 0)
		printf("bad luck ehes maradsz\n");
	//mallococ free
	delete(head);
	free(head);
	free(keresd);
	return 0;
}