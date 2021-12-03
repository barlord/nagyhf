#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct recept {
	char name[20];
	char ossze[15];
	char elkeszit[200];
	int osszcucc;
	struct recept* next;
}Recept;


//lefoglal egy receptnyi helyet �s visszaadja  a pointer�t !!!!!!!!!!!!!!!!!!!MALLOC DE M�Gnem biztos hogy j� a FREE!!!!!!!!!!!!!!!!!
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
/// j� ez de men�, ez megn�zhi ha a head 0 akkor � lesz az els� elem ha nem akkor akkor a neki beadott pointer lesz a k�vetkez� elemre a head;
/// </summary>
/// <param name="head">fajl eleje</param>
/// <param name="e">fajl v�ge pointer k�vire </param>
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
	//megrpob�lom e bet�lteni a receptet
	Recept* head = NULL;
	Recept* e;
	e = create_listelement();

	return e;
}

//stringb�l a spaceket elt�nteti �s visszaad egy �j stringet space n�lk�l
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

//vesz ket chart �s ha ugyanazok 1 et ad vissza k�l�nben 0
int recept_search(const char* keres, Recept* head)
{
	char* mibenkeres = head->ossze;
	int zahl_ossze = 0;
	int  i = 0;
	char* pos;
	int backer = 0;

	//m�sol a tmpbe hogy megtartsam az eredeti �rt�ket
	char tmp[20];
	strcpy(tmp, mibenkeres);
	//darabokra szedem
	char* ktevo = strtok(tmp, ",");

	while (ktevo != NULL)
	{
		if (ktevo[strlen(ktevo) - 1] == '\n') {
			ktevo[strlen(ktevo) - 1] = '\0';
		}
		pos = strstr(keres, ktevo);
		if (pos)
		{
			backer++;
		}
		else
		{
			return 0;
		}

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
	int c; //as getchar() returns `int`
	int i=0;
	string = malloc(sizeof(char)); //allocating memory

	string[0] = '\0';

	while ((c = getchar() )!= '\n')
	{
		string = realloc(string, (i + 2) * sizeof(char));//reallocating memory
		if (string==NULL)
		{
			return NULL;
		}
		string[i] = (char)c; //type casting `int` to `char`
		string[i + 1] = '\0'; //inserting null character at the end
		i++;
	}

	return string;
}
