#include "gui.h"

int win_row = 0;
int currentScene = MAIN_SCENE;
struct Menu* menu;


char menuNWW[] = " \
/$$   /$$ /$$      /$$ /$$      /$$ \n\
| $$$ | $$| $$  /$ | $$| $$  /$ | $$ \n\
| $$$$| $$| $$ /$$$| $$| $$ /$$$| $$ \n\
| $$ $$ $$| $$/$$ $$ $$| $$/$$ $$ $$ \n\
| $$  $$$$| $$$$_  $$$$| $$$$_  $$$$ \n\
| $$\\  $$$| $$$/ \\  $$$| $$$/ \\  $$$ \n\
| $$ \\  $$| $$/   \\  $$| $$/   \\  $$ \n\
|__/  \\__/|__/     \\__/|__/     \\__/ \n\
";

 	
int gui(){
	menu = mainMenu();
	char key = ' ';
	int option = 0;

	refreshScreen();

	changeLine(key, &option);
	while(currentScene != EXIT){
		//while((key = getch()) != EOF || (key != '\n' || key != '\r')){
		while((key = getch()) != '\r'){
		//	if(key != '\n' || key != '\r')
		//		break;
			changeLine(key, &option);
		}
		changeScene(&option);

		refreshScreen();
		changeLine(key, &option);
	}


	// showInput();
	// int input;
	// if(scanf("%d", &input) != 1){
	// 	moveUp(2);
	// 	showInput();
	// 	printf("WRONG INPUT");
	// 	while(getchar() != '\n');
	// }
	// printf("OK THIS TIME");
	//
	// scanf("%d", &input);
	clearScreen();
	return EXIT_OK;
}



//TODO polymorphism instead of that blasphemy
int whatScene(int option){
	int scene = 0;

	switch(currentScene){
		case MAIN_SCENE: 
					scene = mainWhatScene(option);
					break;
		case NWD_SCENE:
					scene = nwdWhatScene(option);
					break;
		case EXTENDEDEUC_SCENE:
					scene = extEucWhatScene(option);
					break;
		case EXIT:
					scene = EXIT;
					break;
	}

	return scene;
}


void changeScene(int* option){
	int scene = whatScene(*option);
	destroyMenu(&menu);

	switch(scene){
		case MAIN_SCENE: 
					menu = mainMenu();
					break;
		case NWD_SCENE:
					menu = nwdMenu();
					break;
		case EXTENDEDEUC_SCENE:
					menu = extEucMenu();
					break;
		case EXIT:
					menu = mainMenu();
					break;
	}

	currentScene = scene;

}

void showTitle( int sceneNB ){
	switch(sceneNB){
		case MAIN_SCENE:
			printTitle( mainGetTitle(), strlen(mainGetTitle()) );
		break;
		case NWD_SCENE:
			printTitle( nwdGetTitle(), strlen(nwdGetTitle()) );
		break;
		case EXTENDEDEUC_SCENE:
			printTitle( extEucGetTitle(), strlen(extEucGetTitle()) );
		break;
	}
}

// ┌────────────┐	
// │            │
// └────────────┘
// void showInput(){
// 	struct winsize window = getWindowSize();
// 	int width = window.ws_col * 0.8;
// 	int i;
//
// 	printf("┌\n");
// 	printf("│\n");
// 	printf("└");
// 	moveUp(2);
//
// 	for(i=0; i<width; i++){
// 		printf("─");
// 		moveDown(1);
// 		moveLeft(1);
// 		printf(" ");
// 		moveDown(1);
// 		moveLeft(1);
// 		printf("─");
// 		moveUp(2);
// 	}
//
// 	printf("┐");
// 	moveDown(1);
// 	moveLeft(1);
// 	printf("│");
// 	moveDown(1);
// 	moveLeft(1);
// 	printf("┘");
//
// 	moveUp(1);
// 	moveLeft(width);
// }




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



