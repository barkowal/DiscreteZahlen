#include "nwdScene.h"

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

char* nwdGetTitle(){
	return menuNWD;
}

struct Menu* nwdMenu(){
	const int size = 2;	
	char *options[2] = {
		"( ) WPISZ WARTOSCI",
		"( ) POWROT"
	};
	struct Menu* menu = createMenu(menu, size, options);
	return menu;
}


int nwdWhatScene(int option){
	switch(option){
		case 0:
				calculateNWD();
				return NWD_SCENE;
		case 1:
				return MAIN_SCENE;
		default:
				return MAIN_SCENE;
	}
}


void calculateNWD(){
	int a = 0;
	int b = 0;
	struct factor result;
	moveUp(3);
	printf("\nWpisz pierwsza liczbe:\n");
	showInput();
	scanf("%d", &a);

	printf("\nWpisz druga liczbe:\n");
	showInput();
	scanf("%d", &b);

	result = calculateNWD_NWW(a,b);

	moveDown(1);
	showInput();
	printf("CIAG: %s\n", result.sequence);

	moveDown(1);
	showInput();
	printf("NWD: %d, NWW: %d",result.nwd, result.nww);
	getchar();
	getchar();
	if(strlen(result.sequence) != 0)
		free(result.sequence);
}
