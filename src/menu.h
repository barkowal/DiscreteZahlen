#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Menu{
	int size;
	int currentOption;
	char* options[];
};

struct Menu* createMenu(struct Menu* menu, int size, char* options[]);	
int showMenu(struct Menu*);
void showMenuItem(struct Menu*, int option);

#endif
