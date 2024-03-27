#ifndef utils_h
#define utils_h
	
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>
#include <stdlib.h>
#include <string.h>


#ifdef _WIN32

#define UP_ARROW 72
#define DOWN_ARROW 80
#define RIGHT_ARROW 77
#define LEFT_ARROW 75

#endif

#ifdef linux
#define clearScreen() printf("\033[H\033[J")
#define moveUp(value) printf("\033[%dA",value)
#define moveDown(value) printf("\033[%dB",value)
#define moveRight(value) printf("\033[%dC",value)
#define moveLeft(value) printf("\033[%dD",value)
#define moveCursor(x, y) printf("\033[%d;%dH", x, y)
#define colorLine(fg,bg) printf("\033[%d;%dm",fg,bg)

// #define UP_ARROW '\\033A'
// #define DOWN_ARROW '\\033B'
#define UP_ARROW 'A'
#define DOWN_ARROW 'B'

#define RIGHT_ARROW 77
#define LEFT_ARROW 75

#endif


int getch();
void showInput();
struct winsize getWindowSize();
char *appendString(char* str1, char* str2);


#endif
