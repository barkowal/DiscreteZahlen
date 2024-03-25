#include "menu.h"

struct Menu* createMenu(struct Menu* menu, int size, char* options[]){
	menu = malloc(sizeof(*menu));

	int i;
	for(i=0;i<size;i++){
		menu->options[i] = malloc(sizeof(char) * strlen(options[i]));
	}

	menu->size = size;
	menu->currentOption = 0;

	for(i=0; i<size; i++)
	 	strcpy(menu->options[i], options[i]);

	return menu;
}

int showMenu(struct Menu* menu){
	printf("Wybierz co chcesz zrobic\n");
	int i;
	for(i=0; i<menu->size; i++){
		printf("%s \n",menu->options[i]);
	}
	return menu->size;
}

void showMenuItem(struct Menu* menu, int option){
	if(option < menu->size){
		printf("%s", menu->options[option]);
		menu->currentOption = option;
	}
}

