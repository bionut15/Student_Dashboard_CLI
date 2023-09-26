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
void handleResize()
{
	endwin(); 
	refresh();
	initscr();
	refresh(); 
}
void print_center(WINDOW *win,int start_row , std::string text)
{
	int textLen = text.length(); 
	if (textLen< xMax/2) {
		int center_col = win ->_maxx/2;
		int ajusted_col = center_col - text.length();
		mvwprintw(win, start_row, ajusted_col , text.c_str());
	}
}
void drawLogo(WINDOW *win)
{
	std::string logo = R"(	
		  _______ _________          ______   _______  _       _________   ______   _______  _______           ______   _______  _______  _______  ______  
		 (  ____ \\__   __/|\     /|(  __  \ (  ____ \( (    /|\__   __/  (  __  \ (  ___  )(  ____ \|\     /|(  ___ \ (  ___  )(  ___  )(  ____ )(  __  \ 
		 | (    \/   ) (   | )   ( || (  \  )| (    \/|  \  ( |   ) (     | (  \  )| (   ) || (    \/| )   ( || (   ) )| (   ) || (   ) || (    )|| (  \  \
		 | (_____    | |   | |   | || |   ) || (__    |   \ | |   | |     | |   ) || (___) || (_____ | (___) || (__/ / | |   | || (___) || (____)|| |   ) |
		 (_____  )   | |   | |   | || |   | ||  __)   | (\ \) |   | |     | |   | ||  ___  |(_____  )|  ___  ||  __ (  | |   | ||  ___  ||     __)| |   | |
		       ) |   | |   | |   | || |   ) || (      | | \   |   | |     | |   ) || (   ) |      ) || (   ) || (  \ \ | |   | || (   ) || (\ (   | |   ) |
		 /\____) |   | |   | (___) || (__/  )| (____/\| )  \  |   | |     | (__/  )| )   ( |/\____) || )   ( || )___) )| (___) || )   ( || ) \ \__| (__/  )
		 \_______)   )_(   (_______)(______/ (_______/|/    )_)   )_(     (______/ |/     \|\_______)|/     \||/ \___/ (_______)|/     \||/   \__/(______/ 	)";
                                                                                                                                                  
	//needs to print centered fixed
	mvwprintw(win,2,xMax/2-64, "%s", logo.c_str());
}
void writeInfoText(WINDOW *win)
{
	print_center(win,yMax/3 +3,"Right now u have "  "at");
}

void drawtable(WINDOW *win,std::string timeTable[7][6], int numrows, int numcols) 
{
	for (int i = 0; i < numrows; i++) 
	{
		for (int j = 0; j < numcols; j++) 
		{
			//hardcoded ik its bad but it works
			int centeredCol = xMax/2 - 106/2; 
			mvwprintw(win,i+xMax/10, j * 20 + centeredCol, "%-15s", timeTable[i][j].c_str());
		};
	};
};	

int main () 
{
	setlocale(LC_ALL, "");
	intrflush(stdscr, FALSE);
	initscr();
	noecho();
	raw();
	cbreak();
	start_color();
	nodelay(stdscr, TRUE);
	curs_set(0);
	keypad(stdscr, TRUE);
	getmaxyx(stdscr,yMax ,xMax);

	WINDOW *win = newwin(yMax-2, xMax-2 , 1, 1);

	scrollok(win, TRUE);
	refresh();	
	//mvwprintw(win, 3,4,"%d\n",getWeekNumber());
	drawLogo(win);
	wrefresh(win);
	writeInfoText(win);
	drawtable(win, timeTable ,7 ,6 );
	
	box(win, 0, 0);
	wrefresh(win);

	//to be modified with a switch case 
	while ((exitKey = getch()) != 'q') {

	}
	
	//probrably spould be check out
	//signal(SIGWINCH, handleResize);
	
	endwin();
	return 0;
}
