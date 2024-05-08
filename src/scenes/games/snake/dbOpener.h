#ifndef db_opener_h
#define db_opener_h

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_BUFFER_LEN 80

void getQuestion(char* question ,char* correctAnswer);
int countFileLines(FILE* fileptr);

#endif
