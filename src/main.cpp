#include <iostream>
#include <ncurses.h>

int main (int argc, char *argv[]) {
	initscr();
	


	WINDOW *win = newwin(15, 17, 2, 10);
    refresh();

    // making box border with default border styles
    box(win, 0, 0);

    // move and print in window
    mvwprintw(win, 0, 1, "Greeter");
    mvwprintw(win, 1, 1, "Hello");

    // refreshing the window
    wrefresh(win);

    refresh();
    getch();
    endwin();
	return 0;
}
