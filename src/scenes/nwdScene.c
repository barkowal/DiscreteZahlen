#include "nwdScene.h"

char menuNWD[] = " \
 /$$   /$$ /$$      /$$ /$$$$$$$       /$$ /$$   /$$ /$$      /$$ /$$      /$$\n\
| $$$ | $$| $$  /$ | $$| $$__  $$     /$$/| $$$ | $$| $$  /$ | $$| $$  /$ | $$\n\
| $$$$| $$| $$ /$$$| $$| $$  \\ $$    /$$/ | $$$$| $$| $$ /$$$| $$| $$ /$$$| $$\n\
| $$ $$ $$| $$/$$ $$ $$| $$  | $$   /$$/  | $$ $$ $$| $$/$$ $$ $$| $$/$$ $$ $$\n\
| $$  $$$$| $$$$_  $$$$| $$  | $$  /$$/   | $$  $$$$| $$$$_  $$$$| $$$$_  $$$$\n\
| $$\\  $$$| $$$/ \\  $$$| $$  | $$ /$$/    | $$\\  $$$| $$$/ \\  $$$| $$$/ \\  $$$\n\
| $$ \\  $$| $$/   \\  $$| $$$$$$$//$$/     | $$ \\  $$| $$/   \\  $$| $$/   \\  $$\n\
|__/  \\__/|__/     \\__/|_______/|__/      |__/  \\__/|__/     \\__/|__/     \\__/\n\
";


Menu* nwdMenu(){
	const int size = 3;	
	char *options[3] = {
		"( )WPISZ WARTOSCI ABY POLICZYC NWD, NWW",
		"( )ROZKLAD LICZBY NA CZYNNIKI PIERWSZE",
		"( )POWROT"
	};
	char* title = menuNWD;
	Menu* menu = createMenu(menu, size, title, options);
	menu->methods->whatScene = &nwdWhatScene;
	return menu;
}


int nwdWhatScene(Menu* self, int option){
	switch(option){
		case 0:
				calculateNWD();
				return NWD_SCENE;
				break;
		case 1:
				showFactorization();
				return NWD_SCENE;
				break;
		case 2:
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

	moveDown(1);
	if( a >= INT_MAX || b >= INT_MAX || a < 0 || b < 0){
		showInput();
		printf("PODANO ZLE DANE!!!");

		getchar();
		getchar();
		return;
	}

	result = calculateNWD_NWW(a,b);

	showInput();
	printf("CIAG NWD: %s", result.nwdSequence);
	printf(", CIAG NWW: %s\n", result.nwwSequence);

	moveDown(1);
	showInput();
	printf("NWD: %d, NWW: %d \n",result.nwd, result.nww);
	getchar();
	getchar();

	if(strlen(result.nwdSequence) != 0)
		free(result.nwdSequence);

	if(strlen(result.nwwSequence) != 0)
		free(result.nwwSequence);

}


void showFactorization(){
	int a = 0;

	moveUp(3);
	printf("\nPODAJ LICZBE:                       \n");
	showInput();
	scanf("%d", &a);

	moveDown(1);
	if( a >= INT_MAX || a < 0 ){
		showInput();
		printf("PODANO ZLE DANE!!!");

		getchar();
		getchar();
		return;
	}

	char* sequence = getFactorization(a);
	showInput();
	printf("ROZKLAD NA CZYNNIKI: %s",sequence);

	getchar();
	getchar();

	if(strlen(sequence) != 0)
		free(sequence);

}
