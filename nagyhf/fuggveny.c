#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "fuggveny.h"
#include "data.h"

//lefoglal egy receptnyi helyet és visszaadja  a pointer�t malloc kezelve
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
/// jé ez de menő, ez megnézhi ha a head 0 akkor ő lesz az első elem ha nem akkor akkor a neki beadott pointer lesz a következő elemre a head;
/// </summary>
/// <param name="head">fajl eleje</param>
/// <param name="e">fajl vége pointer k�vire </param>
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

	return e;
}

//stringből a spaceket eltünteti és visszaad egy új stringet space nélkül
char* str_spacedel(char* str)
{
	int i = 0;
	int j = 0;
	while (str[i] != '\0')
	{

		if (str[i] != ' ')
		{
			str[j++] = str[i];

		}
		else
		{
			str[j] = str[i];

		}
		i++;

	}
	str[j] = '\0';
	return str;
}

//vesz ket chart és ha ugyanazok 1 et ad vissza különben 0
int recept_search(const char* keres, Recept* head)
{
	char* mibenkeres =(char*)malloc(sizeof(char)*(strlen(head->ossze)+1));
	strcpy(mibenkeres, head->ossze);
	int zahl_ossze = 0;
	int  i = 0;
	char* pos;
	int backer = 0;

	//darabokra szedem
	char* ktevo = strtok(mibenkeres, ",");

	while (ktevo != NULL)
	{
		//keres a stringben részleteket 
		pos = strstr(keres, ktevo);
		if (pos)
		{
			//szamolja hány összetevőt talált hogy megvan e mind
			backer++;
		}
		else
		{
			//ha van olyan összetevő ami kellen de nincs 0t ad vissza
			return 0;
		}
		//keresett összetevő ,-vel elválasztva
		ktevo = strtok(NULL, ",");
	}
	if (backer < head->osszcucc) {
		return 0;
	}
	return 1;


}

//input tárolása akármilyen hosszra dinamikusan
char* beolvas(char*string)
{
	int c; 
	int i=0;
	string =(char*) malloc(sizeof(char)); 

	string[0] = '\0';

	while ((c = getchar() )!= '\n')
	{
		string = realloc(string, (i + 2) * sizeof(char));
		if (string==NULL)
		{
			return NULL;
		}
		string[i] = (char)c; 
		string[i + 1] = '\0'; 
		i++;
	}

	return string;
}

void delete(Recept* head) {
	Recept* p;
	while (head != NULL) {
		p = head->next; 
		free(head->name);
		free(head->ossze);
		free(head->elkeszit);
		free(head);
		head = p;
	}
	return;
}