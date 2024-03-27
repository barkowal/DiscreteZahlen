#include "utils.h"


#ifdef linux
struct winsize getWindowSize(){
	struct winsize window;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);

	return window;

}


int getch()
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}
#endif


#ifdef _WIN32
struct winsize getWindowSize(){
	struct winsize window;

    CONSOLE_SCREEN_BUFFER_INFO csbi;
    int columns, rows;

    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

	window.ws_row = rows;
	window.ws_col = columns;
	
	window.ws_xpixel = 0;
	window.ws_ypixel = 0;

	return window;
}
#endif

#ifdef linux
void showInput(){
	struct winsize window = getWindowSize();
	int width = window.ws_col * 0.8;
	int i;
	
	printf("\n");
	moveUp(1);
	printf("┌\n");
	printf("│\n");
	printf("└");
	moveUp(2);

	for(i=0; i<width; i++){
		printf("─");
		moveDown(1);
		moveLeft(1);
		printf(" ");
		moveDown(1);
		moveLeft(1);
		printf("─");
		moveUp(2);
	}

	printf("┐");
	moveDown(1);
	moveLeft(1);
	printf("│");
	moveDown(1);
	moveLeft(1);
	printf("┘");

	moveUp(1);
	moveLeft(width);
}
#endif

#ifdef _WIN32
void showInput(){
	struct winsize window = getWindowSize();
	int width = window.ws_col * 0.8;
	int i;
	
	printf("\n");
	moveUp(1);
	printf("-\n");
	printf("|\n");
	printf("-");
	moveUp(2);

	for(i=0; i<width; i++){
		printf("-");
		moveDown(1);
		moveLeft(1);
		printf(" ");
		moveDown(1);
		moveLeft(1);
		printf("-");
		moveUp(2);
	}

	printf("-");
	moveDown(1);
	moveLeft(1);
	printf("|");
	moveDown(1);
	moveLeft(1);
	printf("-");

	moveUp(1);
	moveLeft(width);
}
#endif



char *appendString(char* str1, char* str2){
	char* newStr;
	if( (newStr = malloc(strlen(str1) + strlen(str2))) != NULL){
		newStr[0] = '\0';
		strcat(newStr, str1);
		strcat(newStr, str2);
	}

	return newStr;
}
