#include <iostream>
#include <ncurses.h>
using namespace std;

int yMax, xMax;

int main (int argc, char *argv[]) {
	initscr();
	refresh();

	getmaxyx(stdscr,yMax ,xMax);

	WINDOW *win = newwin(yMax-2, xMax-2 , 1, 1);
	
	box(win, 0, 0);

    	wrefresh(win);

    	refresh();
    	getch();
	endwin();
	return 0;
}
