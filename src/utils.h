#ifndef utils_h
#define utils_h
	
#include <stdio.h>
#include <unistd.h>
#include <limits.h>


#include <stdlib.h>
#include <string.h>


#define moveUp(value) printf("\033[%dA",value)
#define moveDown(value) printf("\033[%dB",value)
#define moveRight(value) printf("\033[%dC",value)
#define moveLeft(value) printf("\033[%dD",value)
#define moveCursor(x, y) printf("\033[%d;%dH", x, y)
#define colorLine(fg,bg) printf("\033[%d;%dm",fg,bg)

#ifdef _WIN32

#include <windows.h>
#include <conio.h>

#define UP_ARROW 72
#define DOWN_ARROW 80
#define RIGHT_ARROW 77
#define LEFT_ARROW 75

#define clearScreen() system("cls")
//#define colorLine(fg,bg) SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), bg*16 + fg);

#endif

#ifdef linux

#include <sys/ioctl.h>
#include <termios.h>

// #define UP_ARROW '\\033A'
// #define DOWN_ARROW '\\033B'
#define UP_ARROW 'A'
#define DOWN_ARROW 'B'

#define RIGHT_ARROW 77
#define LEFT_ARROW 75


#define clearScreen() printf("\033[H\033[J")

#endif


#ifdef _WIN32
struct winsize{
	unsigned short ws_row;
    unsigned short ws_col;
    unsigned short ws_xpixel;   /* unused */
    unsigned short ws_ypixel;   /* unused */
};
#endif

int getch();
void showInput();
struct winsize getWindowSize();
char* appendString(char* str1, char* str2);


#endif
