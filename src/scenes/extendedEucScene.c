#include "extendedEucScene.h"


char extEucTitle[] = "\
 /$$$$$$$$           /$$       /$$ /$$       /$$                    \n\
| $$_____/          | $$      | $$|__/      | $$                    \n\
| $$       /$$   /$$| $$   /$$| $$ /$$  /$$$$$$$  /$$$$$$   /$$$$$$$\n\
| $$$$$   | $$  | $$| $$  /$$/| $$| $$ /$$__  $$ /$$__  $$ /$$_____/\n\
| $$__/   | $$  | $$| $$$$$$/ | $$| $$| $$  | $$| $$$$$$$$|  $$$$$$ \n\
| $$      | $$  | $$| $$_  $$ | $$| $$| $$  | $$| $$_____/ \\____  $$\n\
| $$$$$$$$|  $$$$$$/| $$ \\  $$| $$| $$|  $$$$$$$|  $$$$$$$ /$$$$$$$/\n\
|________/ \\______/ |__/  \\__/|__/|__/ \\_______/ \\_______/|_______/ \n\
";


struct Menu* extEucMenu(){
	const int size = 2;
	char* options[2] = {
		"( )WPISZ WARTOSC",
		"( )POWROT"
	};
	char* title = extEucTitle;
	struct Menu* menu = createMenu(menu, size, title, options);
	menu->methods->whatScene = &extEucWhatScene;
	return menu;
}

int extEucWhatScene(Menu* self, int option){
	switch(option){
		case 0:
				calculateExtEuc();
				return EXTENDEDEUC_SCENE;
		case 1:
				return MAIN_SCENE;
		default:
				return MAIN_SCENE;
	}
}


void calculateExtEuc(){
	int a, b;
	struct eucResult result;

	moveUp(3);
	printf("\nWpisz pierwsza liczbe:\n");
	showInput();
	scanf("%d", &a);

	printf("\nWpisz druga liczbe:\n");
	showInput();
	scanf("%d", &b);

	moveDown(1);
	result = ext_nwd_table(a, b);

	moveDown(1);
	showInput();
	printf("NWD = %d = %d * %d + %d * %d", result.nwd, result.x, a, result.y, b);
	getchar();
	getchar();
}
