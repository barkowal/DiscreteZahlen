#ifndef MENU_H
#define MENU_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct MenuVtable MenuVtable;
typedef struct Menu Menu;

struct MenuVtable{
	int (*showMenu)(Menu* self);
	void (*showMenuItem)(Menu* self, int option);
	void (*destroyMenu)(Menu** self);
	char* (*getTitle)(Menu* self);
	int (*whatScene)(Menu* self, int option);
	Menu* (*changeMenu)(Menu* self, int option);
};

struct Menu{
	int size;
	int currentOption;
	MenuVtable* methods;
	char* title;
	char* options[];
};

Menu* createMenu(Menu* self, int size, char* title, char* options[]);	
MenuVtable* createVtable();
char* getTitle(Menu* self);
int showMenu(Menu* self);
void showMenuItem(Menu* self, int option);
int nextScene(Menu* self, int option);
Menu* changeMenu(Menu* self, int optiion);
void destroyMenu(Menu** self);

#endif
