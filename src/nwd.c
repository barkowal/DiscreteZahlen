#include <stdio.h>
#include <math.h>
 
#define TRUE 1
#define FALSE 0
#define EXIT_OK 0
 
#define RED 12
#define WHITE 15
#define GREEN 2
#define BLUE 1
 
 
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


int nwd(int a, int b)
{
	int alfa = 0;
	int beta = 0;
	int prime = 1;
	int i;
	int j;
	int result = 1;
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

		result *= pow(prime,fmin(alfa,beta));

	
		if (alfa)
			printf("%d[%d]\n", prime, alfa);
		if (beta)
			printf("%d[%d]\n", prime, beta);
	}
	return result;
	
}
 
int main(void)
{

	int i;
	/*
	  for(i=2; i <100; i++)
	    printf("%d -> %d\n", i, isPrime(i));
	  */

	/*
	  for(i = 2; i<100; i++)
	    if (isPrime(i))
	      printf("%d -> %d\n\a", i, getNextPrime(i));
	  */

	int number = 100;
	int counter;
	int prime;

	printf("NWD: %d",nwd(100,101));

	// for(i = 1; i<= number; i = prime)
	// {
	// 	counter = 0;
	// 	prime = getNextPrime(i);
	// 	while ( number > 1 )
	// 	{
	// 		if (number % prime == 0)
	// 		{
	// 			number /= prime;
	// 			counter ++;
	// 		}
	// 		else
	// 		break;
	// 	}
	// 	if (counter)
	// 		printf("%d[%d]\n", prime, counter);
	// }

	getchar();
	return EXIT_OK;
}
