#include <stdio.h>
#include <math.h>
 
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
};
 
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


struct factor calculate(int a, int b)
{
	int alfa = 0;
	int beta = 0;
	int prime = 1;
	int i, j;
	struct factor result;
	result.nwd = result.nww = 1;

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

	
		if (alfa)
			printf("%d[%d]\n", prime, alfa);
		if (beta)
			printf("%d[%d]\n", prime, beta);
	}
	return result;
}
 
int main(void)
{

	printf("NWD: %d \n",calculate(100,101).nwd);
	printf("NWW: %d \n",calculate(100,101).nww);

	getchar();
	return EXIT_OK;
}
