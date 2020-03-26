#include <ncurses.h>
#include <stdlib.h>
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

void control(WINDOW *win) {
  int ch;

  while (true) {
    ch = getch();
    int y, x;
    refresh();
    getyx(win, y, x);
    
    switch (ch) {
    case KEY_F(1):
      endwin();
      exit(0);
      break;
    case KEY_F(2):
      clear();
      makeUI();
      break;
    case KEY_BACKSPACE:
      wmove(win, y, x - 1);
      delch();
      break;
    case KEY_LEFT:
      wmove(win, y, x - 1);
      break;
    case KEY_RIGHT:
      wmove(win, y, x + 1);
      break;
    case KEY_UP:
      wmove(win, y - 1, x);
      break;
    case KEY_DOWN:
      wmove(win, y + 1, x);
      break;
    default:
      addch(ch);
    }

    refresh();

  }
}

int main() {
  makeUI();
  control(stdscr);
}
