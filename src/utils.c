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



void nonblock(int state)
{
    struct termios ttystate;

    tcgetattr(STDIN_FILENO, &ttystate);

    if (state==NB_ENABLE)
    {
        ttystate.c_lflag &= ~(ICANON | ECHO);
    }
    else if (state==NB_DISABLE)
    {
        ttystate.c_lflag |= (ICANON | ECHO);
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}


int _kbhit()
{
    struct termios oldAttr, newAttr;
    tcgetattr(STDIN_FILENO, &oldAttr);

    newAttr = oldAttr;
    newAttr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr(STDIN_FILENO, TCSANOW, &newAttr);

    setbuf(stdin, NULL);
    int byteswaiting;
    ioctl(STDIN_FILENO, FIONREAD, &byteswaiting);

    tcsetattr(STDIN_FILENO, TCSANOW, &oldAttr);

    return byteswaiting;
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



void nonblock(int state)
{
	
}
#endif

#ifdef linux
void (showInput)(struct showInput boxSize){
	struct winsize window = getWindowSize();
	int width = boxSize.colNb? window.ws_col * ((double)(boxSize.colNb)/10) :  window.ws_col * 0.8;
	int height = boxSize.rowNb? boxSize.rowNb :  1;
	int i;
	
	printf("\n");
	moveUp(1);
	printf("┌\n");
	for(i=0; i<height; i++)
		printf("│\n");
	printf("└");
	moveUp(height + 1);

	for(i=0; i<width; i++){
		printf("─");
		moveDown(1);
		moveLeft(1);
		printf(" ");
		moveUp(1);
		moveDown(height + 1);
		moveLeft(1);
		printf("─");
		moveUp(height + 1);
	}
	
	printf("┐");
	moveDown(1);
	moveLeft(1);
	for(i=0; i<height; i++){
		printf("│");
		moveDown(1);
		moveLeft(1);
	}
	printf("┘");

	moveUp(height);
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
	int newSize = strlen(str1) + strlen(str2) + 1;

	if( (newStr = calloc(newSize, sizeof(char))) != NULL){
		snprintf(newStr, newSize, "%s%s",str1 , str2);
	}

	free(str1);
	free(str2);

	return newStr;
}
