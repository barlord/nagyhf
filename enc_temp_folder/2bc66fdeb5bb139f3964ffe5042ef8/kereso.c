#include <stdio.h>
#include <string.h>

typedef struct recept {
	char name[20];
	char ossze[15];
	char elkeszit[200];
	struct recept* next;
}Recept;


//lefoglal egy receptnyi helyet és visszaadja  a pointerét !!!!!!!!!!!!!!!!!!!MALLOC DE MÉG NINCS FREE!!!!!!!!!!!!!!!!!
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
	
	return e;
}

//stringbõl a spaceket eltünteti és visszaad egy új stringet space nélkül
char* str_spacedel(char* str)
{
	int i = 0;
	int j = 0;
	while (str[i] != '\0')
	{
		
		if (str[i] != ' ')
		{
			str[j++] = str[i ];

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
	char keres[15];
	int nf = 0; //not found
	///majd át kell rakni másik függvénybe
	Recept* head = NULL;
	Recept* tmp=create_list();
	strcpy_s(tmp->name, 20, "rantotta");
	strcpy_s(tmp->ossze, 15, "tojas");
	strcpy_s(tmp->elkeszit, 200, "keverd ossze a tojast majd süssd ki");
	add_element(&head,tmp);

	 tmp = create_list();
	strcpy_s(tmp->name, 20, "limonade");
	strcpy_s(tmp->ossze, 15, "viz, cukor");
	strcpy_s(tmp->elkeszit, 200, "keverd ossze a vizet es ihatod is");
	add_element(&head, tmp);
	////////
	// 
	//bekéri a receptet
	printf("ami van otthon:\n");
	gets(&keres,15,stdin);
	char* natur = str_spacedel(keres);
	
	//végig megy a listán és kiírja a találatokat strcmpvel, ha ninsc találat bad luck...
	for (; head!=NULL; head=head->next)
	{
		if (recept_search(natur, str_spacedel(head->ossze)))
		{
		printf("\n ehez van minden otthon:");
		printf("\n%s", head->name);
		printf("\n%s", head->ossze);
		printf("\n%s", head->elkeszit);
		nf++;
		}
		
	}
	//ha nincs találat
	if(nf==0)
	printf("bad luck ehes maradsz");
	free(head);
	printf("\n%s", head->elkeszit);
		return 0;
}