#include "gui.h"

int win_row = 0;

char menuString[] = " \
/$$      /$$ /$$$$$$$$ /$$   /$$ /$$   /$$\n\
| $$$    /$$$| $$_____/| $$$ | $$| $$  | $$\n\
| $$$$  /$$$$| $$      | $$$$| $$| $$  | $$\n\
| $$ $$/$$ $$| $$$$$   | $$ $$ $$| $$  | $$\n\
| $$  $$$| $$| $$__/   | $$  $$$$| $$  | $$\n\
| $$\\  $ | $$| $$      | $$\\  $$$| $$  | $$\n\
| $$ \\/  | $$| $$$$$$$$| $$ \\  $$|  $$$$$$/\n\
|__/     |__/|________/|__/  \\__/ \\______/ \n";

char menuNWD[] = " \
/$$   /$$ /$$      /$$ /$$$$$$$ \n\
| $$$ | $$| $$  /$ | $$| $$__  $$ \n\
| $$$$| $$| $$ /$$$| $$| $$  \\ $$ \n\
| $$ $$ $$| $$/$$ $$ $$| $$  | $$ \n\
| $$  $$$$| $$$$_  $$$$| $$  | $$ \n\
| $$\\  $$$| $$$/ \\  $$$| $$  | $$ \n\
| $$ \\  $$| $$/   \\  $$| $$$$$$$/ \n\
|__/  \\__/|__/     \\__/|_______/ \n\
";

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
	struct Menu* menu = nwdMenu();
	char key = ' ';
	int option = 0;

	refreshScreen(menu);

	while((key = getch()) != 'x'){
		changeLine(menu, key, &option);
	}

	printf("\nSELECTED OPTION: %d\n",option);

	return EXIT_OK;
}


void showTitle(){
	printf("%s",menuString);
	printf("%s",menuNWD);
	printf("%s",menuNWW);
}


void refreshScreen(struct Menu* menu){
	struct winsize window = getWindowSize();
	colorLine(37,40);
 	clearScreen();

	showTitle();
	win_row = 0.8 * window.ws_row;
	moveCursor(win_row, 0);

	showMenu(menu);
	win_row++;
	moveCursor(win_row, 0);
}


struct Menu* nwdMenu(){
	const int size = 3;
	char* options[3] = {
		"( )Policz NWD",
		"( )Policz NWW",
		"( )Ustawienia"
	};
	struct Menu* menu = createMenu(menu, size, options);
	return menu;
}


void changeLine(struct Menu* menu, char keyPress, int* option){

	refreshScreen(menu);
	int menuSize = menu->size;
	int selectedOption = *option; 

	switch(keyPress){
	case 'k':	selectedOption--; 
				break;
	case 'j':	selectedOption++;
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



