#ifndef congruenceScene_H
#define congruenceScene_H

#include "../scenes.h"
#include "../../menu.h"
#include "../../utils.h"


Menu* congruenceMenu();
int congruenceNextScene(Menu* self, int option);
Menu* congruenceChangeMenu(Menu* self, int option);

#endif
