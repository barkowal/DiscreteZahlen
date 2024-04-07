#include "gui.h"

int win_row = 0;
int currentScene = MAIN_SCENE;
Menu* menu;


int gui(){
	menu = mainMenu();
	char key = ' ';
	int option = 0;

	refreshScreen();

	changeLine(key, &option);
	while(currentScene != EXIT){
		while((key = getch()) != '\r' && (key != EOF && key != '\n' )){
			changeLine(key, &option);
		}
		changeScene(&option);

		refreshScreen();
		changeLine(key, &option);
	}

	if(menu != NULL){
		destroyMenu(&menu);
	}

	clearScreen();
	return EXIT_OK;
}


int whatScene(int option){
	int scene = 0;
	scene = menu->methods->whatScene(menu, option);

	return scene;
}


void changeScene(int* option){
	int scene = whatScene(*option);
	Menu* temp = menu->methods->changeMenu(menu, *option);

	destroyMenu(&menu);

	menu = temp;
	currentScene = scene;
}


void showTitle( int sceneNB ){
	char* title = menu->methods->getTitle(menu);
	printTitle(title, strlen(title));
}


void printTitle(char* title, int len){
	struct winsize window = getWindowSize();
	int textWidth = 0;

	while(title[textWidth] != '\n')
		textWidth++;
	
	int center = ((int)(window.ws_col * 0.5) - textWidth/2);
	moveRight(center);

	int i;
	for(i=0; i<len; i++){
		printf("%c",title[i]);
		if(title[i] == '\n')
			moveRight(center);
	}
}


void refreshScreen(){
	struct winsize window = getWindowSize();
	colorLine(37,40);
 	clearScreen();

	showTitle(currentScene);
	win_row = 0.5 * window.ws_row;
	moveCursor(win_row, 0);

	showMenu(menu);
	win_row++;
	moveCursor(win_row, 0);
}


void changeLine(char keyPress, int* option){

	refreshScreen();
	int menuSize = menu->size;
	int selectedOption = *option; 

	switch(keyPress){
	case 'k':			
				selectedOption--; 
				break;
	case UP_ARROW:
				selectedOption--; 
				break;
	case 'j':	
				selectedOption++;
				break;
	case DOWN_ARROW:
				selectedOption++;
				break;
	}

	if(selectedOption < menuSize && selectedOption > 0){
		*option = selectedOption;
	}
	if(selectedOption >= menuSize){
		*option = menuSize - 1;
	}
	if(selectedOption <= 0 ){
		*option = 0;
	}

	moveCursor(win_row + *option, 0);
	colorLine(47,30);
	showMenuItem(menu, *option);
	colorLine(37,40);
}



