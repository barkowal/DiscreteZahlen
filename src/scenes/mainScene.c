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


Menu* mainMenu(){
	const int size = 4;
	char* options[4] = {
		"( )POLICZ NWD ORAZ NWW Z ROZKLADEM NA CZYNNIKI PIERWSZE",
		"( )POLICZ NWD ROZSZERZONYM ALGORYTMEM EUKLIDESA",
		"( )KONGRUENCJE",
		"( )WYJDZ"
	};
	Menu* menu;
	char* title = menuString;
	menu = createMenu(menu, size, title, options);
	menu->methods->whatScene = &mainWhatScene;
	menu->methods->changeMenu = &mainChangeMenu;

	return menu;
}


int mainWhatScene(Menu* main, int option){
	switch(option){
		case 0:	return NWD_SCENE;
		case 1: return EXTENDEDEUC_SCENE;
		case 2: return CONGRUENCES_SCENE;
		case 3: return EXIT;
		default: return EXIT;
	}
}


Menu* mainChangeMenu(Menu* self, int option){
	Menu* temp;
	switch(option){
		case 0:	
				temp = nwdMenu();
				break;
		case 1: 
				temp = extEucMenu();
				break;
		case 2: 
				temp = congruenceMenu();
				break;
		case 3: 
				temp = mainMenu();
				break;
		default: 
				temp = mainMenu();
				break;
	}
	return temp;
}

