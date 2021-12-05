#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include "fuggveny.h"
//a receptek adatbazisa
Recept* data(Recept* head)
{
	Recept* tmp = create_listelement();
	tmp->name= (char*)malloc(sizeof(char) * (strlen("rántotta") + 1));
	strcpy(tmp->name, "rántotta");
	tmp->ossze =(char*)malloc(sizeof(char)*(strlen("tojás,só")+1));
	strcpy(tmp->ossze, "tojás,só");
	tmp->elkeszit = (char*)malloc(sizeof(char) * (strlen("keverd össze a tojást majd süssd ki") + 1));
	strcpy(tmp->elkeszit, "keverd össze a tojást majd süssd ki");
	//nagyon fontos hogy hány elem van benne, ha a user is rakhatna be ide adatot ,-k száma+1 lenne ez
	tmp->osszcucc = 2;
	add_element(&head, tmp);

	tmp = create_listelement();
	tmp->name = (char*)malloc(sizeof(char) * (strlen("limonádé") + 1));
	strcpy(tmp->name, "limonádé");
	tmp->ossze = (char*)malloc(sizeof(char)*(strlen("víz,cukor,citrom")+1));
	strcpy(tmp->ossze, "víz,cukor,citrom");
	tmp->elkeszit = (char*)malloc(sizeof(char) * (strlen("keverd össze a vízet es ihatod is") + 1));
	strcpy(tmp->elkeszit, "keverd össze a vízet es ihatod is");
	tmp->osszcucc = 3;
	add_element(&head, tmp);


	tmp = create_listelement();
	tmp->name = (char*)malloc(sizeof(char) * (strlen("lekvaros turó") + 1));
	strcpy(tmp->name, "lekváros turó");
	tmp->ossze = (char*)malloc(sizeof(char) * (strlen("lekvár,turó") + 1));
	strcpy(tmp->ossze, "lekvár,turó");
	tmp->elkeszit = (char*)malloc(sizeof(char) * (strlen("keverd ossze a turot es a lekvárt und eheted is") + 1));
	strcpy(tmp->elkeszit, "keverd ossze a turot es a lekvárt und eheted is");
	tmp->osszcucc = 2;
	add_element(&head, tmp);
	
	return head;
}