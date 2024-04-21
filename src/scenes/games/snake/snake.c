#include "snake.h"

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
	int direction;
}Snake;

char screenObjects[WIN_X][WIN_Y];

int centerX = 0;
int centerY = 0;

void initScreen();
void moveSnake(Snake* snake, char key);
void drawRectangle(int, int);
void drawPoint(Point p, char image);
void drawSnake(Snake snake);
void clearPoint(Point p);

struct winsize getWindowSize(){
	struct winsize window;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &window);

	return window;
}

int getch()
{
    struct termios oldattr, newattr;
    int ch;
    tcgetattr( STDIN_FILENO, &oldattr );
    newattr = oldattr;
    newattr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr( STDIN_FILENO, TCSANOW, &newattr );
    ch = getchar();
    tcsetattr( STDIN_FILENO, TCSANOW, &oldattr );
    return ch;
}

#define NB_ENABLE 1
#define NB_DISABLE 0

void nonblock(int state)
{
    struct termios ttystate;

    tcgetattr(STDIN_FILENO, &ttystate);

    if (state==NB_ENABLE)
    {
        ttystate.c_lflag &= ~(ICANON | ECHO);
    }
    else if (state==NB_DISABLE)
    {
        ttystate.c_lflag |= (ICANON | ECHO);
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &ttystate);
}


int _kbhit()
{
    struct termios oldAttr, newAttr;
    tcgetattr(STDIN_FILENO, &oldAttr);

    newAttr = oldAttr;
    newAttr.c_lflag &= ~( ICANON | ECHO );
    tcsetattr(STDIN_FILENO, TCSANOW, &newAttr);

    setbuf(stdin, NULL);
    int byteswaiting;
    ioctl(STDIN_FILENO, FIONREAD, &byteswaiting);

    tcsetattr(STDIN_FILENO, TCSANOW, &oldAttr);

    return byteswaiting;
}


int main(){
	struct winsize win = getWindowSize();
	centerX = (win.ws_col/2) - WIN_X/2;
	centerY = win.ws_row/2;
	char key = 'i';

	Point head = { WIN_X/2, WIN_Y/2};
	Snake snake = { head, head, 1, 0 };

	//Hide Cursor
	printf("\x1b[?25l");
    nonblock(NB_ENABLE);

	clearScreen();
	drawRectangle(WIN_X, WIN_Y);
	Point testP = {33,5};
	drawPoint(testP, '1');

	moveCursor(head.x, head.y);

	while(key != ESC){
		while(_kbhit())
		{
			key = getch();
			if(key == '\033'){
				getch();
				key = getch();
			}
		}

		// clearScreen();
		clearPoint(snake.tail);
		moveSnake(&snake, key);
		// drawRectangle(WIN_X, WIN_Y);
		drawSnake(snake);

		fflush(stdout);
		usleep(1000 * 100);
	}

	nonblock(NB_DISABLE);
	printf("\x1b[?25h");
	clearScreen();
}

void moveSnake(Snake* snake, char key){
	snake->tail = snake->head;
	int x = snake->head.x;
	int y = snake->head.y;

	switch(key){
		case UP_ARROW: 
						y--;
						if(y < 0 ) y = WIN_Y ;
						break;
			case DOWN_ARROW:
						y++;
						if(y > WIN_Y ) y = 0;
						break;
		case RIGHT_ARROW:
						x++;
						if(x > WIN_X ) x = 0;
						break;
		case LEFT_ARROW:
						x--;
						if(x < 0 ) x = WIN_X ;
						break;
		default:		
						x++;
						if(x > WIN_X ) x = 0;
						break;
	}

	snake->head.x = x;
	snake->head.y = y;
}

void drawSnake(Snake snake){
	drawPoint(snake.head, '@');
}

void drawPoint(Point p, char image){
	screenObjects[p.x][p.y] = image;
	moveCursor(p.y + 2, p.x + centerX + 2);
	printf("%c", image);
	moveLeft(1);
}

void clearPoint(Point p){
	screenObjects[p.x][p.y] = 0;
	moveCursor(p.x, p.y);
	printf(" ");
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
