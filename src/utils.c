#include "utils.h"


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


struct winsize getWindowSize(){
	struct winsize window;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);

	return window;

}

