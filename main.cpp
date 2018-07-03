#include <stdlib.h>

#include <ncurses.h>

void quit() {
	printw("Press any key to exit...");
	refresh();
	getch();
	endwin();
	exit(0);
}

void help(char* name) {
	attron(COLOR_PAIR(1));
	printw("Usage:\n");
	printw("\t%s fetch <packagename>\n", name);
}

int main(int argc, char** argv) {
	initscr();
	use_default_colors();
	start_color();
	cbreak();

	// Initialize colors:
	init_pair(1, COLOR_WHITE, -1); // Standard color
	init_pair(2, COLOR_RED, -1); // Error color
	init_pair(3, COLOR_GREEN, -1); // Confirmation color

	attron(COLOR_PAIR(3));
	printw("Lightning Creations Unified Package Manager\n");
	attron(COLOR_PAIR(1));
	printw("by InfernoDeity and Rdrpenguin\n");
	printw("Version 1.0\n");
	refresh();

	if(argc == 1) {
		attron(COLOR_PAIR(2));
		printw("ERROR! Not enough arguments!\n");
		help(argv[0]);
		quit();
	}
	printw("WIP"); // Rdr: I'll get back to this later.
	quit();
}
