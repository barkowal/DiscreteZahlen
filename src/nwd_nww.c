#include "nwd_nww.h"


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

char* appendString(char* str1, char* str2){
	char* newStr;
	if( (newStr = malloc(strlen(str1) + strlen(str2))) != NULL){
		newStr[0] = '\0';
		strcat(newStr, str1);
		strcat(newStr, str2);
	}
	return newStr;
}

struct factor calculateNWD_NWW(int a, int b)
{
	int alfa = 0;
	int beta = 0;
	int prime = 1;
	int i, j;
	struct factor result;
	result.nwd = result.nww = 1;
	char* factoring = "";

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

		result.nwd *= pow(prime,fmin(alfa,beta));
		result.nww *= pow(prime,fmax(alfa,beta));

	
		if (alfa){
			int len = snprintf(NULL, 0, "%d[%d] ", prime, alfa);
			char* temp = malloc( len + 1 );
			snprintf(temp, len, "%d[%d] ", prime, alfa);
			factoring = appendString(factoring, temp);
		}
		if (beta){
			int len = snprintf(NULL, 0, "%d[%d] ", prime, alfa);
			char* temp = malloc( len + 1 );
			snprintf(temp, len, "%d[%d] ", prime, alfa);
			factoring = appendString(factoring, temp);
		}
		printf("%s",factoring);
	}
	return result;
}
 
