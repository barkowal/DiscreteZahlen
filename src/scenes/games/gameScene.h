#ifndef gameScene_h
#define gameScene_h

#include "../../menu.h"
#include "../scenes.h"
#include "snake/snakeGame.h"

Menu* gameMenu();

int gameWhatScene(Menu* self, int option);

Menu* gameChangeMenu(Menu* self, int option);
#endif
