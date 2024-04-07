#include "sunziTheoremScene.h"

char sunziTitle[] = "\
  /$$$$$$  /$$   /$$ /$$   /$$ /$$$$$$$$ /$$$$$$\n\
 /$$__  $$| $$  | $$| $$$ | $$|_____ $$ |_  $$_/\n\
| $$  \\__/| $$  | $$| $$$$| $$     /$$/   | $$  \n\
|  $$$$$$ | $$  | $$| $$ $$ $$    /$$/    | $$  \n\
 \\____  $$| $$  | $$| $$  $$$$   /$$/     | $$  \n\
 /$$  \\ $$| $$  | $$| $$\\  $$$  /$$/      | $$  \n\
|  $$$$$$/|  $$$$$$/| $$ \\  $$ /$$$$$$$$ /$$$$$$\n\
 \\______/  \\______/ |__/  \\__/|________/|______/\n\
";

Menu* sunziTheoremMenu(){
	const int size = 3;
	char* options[3] = {
		"( )WPISZ WARTOSCI",
		"( )POWROT",
		"( )MAIN MENU"
	};
	char* title = sunziTitle;
	struct Menu* menu = createMenu(menu, size, title, options);
	menu->methods->whatScene = &sunziTheoremNextScene;
	menu->methods->changeMenu = &sunziTheoremChangeMenu;
	return menu;
}

int sunziTheoremNextScene(Menu* self, int option){
	switch(option){
		case 0:
				showSunziTheorem();
				return SUNZITHEOREM_SCENE;
		case 1:
				return CONGRUENCES_SCENE;
		case 2:
				return MAIN_SCENE;
		default:
				return CONGRUENCES_SCENE;
	}
}

Menu* sunziTheoremChangeMenu(Menu* self, int option){
	Menu* temp;
	switch(option){
		case 0:
				temp = sunziTheoremMenu();
				break;
		case 1:
				temp = congruenceMenu();
				break;
		case 2:
				temp = mainMenu();
				break;
		default:
				temp = congruenceMenu();
				break;
	}
	return temp;
}

void showSunziTheorem(){
	int size;
	int* a;
	int* moduloTable;
	int result;

	moveUp(3);
	printf("\nWpisz ilosc rownan:\n");
	showInput();
	scanf("%d", &size);

	a = malloc(sizeof(int) * size);
	moduloTable = malloc(sizeof(int) * size);

	int i;
	for(i=1; i<=size; i++){
		printf("\nWpisz %d rownanie:\n", i);
		showInput();
		printf("x mod ");
		scanf("%d", &(moduloTable[i-1]));
		moveUp(1);
		moveRight(20);
		printf(" = ");
		scanf("%d", &(a[i-1]));
		moveDown(1);
	}

	result = calculateSunziTheorem(a, moduloTable, size);

	showInput();
	printf("Wynik = %d", result);

	free(a);
	free(moduloTable);

	getchar();
	getchar();
}


