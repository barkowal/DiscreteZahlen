#include "mainScene.h"


char menuString[] = " \
/$$      /$$ /$$$$$$$$ /$$   /$$ /$$   /$$\n\
| $$$    /$$$| $$_____/| $$$ | $$| $$  | $$\n\
| $$$$  /$$$$| $$      | $$$$| $$| $$  | $$\n\
| $$ $$/$$ $$| $$$$$   | $$ $$ $$| $$  | $$\n\
| $$  $$$| $$| $$__/   | $$  $$$$| $$  | $$\n\
| $$\\  $ | $$| $$      | $$\\  $$$| $$  | $$\n\
| $$ \\/  | $$| $$$$$$$$| $$ \\  $$|  $$$$$$/\n\
|__/     |__/|________/|__/  \\__/ \\______/ \n";


char* mainGetTitle(){
	return menuString;
}


struct Menu* mainMenu(){
	const int size = 3;
	char* options[3] = {
		"( )POLICZ NWD ORAZ NWW Z ROZKLADEM NA CZYNNIKI PIERWSZE",
		"( )POLICZ NWD ROZSZERZONYM ALGORYTMEM EUKLIDESA",
		"( )WYJDZ"
	};
	struct Menu* menu = createMenu(menu, size, options);
	return menu;
}


int mainWhatScene(int option){
	switch(option){
		case 0:	return NWD_SCENE;
		case 1: return EXTENDEDEUC_SCENE;
		case 2: return EXIT;
		default: return EXIT;
	}
}

