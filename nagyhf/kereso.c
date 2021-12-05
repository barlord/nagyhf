#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "fuggveny.h"
#include "data.h"

int main()
{
	char*keresd='\0';
	int nf = 0; //not found
	Recept* head = NULL;
	head=data(head);
	/////majd �t kell rakni m�sik f�ggv�nybe
	//Recept* head = NULL;
	//Recept* tmp = create_list();
	//strcpy(tmp->name, "rantotta");
	//strcpy(tmp->ossze, "tojas,so");
	//strcpy(tmp->elkeszit, "keverd ossze a tojast majd sussd ki");
	//tmp->osszcucc = 2;
	//add_element(&head, tmp);

	//tmp = create_list();
	//strcpy(tmp->name, "limonade");
	//strcpy(tmp->ossze, "viz,cukor");
	//strcpy(tmp->elkeszit, "keverd ossze a vizet es ihatod is");
	//tmp->osszcucc = 2;
	//add_element(&head, tmp);
	//////////
	//// 
	//bek�ri a receptet
	printf("ami van otthon:\n");
	//teszt beolvas dinam
	keresd=beolvas(keresd);
	if (keresd == NULL)
	{
		fprintf(stderr, "FattalERRRORRRR");
		return 0;
	}

	char* natur = str_spacedel(keresd);

	//v�gig megy a list�n �s ki�rja a tal�latokat strcmpvel, ha ninsc tal�lat bad luck...
	for (; head != NULL; head = head->next)
	{
		if (recept_search(keresd, head))
		{
			printf("\n ehez van minden otthon:");
			printf("\n%s", head->name);
			printf("\n%s", head->ossze);
			printf("\n%s", head->elkeszit);
			printf("\n");
			nf++;
		}
	}
	//ha nincs tal�lat
	if (nf == 0)
		printf("bad luck ehes maradsz\n");
	free(head);
	free(keresd);
	return 0;
}