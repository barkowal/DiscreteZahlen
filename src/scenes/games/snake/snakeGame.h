#ifndef SNAKEGAME_H
#define SNAKEGAME_H

#include "snake.h"
#include "../../../utils.h"
#include <time.h>

int snakeGame();

void initScreen();
void drawRectangle(int, int);
void drawPoint(Point p, char image);
void clearPoint(Point p);

void moveSnake(Snake* snake);
void drawSnake(Snake snake);

void drawTail(Snake snake);
void moveTail(Snake snake);

int checkCollide(Point p);
void spawnPoints();


#endif
