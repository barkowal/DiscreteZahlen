#ifndef gui_h
#define gui_h

#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include "utils.h"
#include "menu.h"

#define EXIT_OK 0



#ifdef _WIN32

#endif

#ifdef linux
#define clearScreen() printf("\033[H\033[J")
#define moveUp(value) printf("\033[%dA",value)
#define moveDown(value) printf("\033[%dB",value)
#define moveRight(value) printf("\033[%dC",value)
#define moveLeft(value) printf("\033[%dD",value)
#define moveCursor(x, y) printf("\033[%d;%dH", x, y)
#define colorLine(fg,bg) printf("\033[%d;%dm",fg,bg)
#endif



int gui();

void showTitle();

void refreshScreen(struct Menu* menu);

struct Menu* nwdMenu();

void changeLine(struct Menu* menu, char keyPress, int* option);





#endif
