#ifndef nwdScene_h
#define nwdScene_h

#include "../menu.h"
#include "../utils.h"
#include "scenes.h"
#include "../math/nwd_nww.h"

Menu* nwdMenu();
int nwdWhatScene(Menu* self, int option);
Menu* nwdChangeMenu(Menu* self, int option);
void calculateNWD();
void showFactorization();

#endif
