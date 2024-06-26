#include "extendedEuc.h"


int divide(int a, int b){
	int result =floorf( (double)a/b );
	return result;
}

int mod(int a, int b){
	int result = a - divide(a,b) * b;
	return result;
}

int nwd(int a, int b){
	int rest;
	// printf("NWD( %d, %d ) = ", a,b);
	while(b != 0){
		rest = a%b;
		a = b;
		b = rest;
	}
	// printf("%d \n",a);
	return a;
}

int ext_nwd( int a, int b, int* x, int* y){
	int rest;
	int divided;
	*x = 1;
	*y = 0;
	int s = 0;
	int r = 1;
	int sp;
	int rp;
//	printf("Extended NWD( %d, %d ) = ", a,b);
	while(b != 0){
		rest = a%b;
		divided = divide(a,b);
		a = b;
		b = rest;
		sp = *x - divided * s;
		rp = *y - divided * r;
		*x = s;
		*y = r;
		s = sp;
		r = rp;
	}
//	printf(" %d, x = %d, y = %d \n",a,x,y);
	return 0;
}

int nwd_rec(int a, int b){
	if(b == 0)
		return a;
	return nwd_rec(b,a%b);
}

struct eucResult ext_nwd_table(int a, int b){
	int rest = 0;
	int divided;
	int x = 1;
	int y = 0;
	int s = 0;
	int r = 1;
	int sp;
	int rp;
	printf("         a |          x |          b |          y |          r | \n");
	printf("%10d | %10d | %10d | %10d | %10d | \n", a,x,b,y,rest);
	while(b != 0){
		rest = a%b;
		divided = divide(a,b);
		a = b;
		b = rest;
		sp = x - divided * s;
		rp = y - divided * r;
		x = s;
		y = r;
		s = sp;
		r = rp;
		printf("%10d | %10d | %10d | %10d | %10d | \n", a,x,b,y,rest);
	}
	struct eucResult result = {a, x, y};
	return result;
}
