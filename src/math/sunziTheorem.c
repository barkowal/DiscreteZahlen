#include "sunziTheorem.h"



//xi = a * mi * bi 
//bi = (mi^-1 mod m) OR NWD(singleMod, mi) = a * a + bi * singleMod 
int calculatePart(int a, int singleMod, int mulMod){
	int mi = mulMod/singleMod;
	int bi, x;
	ext_nwd(singleMod, mi, &x, &bi);
	return a*mi*bi;
}


int calculateSunziTheorem(int a[], int singleMod[], int size){
	int mulMod = 1;
	int result = 0;
	int i;
	for(i=0; i<size; i++){
		mulMod *= singleMod[i];
	}
	
	if(!checkInputValues(a, singleMod, mulMod, size))
		return 0;

	for(i=0; i<size; i++){
		result += calculatePart(a[i], singleMod[i], mulMod);
	}
	result %= mulMod;

	//To get result in {0, ..., mulMod - 1}
	while(result<0)
		result += mulMod;
	while(result>=mulMod)
		result -= mulMod;

	return result;
}


//Algorithm with a little bit of tweaking should work with any values,
//but for now it only works with pairwise coprimes
int checkInputValues(int a[], int moduloValues[], int mulMod, int size){
	int i,j;

	for(i=0; i<size; i++){
		if(a[i] >= mulMod || a[i] < 0) return 0;

		for(j=i+1; j<size; j++){
			if(nwd(moduloValues[i], moduloValues[j]) != 1)
				return 0;
		}
	}

	return 1;
}
