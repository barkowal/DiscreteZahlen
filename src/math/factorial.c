#include "factorial.h"


int* sieve(const int n){
	int next = 0;
	int i;
	int* tab = malloc( sizeof(int) * n );

	for(i=0; i<n; i++){
		tab[i] = 1;
	}
	
	for(i=2; i <= sqrt(n); i++){
		if(tab[i] == 1){
			next = i+i;
			while(next < n){
				tab[next] = 0;
				next += i;
			}
		}
	}

	return tab;
}


void calculateFactorial(const int n){
	int* primes = sieve(n+1);
	int i;

	for(i=2; i <= n; i++){
		if(primes[i] == 1) {
			int exp = 0;
			int divider = i;
			while( (n/divider) >= 1){
				exp += (n/divider);
				divider *= i;
			}
			printf(" [ %d ^ %d ]", i, exp);
		}
	}

	free(primes);
}

