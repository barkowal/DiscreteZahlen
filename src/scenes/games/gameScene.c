#include "gameScene.h"


char gameString[] = " \
  /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$  /$$$$$$ \n\
 /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/ /$$__  $$\n\
| $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$      | $$  \\__/\n\
| $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$   |  $$$$$$ \n\
| $$|_  $$| $$__  $$| $$  $$$| $$| $$__/    \\____  $$\n\
| $$  \\ $$| $$  | $$| $$\\  $ | $$| $$       /$$  \\ $$\n\
|  $$$$$$/| $$  | $$| $$ \\/  | $$| $$$$$$$$|  $$$$$$/\n\
 \\______/ |__/  |__/|__/     |__/|________/ \\______/\n\
";

Menu* gameMenu(){
	const int size = 3;
	char* options[3] = {
		"( )SNAKE",
		"( )POWROT",
		"( )WYJDZ"
	};
	Menu* menu;
	char* title = gameString;
	menu = createMenu(menu, size, title, options);
	menu->methods->whatScene = &gameWhatScene;
	menu->methods->changeMenu = &gameChangeMenu;

	return menu;
}


int gameWhatScene(Menu* main, int option){
	switch(option){
		case 0:	return GAMES_SCENE;
		case 1: return MAIN_SCENE;
		case 2: return EXIT;
		default: return EXIT;
	}
}


Menu* gameChangeMenu(Menu* self, int option){
	Menu* temp;
	switch(option){
		case 0:	snakeGame();
				temp = gameMenu();
				break;
		case 1: 
				temp = mainMenu();
				break;
		case 2: 
				temp = mainMenu();
				break;
	}
	return temp;
}

