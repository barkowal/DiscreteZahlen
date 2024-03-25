#ifndef utils_h
#define utils_h
	
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <sys/ioctl.h>

int getch();
struct winsize getWindowSize();

#endif
