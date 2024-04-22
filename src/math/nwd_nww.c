#include "nwd_nww.h"


int fastPow(int base, int exp){
	int result = 1;

	while(exp){
		if(exp & 1)
			result *= base;
		exp >>= 1;
		base *= base;
	}

	return result;
}


int isPrime(int number)
{
	int result = TRUE;
	int i;
	for(i = 2; i <= (int)sqrt((double)number); i ++)
		if (number % i == 0)
		{
			result = FALSE;
			break;
		}
	return result;
}
 
int getNextPrime(int prevprime)
{
	int i;
	for(i = prevprime+1; /* !isPrime(i) */;i ++)
		if (isPrime(i))
		{
			break;
		}
	return i;
}


struct factor calculateNWD_NWW(int a, int b)
{
	int alfa = 0;
	int beta = 0;
	int prime = 1;
	int i, j;
	struct factor result;
	result.nwd = result.nww = 1;
	result.nwdSequence = calloc(1,sizeof(char));
	result.nwwSequence = calloc(1,sizeof(char));

	for(i = j = 1; i<= a || j <= b; i = j = prime)
	{
		alfa = 0;
		beta = 0;
		prime = getNextPrime( (a>b)?i:j);
		while ( a > 1 )
		{
			if (a % prime == 0)
			{
				a /= prime;
				alfa ++;
			}
			else
				break;
		}

		while ( b > 1 )
		{
			if (b % prime == 0)
			{
				b /= prime;
				beta++;
			}
			else
				break;
		}

		result.nwd *= fastPow(prime,fmin(alfa,beta));
		result.nww *= fastPow(prime,fmax(alfa,beta));

	
		if (alfa || beta){
			int minim = fmin(alfa,beta);
			int maxim = fmax(alfa,beta);
			int nwdLen = snprintf(NULL, 0, " %d^%d ", prime, minim);
			int nwwLen = snprintf(NULL, 0, " %d^%d ", prime, maxim);
			char* nwdTemp = malloc( nwdLen + 1 );
			char* nwwTemp = malloc( nwwLen + 1 );

			snprintf(nwdTemp, nwdLen, " %d^%d ", prime, minim);
			snprintf(nwwTemp, nwwLen, " %d^%d ", prime, maxim);
			result.nwdSequence = appendString(result.nwdSequence, nwdTemp);
			result.nwwSequence = appendString(result.nwwSequence, nwwTemp);

		}
	}
	return result;
}
 

char* getFactorization(int a)
{
	char* sequence = calloc(1,sizeof(char));
	int alfa = 0;
	int prime = 1;
	int i;
	for(i = 1; i<= a; i = prime)
	{
		alfa = 0;
		prime = getNextPrime(i);
		while ( a > 1 )
		{
			if (a % prime == 0)
			{
				a /= prime;
				alfa ++;
			}
			else
				break;
		}

		if (alfa){
			int len = snprintf(NULL, 0, " %d^%d ", prime, alfa);
			char* temp = malloc( len + 1 );

			snprintf(temp, len, " %d^%d ", prime, alfa);
			sequence = appendString(sequence, temp);

		}
	}

	return sequence;
}
