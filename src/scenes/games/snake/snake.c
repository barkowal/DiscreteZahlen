#include "snake.h"

void changeSnakeDirection(Snake* snake, char key){
	switch(key){
		case UP_ARROW: 
		case 'w':
		case 'k':
						if(snake->direction * -1 == 1)
							snake->direction = -1;
						else
							snake->direction = 1;
						break;

		case DOWN_ARROW:
		case 's':
		case 'j':
						if(snake->direction * -1 == -1)
							snake->direction = 1;
						else
							snake->direction = -1;
						break;

		case RIGHT_ARROW:
		case 'd':
		case 'l':
						if(snake->direction * -1 == 2)
							snake->direction = -2;
						else 
							snake->direction = 2;
						break;

		case LEFT_ARROW:
		case 'a':
		case 'h':
						if(snake->direction * -1 == -2)
							snake->direction = 2;
						else
							snake->direction = -2;
						break;
	}
}




void addTail(Snake* snake){
	struct Tail* tail = snake->tail;
	struct Tail* newEnd = (struct Tail*)malloc( sizeof(struct Tail) );
	Point newPos = snake->head;
	newEnd->nextTail = NULL;

	if( snake->tail == NULL){
		newPos.x++;
		newEnd->pos = newPos;

		snake->tail = newEnd;
		return;
	}

	while(tail->nextTail != NULL){
		newPos = tail->pos;
		tail = tail->nextTail;
	}

	newPos.x++;
	newEnd->pos = newPos;
	tail->nextTail = newEnd;
}



void killSnake(Snake* snake){
	struct Tail* tail = snake->tail;
	struct Tail* nextTail = snake->tail;

	while(tail != NULL){
		nextTail = tail->nextTail;
		free(tail);
		tail = nextTail;
	}

}
