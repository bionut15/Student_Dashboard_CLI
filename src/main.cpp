#include <iostream>
#include <string>
#include <locale.h>
#include <ncurses.h>
#include <signal.h>
#include "../includes/weeknumber.hpp"

int numrows, numcols , yMax, xMax;
int weekNumberRounded;
char exitKey;



std::string timeTable[7][6] = {
	{"Program", "Monday", "Tuesday","Wednesday", "Thursday", "Friday"},
	{" 8:00 - 10:00", "header2", "header3","header1", "header2", "header3"},
	{"10:00 - 12:00", "header2", "header3","header1", "header2", "header3"},
	{"12:00 - 14:00", "header", "header3","header1", "header2", "header3"},
	{"14:00 - 16:00", "header2", "header3","header1", "header2", "hwwwwwwwwweader3"},
	{"16:00 - 18:00", "header2", "header3","header1", "header2", "header3"},
	{"18:00 - 20:00", "header2", "header3","header1", "headwiwwjwwjwer2", "header3"},
};

// Broken need fixing
void handleResize(int signal)
{
	endwin(); 
	refresh();
	initscr();
	refresh(); 
}
void print_center(WINDOW *win,int start_row , std::string text)
{
	int center_col = win ->_maxx/2;
	int half_length = text.length();
	int ajusted_col = center_col - half_length;
	
	mvwprintw(win, start_row, ajusted_col , text.c_str());
}
//broken
void drawLogo(WINDOW *win)
{
	refresh();
	//logo not printing corectly
	std::string logo = R"(	
	███████╗████████╗██╗   ██╗██████╗ ███████╗███╗   ██╗████████╗    ██████╗  █████╗ ███████╗██╗  ██╗██████╗  ██████╗  █████╗ ██████╗ ██████╗
	██╔════╝╚══██╔══╝██║   ██║██╔══██╗██╔════╝████╗  ██║╚══██╔══╝    ██╔══██╗██╔══██╗██╔════╝██║  ██║██╔══██╗██╔═══██╗██╔══██╗██╔══██╗██╔══██╗
	███████╗   ██║   ██║   ██║██║  ██║█████╗  ██╔██╗ ██║   ██║       ██║  ██║███████║███████╗███████║██████╔╝██║   ██║███████║██████╔╝██║  ██║
	╚════██║   ██║   ██║   ██║██║  ██║██╔══╝  ██║╚██╗██║   ██║       ██║  ██║██╔══██║╚════██║██╔══██║██╔══██╗██║   ██║██╔══██║██╔══██╗██║  ██║
	███████║   ██║   ╚██████╔╝██████╔╝███████╗██║ ╚████║   ██║       ██████╔╝██║  ██║███████║██║  ██║██████╔╝╚██████╔╝██║  ██║██║  ██║██████╔╝
	╚══════╝   ╚═╝    ╚═════╝ ╚═════╝ ╚══════╝╚═╝  ╚═══╝   ╚═╝       ╚═════╝ ╚═╝  ╚═╝╚══════╝╚═╝  ╚═╝╚═════╝  ╚═════╝ ╚═╝  ╚═╝╚═╝  ╚═╝╚═════╝	)";
	print_center(stdscr,yMax/7,"Student Dashboard");
}
void writeInfoText(WINDOW *win)
{
	print_center(stdscr,yMax/5,"Right now u have " "" "at");
}

void drawtable(WINDOW *win,std::string timeTable[7][6], int numrows, int numcols) 
{
	for (int i = 0; i < numrows; i++) 
	{
		for (int j = 0; j < numcols; j++) 
		{
			//hardcoded ik its bad but it works
			int centeredCol = xMax/2 - 106/2; 
			mvwprintw(win,i+xMax/15, j * 20 + centeredCol, "%-15s", timeTable[i][j].c_str());
		};
	};
};	

int main (int argc, char *argv[]) 
{
	initscr();
	noecho();
	setlocale(LC_ALL, "");
	raw();
	cbreak();
	nodelay(stdscr, TRUE);
	curs_set(0);
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
	getmaxyx(stdscr,yMax ,xMax);

	WINDOW *win = newwin(yMax-2, xMax-2 , 1, 1);
	//testing
	//WINDOW *secondary = newwin(yMax-2, xMax/2 , yMax/2, xMax/2);
	refresh();	

	getWeekNumber();
	//mvwprintw(win, 3,4,to_string(weekNumberRounded))

	writeInfoText(win);
	drawtable(win, timeTable ,7 ,6 );
	
	box(win, 0, 0);
	wrefresh(win);

	//to be modified with a switch case 
	while ((exitKey = getch()) != 'q') {

	}
	
	//probrably spould be check out
	signal(SIGWINCH, handleResize);
	
	endwin();
	return 0;
}
