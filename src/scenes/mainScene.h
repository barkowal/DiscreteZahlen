#ifndef mainScene_h
#define mainScene_h

#include "../menu.h"
#include "scenes.h"

struct Menu* mainMenu();

char* mainGetTitle();

int mainWhatScene(int option);

#endif
