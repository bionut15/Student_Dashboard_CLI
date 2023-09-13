#include <iostream>
#include <locale.h>
#include <ncurses.h>
#include <string>

int numrows, numcols , yMax, xMax;
char exitKey;

const char *timeTable[5][8] = {
	{"header1", "header2", "header3"},
	{"header1", "header2", "header3"},
	{"header1", "header2", "header3"},
	{"data1", "data2", "data3"},
	{"data4", "data5", "data6"},
};

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

void drawtable(WINDOW *win, const char* timeTable[5][8], int numrows, int numcols) 
{
	for (int i = 0; i < numrows; i++) 
	{
		for (int j = 0; j < numcols; j++) 
		{
			mvwprintw(win,i+15, j * 20, "%-20s", timeTable[i][j]);
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
	curs_set(0);
	keypad(stdscr, TRUE);

	getmaxyx(stdscr,yMax ,xMax);

	WINDOW *win = newwin(yMax-2, xMax-2 , 1, 1);
	refresh();	

	drawLogo(win);
	writeInfoText(win);
	drawtable(win, timeTable ,5 ,8 );

	box(win, 0, 0);
	wrefresh(win);
	
	//to be modified with a switch case 
	while ((exitKey = getch()) != 'q') {

	}

	endwin();
	return 0;
}
