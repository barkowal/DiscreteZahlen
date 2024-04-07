#ifndef mainScene_h
#define mainScene_h

#include "../menu.h"
#include "scenes.h"

Menu* mainMenu();

int mainWhatScene(Menu* self, int option);

Menu* mainChangeMenu(Menu* self, int option);
#endif
