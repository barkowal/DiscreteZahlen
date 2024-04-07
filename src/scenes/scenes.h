#ifndef SCENES_H
#define SCENES_H

#define EXIT 0
#define MAIN_SCENE 1
#define NWD_SCENE 2
#define EXTENDEDEUC_SCENE 3
#define CONGRUENCES_SCENE 4
#define SUNZITHEOREM_SCENE 5

#include "../menu.h"

Menu* mainMenu();
Menu* nwdMenu();
Menu* extEucMenu();
Menu* congruenceMenu();
Menu* sunziTheoremMenu();

#endif
