
typedef struct recept {
	char* name;
	char* ossze;

	char* elkeszit;
	int osszcucc;
	struct recept* next;
}Recept;

Recept* create_listelement();
void add_element(Recept** head, Recept* e);
Recept* create_list();
char* str_spacedel(char* str);
int recept_search(const char* keres, Recept* head);
char* beolvas(char* string);
void delete(Recept* head);