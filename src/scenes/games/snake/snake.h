#ifndef SNAKE_H
#define SNAKE_H

#include <stdio.h>
#include <stdint.h>
#include "../../../utils.h"

typedef struct{
	uint8_t x;
	uint8_t y;
}Point;

struct Tail{
	Point pos;
	struct Tail* nextTail;
};

typedef struct{
	Point head;
	struct Tail* tail;
	uint16_t size;
	char direction; //TO CHECK IF YOU CAN TURN 
}Snake;


#define WIN_X 80
#define WIN_Y 20

void changeSnakeDirection(Snake* snake, char);
void addTail(Snake* snake);
void killSnake(Snake* snake);

#endif
