#include <stdio.h>
#include <stdlib.h>
typedef struct receptd {
	char name[20];
	char ossze[10];
	char elkeszit[200];
	struct receptd* next;
} Receptd;

//lefoglal egy receptnyi helyet és visszaadja  a pointerét
Receptd* create_listelement()
{
	Receptd* p;
	p = (Receptd*)malloc(sizeof(Receptd));
	if (p == NULL)
	{
		printf("malloc error");
		exit(1);
	}
	p->next = NULL;
	return p;
}

/// <summary>
/// jé ez de menõ, ez megnézhi ha a head 0 akkor õ lesz az elsõ elem ha nem akkor akkor a neki beadott pointer lesz a következõ elemre a head;
/// </summary>
/// <param name="head">fajl eleje</param>
/// <param name="e">fajl vége pointer kövire </param>
void add_element(Receptd** head, Receptd* e) {
	Receptd* p;
	if (*head == NULL) {
		
		*head = e;
		return;
	}
	for (p = *head; p->next != NULL; p = p->next) {
	}
	
	p->next = e; 
	return;
}

void create_list()
{
	//megrpobálom e betölteni a receptet
	Receptd* head = NULL;
	Receptd* e;
	e = create_listelement();
	strcpy_s(e->name, 20, "rantotta");
	strcpy_s(e->ossze, 10, "tojas");
	strcpy_s(e->elkeszit, 200, "keverd ossze a tojast majd süssd ki");
	printf("\nneve:\t%s\n osszetevok:%s \n Recept:\n%s",e->name,e->ossze,e->elkeszit);
	
}