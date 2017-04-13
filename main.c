#include "stdlib.h"
#include "grid.h"
#include "ncurses.h"
#include "form.h"
#include "wait.h"


int main() {
	grid *g = new_grid(9, 9);

	initscr();
	cbreak();
	noecho();
	nonl();
	intrflush(stdscr, FALSE);
	keypad(stdscr, TRUE);

	refresh();
	printw("Type anything...\n");
	refresh();
	getch();
	erase();
	print_grid(g);
	refresh();
	getch();
	erase();

	delete_grid(g);

	refresh();
	endwin();
	
	return 0;
}


