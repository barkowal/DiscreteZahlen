#include "factorial.h"


void sieve(int n, int* tab){
	int next = 0;
	int i;

	for(i=0; i<n; i++){
		tab[i] = 1;
	}
	
	for(i=2; i <= sqrt(n); i++){
		if(tab[i] == 1){
			next = i;
			while(next < n){
				next += i;
				tab[next] = 0;
			}
		}
	}

}


void calculateFactorial(int n){
	int primes[n+1];
	sieve(n+1, primes);
	int i;

	for(i=2; i <= n; i++){
		if(primes[i] == 1) {
			int exp = 1;
			int divider = i;
			while(n/divider > 1){
				exp += n/divider;
				divider *= divider;
			}
			printf(" [ %d ^ %d ]", i, exp);
		}
	}

}

