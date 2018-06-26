#include <ncurses.h>

void help() {
  wprintw(stdscr, "Usage: (WIP)"); // Rdr: I'll get back to this later.
}

int main(int argc, char** argv) {
  initscr();
  start_color();
  cbreak();
  
  // Initialize colors:
  init_pair(1, COLOR_WHITE, COLOR_BLACK); // Standard color
  init_pair(2, COLOR_RED, COLOR_BLACK); // Error color
  
  attron(COLOR_PAIR(1));
  wprintw(stdscr, "Lightning Creations Unified Package Manager\n");
  wprintw(stdscr, "by InfernoDeity and Rdrpenguin\n");
  wprintw(stdscr, "Version 1.0\n");
  wrefresh(stdscr);
  
  if(argc == 1) {
    attron(COLOR_PAIR(2));
    wprintw(stdscr, "ERROR! Not enough arguments!\n");
    help();
    return 1;
  }
  wprintw("WIP"); // Rdr: I'll get back to this later.
  return 0;
}
