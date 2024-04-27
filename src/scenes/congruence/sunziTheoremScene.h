#ifndef sunziTheoremScene_H
#define sunziTheoremScene_H

#include "../scenes.h"
#include "../../menu.h"
#include "../../utils.h"
#include "sunziTheorem.h"


Menu* sunziTheoremMenu();

int sunziTheoremNextScene(Menu* self, int option);

Menu* sunziTheoremChangeMenu(Menu* self, int option);

void showSunziTheorem();

#endif
