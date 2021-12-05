#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "fuggveny.h"
//a receptek adatbazisa
Recept* data(Recept* head)
{
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
	
	return head;
}