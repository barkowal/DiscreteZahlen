#include "dbOpener.h"


int countFileLines(FILE* fileptr){
	int lines = 0;
	char buff[65536];

	for(;;){
		unsigned int len = fread( buff, 1, 65536, fileptr);
		int i;

		for(i=0; i < len; i++){
			if( buff[i] == '\n')
				lines++;
		}

		if(feof(fileptr))
			break;
	}
	rewind(fileptr);

	return lines;
}


void getQuestion(char* question ,char* correctAnswer){
	srand(time(NULL));
	FILE* fileptr = fopen("pytania.txt", "r");
	if(fileptr == NULL){
		return;
	}

	int lines = countFileLines(fileptr);
	if(lines < 2)
		return;

	int rndNb = random()%lines - 1;
	if(rndNb%2 != 0)
		rndNb++;

	int i;
	for(i=0; i<rndNb; i++)
		fgets(question, MAX_BUFFER_LEN, fileptr);

	fgets(question, MAX_BUFFER_LEN, fileptr);
	*(correctAnswer) = fgetc(fileptr);

	fclose(fileptr);
}
