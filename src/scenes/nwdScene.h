#ifndef nwdScene_h
#define nwdScene_h

#include "../menu.h"
#include "../utils.h"
#include "scenes.h"
#include "../math/nwd_nww.h"

char* nwdGetTitle();
struct Menu* nwdMenu();
int nwdWhatScene(int option);
void calculateNWD();
void showFactorization();

#endif
