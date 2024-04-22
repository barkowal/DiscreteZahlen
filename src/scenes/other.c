#include "other.h"


char otherMenuString[] = " \
  /$$$$$$  /$$$$$$$$ /$$   /$$ /$$$$$$$$ /$$$$$$$  \n\
 /$$__  $$|__  $$__/| $$  | $$| $$_____/| $$__  $$ \n\
| $$  \\ $$   | $$   | $$  | $$| $$      | $$  \\ $$ \n\
| $$  | $$   | $$   | $$$$$$$$| $$$$$   | $$$$$$$/ \n\
| $$  | $$   | $$   | $$__  $$| $$__/   | $$__  $$ \n\
| $$  | $$   | $$   | $$  | $$| $$      | $$  \\ $$ \n\
|  $$$$$$/   | $$   | $$  | $$| $$$$$$$$| $$  | $$ \n\
 \\______/    |__/   |__/  |__/|________/|__/  |__/ \n\
 ";



Menu* otherMenu(){
	const int size = 2;
	char* options[2] = {
		"( )ROZKLAD SILNII",
		"( )WYJDZ"
	};
	Menu* menu;
	char* title = otherMenuString;
	menu = createMenu(menu, size, title, options);
	menu->methods->whatScene = &otherWhatScene;
	menu->methods->changeMenu = &otherChangeMenu;

	return menu;
}


int otherWhatScene(Menu* main, int option){
	switch(option){
		case 0:	return FACTORIAL_SCENE;
		case 1:	return MAIN_SCENE;
		default: return EXIT;
	}
}


Menu* otherChangeMenu(Menu* self, int option){
	Menu* temp;
	switch(option){
		case 0:	
				temp = factorialMenu();
				break;
		case 1: 
				temp = mainMenu();
				break;
		default: 
				temp = mainMenu();
				break;
	}
	return temp;
}

