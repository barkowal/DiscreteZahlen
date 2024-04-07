#ifndef ExtendedEucScene_H
#define ExtendedEucScene_H

#include "scenes.h"
#include "../menu.h"
#include "../utils.h"
#include "../math/extendedEuc.h"


Menu* extEucMenu();

int extEucWhatScene(Menu* self, int option);

Menu* extEucChangeMenu(Menu* self, int option);

void calculateExtEuc();

#endif
