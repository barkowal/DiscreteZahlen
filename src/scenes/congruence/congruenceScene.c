#include "congruenceScene.h"

char congruenceTitle[] = "\
  /$$$$$$  /$$$$$$ /$$   /$$ /$$$$$$ /$$$$$$$ /$$   /$$/$$$$$$$$/$$   /$$ /$$$$$$ /$$$$$$$$\n\
 /$$__  $$/$$__  $| $$$ | $$/$$__  $| $$__  $| $$  | $| $$_____| $$$ | $$/$$__  $| $$_____/\n\
| $$  \\__| $$  \\ $| $$$$| $| $$  \\__| $$  \\ $| $$  | $| $$     | $$$$| $| $$  \\__| $$      \n\
| $$     | $$  | $| $$ $$ $| $$ /$$$| $$$$$$$| $$  | $| $$$$$  | $$ $$ $| $$     | $$$$$   \n\
| $$     | $$  | $| $$  $$$| $$|_  $| $$__  $| $$  | $| $$__/  | $$  $$$| $$     | $$__/   \n\
| $$    $| $$  | $| $$\\  $$| $$  \\ $| $$  \\ $| $$  | $| $$     | $$\\  $$| $$    $| $$      \n\
|  $$$$$$|  $$$$$$| $$ \\  $|  $$$$$$| $$  | $|  $$$$$$| $$$$$$$| $$ \\  $|  $$$$$$| $$$$$$$$\n\
 \\______/ \\______/|__/  \\__/\\______/|__/  |__/\\______/|________|__/  \\__/\\______/|________/\n\
";

Menu* congruenceMenu(){
	const int size = 2;
	char* options[2] = {
		"( )Chinskie twierdzenie o resztach",
		"( )POWROT"
	};
	char* title = congruenceTitle;
	struct Menu* menu = createMenu(menu, size, title, options);
	menu->methods->whatScene = &congruenceNextScene;
	menu->methods->changeMenu = &congruenceChangeMenu;
	return menu;
}

int congruenceNextScene(Menu* self, int option){
	switch(option){
		case 0:
				return SUNZITHEOREM_SCENE;
		case 1:
				return MAIN_SCENE;
		default:
				return MAIN_SCENE;
	}
}

Menu* congruenceChangeMenu(Menu* self, int option){
	Menu* temp;
	switch(option){
		case 0:
				temp = sunziTheoremMenu();
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



