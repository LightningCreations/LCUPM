#include <ncurses.h>

void help() {
  wprintw("Usage: (WIP)"); // Rdr: I'll get back to this later.
}

int main(int argc, char** argv) {
  initscr();
  start_color();
  cbreak();
  
  // Initialize colors:
  initPair(1, COLOR_WHITE, COLOR_BLACK); // Standard color
  initPair(2, COLOR_RED, COLOR_BLACK); // Error color
  
  attron(COLOR_PAIR(1));
  wprintw("Lightning Creations Unified Package Manager\n", stdscr);
  wprintw("by InfernoDeity and Rdrpenguin\n");
  wprintw("Version 1.0\n");
  wrefresh(stdscr);
  
  if(argc == 1) {
    attron(COLOR_PAIR(2));
    wprintw("ERROR! Not enough arguments!\n");
    help();
    return 1;
  }
  wprintw("WIP"); // Rdr: I'll get back to this later.
  return 0;
}
