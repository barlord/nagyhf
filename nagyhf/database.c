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
	//nagyon fontos hogy hány elem van benne, ha a user is rakhatna be ide adatot ,-k száma+1
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

	tmp = create_listelement();
	tmp->name = (char*)malloc(sizeof(char) * (strlen("amerikai csokis keksz") + 1));
	strcpy(tmp->name, "amerikai csokis keksz");
	tmp->ossze = (char*)malloc(sizeof(char) * (strlen("tojás,só,cukor,vaj,liszt,sütőpor,csoki") + 1));
	strcpy(tmp->ossze, "tojás,só,cukor,vaj,liszt,sütőpor,csoki");
	tmp->elkeszit = (char*)malloc(sizeof(char) * (strlen("A tojást elkeverjük a cukorral és a csipet sóval, aztán jöhet a vaj. \n Jól össze kell keverni. A darabokra tört csokit is hozzátesszük, és összekeverjük. \n A lisztbe belekeverjük a sütőport, majd hozzáadagoljuk a maszához. \n Golyókat gyúrunk és a sütőpapíros tepsin kicsit lenyomkodjuk. Kb. 160 fokon kell sütni, minimum 15 percig. Sütés után hagyni kell kihűlni. ") + 1));
	strcpy(tmp->elkeszit, "A tojást elkeverjük a cukorral és a csipet sóval, aztán jöhet a vaj. \n Jól össze kell keverni. A darabokra tört csokit is hozzátesszük, és összekeverjük. \n A lisztbe belekeverjük a sütőport, majd hozzáadagoljuk a maszához. \n Golyókat gyúrunk és a sütőpapíros tepsin kicsit lenyomkodjuk. Kb. 160 fokon kell sütni, minimum 15 percig. Sütés után hagyni kell kihűlni. ");
	tmp->osszcucc = 7;
	add_element(&head, tmp);
	
	return head;
}
//"tojás,só,cukor,vaj, liszt, sütőpor, csoki"