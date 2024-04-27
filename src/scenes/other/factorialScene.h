#ifndef factorialScene_h
#define factorialScene_h

#include "../../menu.h"
#include "../scenes.h"
#include "factorial.h"
#include "../../utils.h"

Menu* factorialMenu();

int factorialWhatScene(Menu* self, int option);

Menu* factorialChangeMenu(Menu* self, int option);

void showFactorial();

#endif
