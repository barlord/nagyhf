#include <stdio.h>
#include <string.h>

typedef struct recept {
	char name[20];
	char ossze[10];
	char elkeszit[200];
	struct recept* next;
}Recept;
//lefoglal egy receptnyi helyet és visszaadja  a pointerét
Recept* create_listelement()
{
	Recept* p;
	p = (Recept*)malloc(sizeof(Recept));
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
void add_element(Recept** head, Recept* e) {
	Recept* p;
	if (*head == NULL) {

		*head = e;
		return;
	}
	for (p = *head; p->next != NULL; p = p->next) {
	}

	p->next = e;
	return;
}

Recept* create_list()
{
	//megrpobálom e betölteni a receptet
	Recept* head = NULL;
	Recept* e;
	e = create_listelement();
	strcpy_s(e->name, 20, "rantotta");
	strcpy_s(e->ossze, 10, "tojas");
	strcpy_s(e->elkeszit, 200, "keverd ossze a tojast majd süssd ki");
	//printf("\nneve:\t%s\n osszetevok:%s \n Recept:\n%s", e->name, e->ossze, e->elkeszit);
	return e;
}
//vesz ket chart és ha ugyanazok 1 et ad vissza különben 0
int recept_search(const char* keres, const char* mibenkeres)
{

	if(strcmp(keres,mibenkeres)==0)
	{
		return 1;
	}
	return 0;

}

int main()
{	
	//nem müködik a create list
	char keres[10];
	Recept* rantotta=create_list();

	
	
	//bekéri a receptet
	printf("ami van otthon:\n");
	scanf_s("%s", &keres,10);
	if (recept_search(keres, rantotta->ossze))
	{
		printf("\n ehez van minden otthon:");
		printf("\n%s", rantotta->name);
		printf("\n%s", rantotta->ossze);
		printf("\n%s", rantotta->elkeszit);
	}
	else
	{
		printf("bad luck ehes maradsz");
	}

		return 0;
}