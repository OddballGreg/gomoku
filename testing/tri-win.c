#include <panel.h>
#include <ncurses.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>

# define ROWS    19
# define COLUMNS 19

# define STAT_X  20
# define INFO_X  20

# define WIN_BOARD  0
# define WIN_STATS  1
# define WIN_INFO   2

void	get_boardcr(int colums, int rows, int *x, int *y)
{
	*y = 2 + rows + (rows - 1);
	*x = 4 + (colums * 3) + (colums - 1);
}

void    draw_win(int x, int colour, WINDOW *win, const char *title)
{
    int     k;

    box(win, 0, 0);
    mvwaddch(win, 2, 0, ACS_LTEE);
    mvwaddch(win, 2, x - 1, ACS_RTEE);
    k = 0;
    while (++k < x - 1)
        mvwaddch(win, 2, k, ACS_HLINE);
    if (colour > 0)
        attron(COLOR_PAIR(colour));
    mvwaddstr(win, 1, (x - strlen(title)) / 2, title);
    if (colour > 0)
        attroff(COLOR_PAIR(colour));
    wmove(win, 3, 1);
}

void	manage_wins(WINDOW *win[3], PANEL *panel[3])
{
	int		x;
	int		y;

	get_boardcr(COLUMNS, ROWS, &x, &y);
	if (y + 3 > LINES)
		printw("window is too small (min height = %d).", (y + 4));
	else if (x + 5 + STAT_X + INFO_X < COLS)
	{
		win[WIN_BOARD] = newwin(y, x, (LINES - y) / 2, (COLS - x) / 2);
		win[WIN_STATS] = newwin(y, STAT_X, (LINES - y) / 2, ((COLS + x) / 2) + 2);
		win[WIN_INFO] = newwin(y, INFO_X, (LINES - y) / 2, ((COLS - x) / 2) - INFO_X - 2);
		draw_win(x, 1, win[WIN_BOARD], "Board");
		draw_win(STAT_X, 2, win[WIN_STATS], "Stats");
		draw_win(INFO_X, 3, win[WIN_INFO], "Info");
		panel[WIN_BOARD] = new_panel(win[WIN_BOARD]);
		panel[WIN_INFO] = new_panel(win[WIN_INFO]);
		panel[WIN_STATS] = new_panel(win[WIN_STATS]);
	}
	else if (x + 3 + STAT_X < COLS)
	{
		win[WIN_BOARD] = newwin(y, x, (LINES - y) / 2, (COLS - (x + STAT_X)) / 2 - 1);
		win[WIN_STATS] = newwin(y, STAT_X, (LINES - y) / 2, ((COLS + x - STAT_X) / 2) + 1);
		win[WIN_INFO] = NULL;
		draw_win(x, 1, win[WIN_BOARD], "Board");
		draw_win(STAT_X, 2, win[WIN_STATS], "Stats");
		panel[WIN_BOARD] = new_panel(win[WIN_BOARD]);
		panel[WIN_INFO] = NULL;
		panel[WIN_STATS] = new_panel(win[WIN_STATS]);
	}
	else if (x + 2 < COLS)
	{
		win[WIN_BOARD] = newwin(y, x, (LINES - y) / 2, (COLS - x) / 2);
		win[WIN_STATS] = NULL;
		win[WIN_INFO] = NULL;
		draw_win(x, 1, win[WIN_BOARD], "Board");
		panel[WIN_BOARD] = new_panel(win[WIN_BOARD]);
		panel[WIN_INFO] = NULL;
		panel[WIN_STATS] =NULL;
	}
	else
		printw("window is too small (min width = %d).", (x + 3));
}

int		main()
{
	WINDOW	*win[3];
	PANEL	*panel[3];
	

	initscr();
	start_color();
	cbreak();
	noecho();

	manage_wins(win, panel);

	update_panels();
	doupdate();

	getch();
	endwin();
}