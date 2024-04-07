#include "menu.h"

struct Menu* createMenu(Menu* menu, int size, char* title, char* options[]){
	int i;
	int arrayLen = 0;
	MenuVtable* methods = createVtable();
	for(i=0;i<size;i++){
		 arrayLen += (sizeof(char) * strlen(options[i]) + 1);
	}

	menu = malloc(sizeof(*menu) + arrayLen + sizeof(MenuVtable));

	for(i=0;i<size;i++){
		menu->options[i] = malloc(sizeof(char) * strlen(options[i]) + 1);
	}

	menu->size = size;
	menu->currentOption = 0;
	menu->methods = methods;
	menu->title = strdup(title);

	for(i=0; i<size; i++)
	 	strcpy(menu->options[i], options[i]);
	
	return menu;
}


MenuVtable* createVtable(){

	MenuVtable* vtable;
	vtable = malloc(sizeof(MenuVtable));
	vtable->showMenu = &showMenu;
	vtable->getTitle = &getTitle;
	vtable->whatScene = &nextScene;
	vtable->destroyMenu = &destroyMenu;
	vtable->showMenuItem = &showMenuItem;
	vtable->changeMenu = &changeMenu;

	return vtable;
}


char* getTitle(Menu* self){
	return self->title;
}


int showMenu(Menu* menu){
	printf("Wybierz co chcesz zrobic\n");
	int i;
	for(i=0; i<menu->size; i++){
		printf("%s \n",menu->options[i]);
	}
	return menu->size;
}


void showMenuItem(Menu* menu, int option){
	if(option < menu->size){
		printf("%s", menu->options[option]);
		menu->currentOption = option;
	}
}


int nextScene(Menu* self, int option){
	return 1;
}


Menu* changeMenu(Menu* self, int option){
	Menu* temp = NULL;
	return temp;
}

void destroyMenu(Menu** menu){
	int i;
	for(i=0 ;i<(*menu)->size; i++)
		free( (	(*menu)->options[i] ));

	free((*menu)->title);
	free((*menu)->methods);
	free(*menu);
	*menu = NULL;
}
