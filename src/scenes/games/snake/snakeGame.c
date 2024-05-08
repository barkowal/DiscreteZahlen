#include "snakeGame.h"

char screenObjects[WIN_X][WIN_Y];
Point answers[ANSWER_NB];

char* gameOver = "\
  /$$$$$$   /$$$$$$  /$$      /$$ /$$$$$$$$      \n\
 /$$__  $$ /$$__  $$| $$$    /$$$| $$_____/      \n\
| $$  \\__/| $$  \\ $$| $$$$  /$$$$| $$            \n\
| $$ /$$$$| $$$$$$$$| $$ $$/$$ $$| $$$$$         \n\
| $$|_  $$| $$__  $$| $$  $$$| $$| $$__/         \n\
| $$  \\ $$| $$  | $$| $$\\  $ | $$| $$            \n\
|  $$$$$$/| $$  | $$| $$ \\/  | $$| $$$$$$$$      \n\
 \\______/ |__/  |__/|__/     |__/|________/      \n\
  /$$$$$$  /$$    /$$ /$$$$$$$$ /$$$$$$$         \n\
 /$$__  $$| $$   | $$| $$_____/| $$__  $$        \n\
| $$  \\ $$| $$   | $$| $$      | $$  \\ $$        \n\
| $$  | $$|  $$ / $$/| $$$$$   | $$$$$$$/        \n\
| $$  | $$ \\  $$ $$/ | $$__/   | $$__  $$        \n\
| $$  | $$  \\  $$$/  | $$      | $$  \\ $$        \n\
|  $$$$$$/   \\  $/   | $$$$$$$$| $$  | $$        \n\
 \\______/     \\_/    |________/|__/  |__/ \n\
";	

int snakeGame(){
	char key = 'i';
	int collision = 0;

	Point head = { WIN_X/2, WIN_Y/2};
	struct Tail* tail = NULL;
	Snake snake = { head, tail, 1, 2 };
	addTail(&snake);
	addTail(&snake);

	//Hide Cursor
	printf("\x1b[?25l");
    nonblock(NB_ENABLE);

	clearScreen();
	drawRectangle(WIN_X, WIN_Y);

	spawnPoints();


	while(key != ESC){
		while(_kbhit())
		{
			key = getch();
			if(key == '\033'){
				getch();
				key = getch();
			}
			changeSnakeDirection(&snake, key);
		}

		// clearScreen();

		moveSnake(&snake);
		collision = checkCollide(snake.head);


		if( collision == 1 ){
			addTail(&snake);
			spawnPoints();
		}
		if( collision == 2 )
			break;

		// drawRectangle(WIN_X, WIN_Y);
		drawSnake(snake);
		// printf("%d,%d",snake.head.x, snake.head.y);
		
		fflush(stdout);
		usleep(1000 * 100);
	}


	nonblock(NB_DISABLE);

	printf("\x1b[?25h");
	killSnake(&snake);

	clearScreen();
	printf("%s",gameOver);
	getch();

	return 0;
}


void spawnPoints(){
	srand(time(NULL));
	char symbols[5] = {'A', 'B', 'C', 'D', 'H'};
	char question[MAX_BUFFER_LEN];
	char correctAnswer;
	Point rndPos;
	
	clearAnswers();
	getQuestion(question, &correctAnswer);
	printQuestion(question);

	int i;
	for(i=0; i<5; i++){
		rndPos.x = random()%WIN_X;
		rndPos.y = random()%WIN_Y;
		answers[i] = rndPos;

		drawPoint(rndPos, symbols[i]);

		if( symbols[i] == correctAnswer )
			answers[ANSWER_NB-1] = rndPos;
	}
}


void clearAnswers(){
	int i;
	for(i=0; i<ANSWER_NB; i++){
		clearPoint(answers[i]);
	}
}


void moveSnake(Snake* snake){
	moveTail(*snake);
	int x = snake->head.x;
	int y = snake->head.y;
	int dir = snake->direction + 3;
	switch(dir){
		case 4: 
						y--;
						if(y < 0 ) y = WIN_Y ;
						break;
		case 2:
						y++;
						if(y > WIN_Y ) y = 0;
						break;
		case 5:
						x++;
						if(x > WIN_X ) x = 0;
						break;
		case 1:
						x--;
						if(x < 0 ) x = WIN_X ;
						break;
	}

	snake->head.x = x;
	snake->head.y = y;
}


void moveTail(Snake snake){
	Point pos = snake.head;
	Point buffPos = snake.head;
	struct Tail* tail = snake.tail;

	while( tail!=NULL ){
		buffPos = tail->pos ;
		tail->pos = pos;
		pos = buffPos;
		tail = tail->nextTail;
	}

}


void drawSnake(Snake snake){
	drawPoint(snake.head, '@');
	drawTail(snake);
}


void drawTail(Snake snake){
	struct Tail* tail = snake.tail;

	if (snake.tail == NULL)
		return;

	Point clearTail = tail->pos;
	while(tail != NULL){
		drawPoint(tail->pos, '#');
		clearTail = tail->pos;
		tail = tail->nextTail;
	}
	clearPoint(clearTail);
}


void drawPoint(Point p, char image){
	struct winsize win = getWindowSize();
	const int centerX = (win.ws_col/2) - WIN_X/2;

	screenObjects[p.x][p.y] = image;
	moveCursor(p.y + 2, p.x + centerX + 2);
	printf("%c", image);
	moveLeft(1);
}


void clearPoint(Point p){
	struct winsize win = getWindowSize();
	const int centerX = (win.ws_col/2) - WIN_X/2;

	screenObjects[p.x][p.y] = 0;
	moveCursor(p.y + 2, p.x + centerX + 2);
	printf(" ");
	moveLeft(1);
}


int checkCollide(Point p){
	char collisionObject = screenObjects[p.x][p.y];

	if( p.x == answers[ANSWER_NB - 1].x && 
		p.y == answers[ANSWER_NB - 1].y ){
		return 1;
	}

	switch( collisionObject ){
		case 'A': return 2;
		case 'B': return 2;
		case 'C': return 2;
		case 'D': return 2;
		case '#': return 2;
		case 'H': changeAnswerColors(); return 0;
		default:  return 0;
	}
}


void drawRectangle(int x, int y){
	int i;
	struct winsize win = getWindowSize();
	int startX = (win.ws_col/2) - x/2;

	moveRight(startX + 1);

	for(i = 0; i <= x; i++){
		printf("=");
	}

	printf("\n");

	for(i=0; i<=y; i++){
		moveRight(startX);
		printf("|");	
		moveRight(x + 1);
		printf("|\n");	
	}
 
	moveRight(startX + 1);
	for(i = 0; i <= x; i++){
		printf("=");
	}

	printf("\n");
	
}


void printQuestion(char* question){
	moveCursor(WIN_Y+5, 0);
	showInput();

	printf("%s",question);
}


void changeAnswerColors(){
	Point correctPoint = answers[ANSWER_NB-1];
	char symbols[ANSWER_NB] = {'A', 'B', 'C', 'D'};
	int i;
	changeCol_RED();
	for(i=0; i<ANSWER_NB-2; i++){
		drawPoint(answers[i], symbols[i]);
	}
	changeCol_GREEN();
	
	drawPoint(answers[ANSWER_NB-1], screenObjects[correctPoint.x][correctPoint.y]);
	changeCol_DEFAULT();
}
