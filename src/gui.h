#ifndef gui_h
#define gui_h

#include <stdio.h>
#include <unistd.h>

#include "utils.h"
#include "menu.h"
#include "scenes/scenes.h"

#include "scenes/mainScene.h"
#include "scenes/nwdScene.h"
#include "scenes/extendedEucScene.h"

#define EXIT_OK 0

/*
#ifdef linux

#include <termios.h>

#endif
*/


int gui();

void showTitle(int sceneNumber);
void printTitle( char* title, int len);

void refreshScreen();

void changeLine(char keyPress, int* option);

void changeScene(int* option);
int whatScene(int option);



#endif
