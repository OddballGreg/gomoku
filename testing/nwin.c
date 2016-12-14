#include <panel.h>
#include <ncurses.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>

# define ROWS    19
# define COLUMNS 19

void    draw_win(int x, int colour, WINDOW *win, const char *title)
{
    int     k;

    box(win, 0, 0);
    mvwaddch(win, 2, 0, ACS_LTEE);
    mvwaddch(win, 2, x - 1, ACS_RTEE);
    k = 0;
    while (++k < x - 1)
        mvwaddch(win, 2, k, ACS_HLINE);
    mvwaddstr(win, 1, (x - strlen(title)) / 2, title);
}

int     main()
{
    WINDOW  *win;
    PANEL   *panel;
    int     x;
    int     y;

    initscr();
    start_color();
    cbreak();
    noecho();

    win = newwin(10, 10, (LINES - y) / 2, (COLS - x) / 2 );
    init_pair(1, COLOR_GREEN, COLOR_BLACK);
    panel = new_panel(win);

    draw_win(10, 1, win, "Hello!");
    update_panels();
	doupdate();

    getch();
    endwin();
}
