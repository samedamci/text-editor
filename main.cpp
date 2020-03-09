#include <ncurses.h>
#include <string.h>

void makeUI() {
  int row, col;
  initscr();
  keypad(stdscr, TRUE);
  getmaxyx(stdscr, row, col);
  noecho();

  start_color();
  init_pair(1, COLOR_BLACK, COLOR_BLUE);
  mvprintw(row - 2, 0, "F1");
  mvprintw(row - 2, 7, "F2");
  attron(COLOR_PAIR(1));
  mvprintw(row - 2, 2, "Kill");
  mvprintw(row - 2, 9, "Clear");
  mvprintw(0, 0, "");
  attroff(COLOR_PAIR(1));
}

void control() {
  int ch;

  while (true) {
    ch = getch();
    refresh();

    if (ch == KEY_F(1)) {
      break;
      endwin();
    } else if (ch == KEY_F(2)) {
      clear();
      makeUI();
      refresh();
    } else if (ch == KEY_BACKSPACE) {
      printw("\b \b");
      refresh();
    } else
      addch(ch);
  }
}

int main() {
  makeUI();
  control();
}
