#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "fuggveny.h"


int main()
{
	char keres[20], caller[20];
	int nf = 0; //not found
	///majd �t kell rakni m�sik f�ggv�nybe
	Recept* head = NULL;
	Recept* tmp = create_list();
	strcpy(tmp->name, "rantotta");
	strcpy(tmp->ossze, "tojas,so");
	strcpy(tmp->elkeszit, "keverd ossze a tojast majd sussd ki");
	tmp->osszcucc = 2;
	add_element(&head, tmp);

	tmp = create_list();
	strcpy(tmp->name, "limonade");
	strcpy(tmp->ossze, "viz,cukor");
	strcpy(tmp->elkeszit, "keverd ossze a vizet es ihatod is");
	tmp->osszcucc = 2;
	add_element(&head, tmp);
	////////
	// 
	//bek�ri a receptet
	printf("ami van otthon:\n");
	fgets(keres, 15, stdin);
	char* natur = str_spacedel(keres);

	//v�gig megy a list�n �s ki�rja a tal�latokat strcmpvel, ha ninsc tal�lat bad luck...
	for (; head != NULL; head = head->next)
	{
		strcpy(caller, natur);
		if (recept_search(caller, head))
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
	return 0;
}