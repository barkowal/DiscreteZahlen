#ifndef NWD_NWW_H
#define	NWD_NWW_H

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "../../utils.h"
 
#define TRUE 1
#define FALSE 0
#define EXIT_OK 0
 
#define RED 12
#define WHITE 15
#define GREEN 2
#define BLUE 1
 
struct factor{
	int nwd;
	int nww;
	char* nwdSequence;
	char* nwwSequence;
};


int fastPow(int, int);
int isPrime(int number);
int getNextPrime(int prevprime);
struct factor calculateNWD_NWW(int a, int b);
char* getFactorization(int a);

#endif
