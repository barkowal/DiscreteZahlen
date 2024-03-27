#ifndef extendedEuc_H
#define extendedEuc_H

#include <stdio.h>
#include <math.h>

struct eucResult{
	int nwd;
	int x; 
	int y;
};

int divide(int, int); 
int mod(int, int);
int nwd(int, int);
int ext_nwd(int, int);
struct eucResult ext_nwd_table(int ,int);
int nwd_rec(int, int);


#endif

