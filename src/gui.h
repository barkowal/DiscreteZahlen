#ifndef gui_h
#define gui_h

#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include "utils.h"
#include "menu.h"
#include "scenes.h"

#include "mainScene.h"
#include "nwdScene.h"

#define EXIT_OK 0





int gui();

void showTitle(int sceneNumber);
void printTitle( char* title, int len);

void refreshScreen();

void changeLine(char keyPress, int* option);

void changeScene(int* option);
int whatScene(int option);



#endif
