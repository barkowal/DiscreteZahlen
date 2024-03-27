#ifndef ExtendedEucScene_H
#define ExtendedEucScene_H

#include "scenes.h"
#include "../menu.h"
#include "../utils.h"
#include "../math/extendedEuc.h"


char* extEucGetTitle();

struct Menu* extEucMenu();

int extEucWhatScene(int option);

void calculateExtEuc();

#endif
