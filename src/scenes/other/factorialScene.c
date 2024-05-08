#include "factorialScene.h"


char factorialMenuString[] = " \
 /$$$$$$$  /$$   /$$ /$$$$$$$  /$$$$$$$$ /$$$$$$  /$$$$$$  /$$   /$$\n\
| $$__  $$| $$  | $$| $$__  $$|_____ $$ |_  $$_/ /$$__  $$| $$$ | $$\n\
| $$  \\ $$| $$  | $$| $$  \\ $$     /$$/   | $$  | $$  \\ $$| $$$$| $$\n\
| $$$$$$$/| $$  | $$| $$  | $$    /$$/    | $$  | $$$$$$$$| $$ $$ $$\n\
| $$____/ | $$  | $$| $$  | $$   /$$/     | $$  | $$__  $$| $$  $$$$\n\
| $$      | $$  | $$| $$  | $$  /$$/      | $$  | $$  | $$| $$\\  $$$\n\
| $$      |  $$$$$$/| $$$$$$$/ /$$$$$$$$ /$$$$$$| $$  | $$| $$ \\  $$\n\
|__/       \\______/ |_______/ |________/|______/|__/  |__/|__/  \\__/\n\
";




Menu* factorialMenu(){
	const int size = 3;
	char* options[3] = {
		"( )OBLICZ",
		"( )POWROT",
		"( )WYJDZ"
	};
	Menu* menu;
	char* title = factorialMenuString;
	menu = createMenu(menu, size, title, options);
	menu->methods->whatScene = &factorialWhatScene;
	menu->methods->changeMenu = &factorialChangeMenu;

	return menu;
}


int factorialWhatScene(Menu* main, int option){
	switch(option){
		case 0:	return FACTORIAL_SCENE;
		case 1:	return MAIN_SCENE;
		default: return EXIT;
	}
}


Menu* factorialChangeMenu(Menu* self, int option){
	Menu* temp;
	switch(option){
		case 0:	
				showFactorial();
				temp = factorialMenu();
				break;
		case 1: 
				temp = otherMenu();
				break;
		default: 
				temp = mainMenu();
				break;
	}
	return temp;
}


void showFactorial(){
	int n;

	showInput();	
	printf("Wpisz silnie: ");
	scanf("%d",&n);

	moveDown(1);
	showInput(.colNb = 8, .rowNb = 5);
	calculateFactorial(n);

	getchar();
	getchar();
}

