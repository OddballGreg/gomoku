#include <panel.h>
#include <ncurses.h>
#include <strings.h>
#include <string.h>
#include <stdio.h>

# define ROWS    20
# define COLUMNS 20

# define STAT_X  20
# define INFO_X  20

# define WIN_BOARD  0
# define WIN_STATS  1
# define WIN_INFO   2

int		is_vline(int pos_x)
{
	if (pos_x == 1)
		return (0);
	return (((pos_x - 1) % 4) == 0);
}

int		is_plus(int pos_x, int	pos_y)
{
	if (pos_y == 1)
		return (0);
	return ((((pos_y - 2) % 2) == 0) && is_vline(pos_x));
}

void	get_boardcr(int colums, int rows, int *x, int *y)
{
	*y = 4 + rows + (rows - 1);
	*x = 4 + (colums * 3) + (colums - 1);
}

void	get_boardxy(int pos_x, int pos_y, int *x, int *y)
{
	*y = (pos_y - 1) * 2 + 4;
	*x = (pos_x - 1) * 4 + 5;
}

void	draw_grid(WINDOW *win, int columns, int rows)
{
	int		pos_x;
	int		pos_y;
	int		max_x;
	int		max_y;
	
	get_boardcr(columns, rows, &max_x, &max_y);
	pos_x = 1;
	while (++pos_x < max_x - 2)
	{
		pos_y = 2;
		while (++pos_y < max_y - 1)
		{
			if (is_plus(pos_x, pos_y))
				mvwaddch(win, pos_y, pos_x, ACS_PLUS);
			else if (is_vline(pos_x))
				mvwaddch(win, pos_y, pos_x, ACS_VLINE);
			else if ((pos_y % 2) == 0)
				mvwaddch(win, pos_y, pos_x, ACS_HLINE);
		}
	}
}

void	run_prog(WINDOW *win)
{
	static char	board[COLUMNS][ROWS];
	int			pos_x;
	int			pos_y;
	int			move;
	int			x;
	int			y;
	char		buff;

	pos_x = 1;
	move = 1;
	pos_y = 1;
	while ((buff = getch()) != 'e')
	{
		if (buff == 'd' || buff == 'C')
			pos_x = (pos_x == COLUMNS - 1) ? 1 : pos_x + 1;
		else if (buff == 'a' || buff == 'D')
			pos_x = (pos_x == 1) ? COLUMNS - 1 : pos_x - 1;
		else if (buff == 'w' || buff == 'A')
			pos_y = (pos_y == 1) ? ROWS - 1: pos_y - 1;
		else if (buff == 's' || buff == 'B')
			pos_y = (pos_y == ROWS - 1) ? 1 : pos_y + 1;
		else if ((buff == '\n' || buff == 32) && !board[pos_x - 1][pos_y - 1] && (board[pos_x - 1][pos_y - 1] = 1))
			mvwaddch(win, y, x, (move++ % 2) ? 'X' : 'O');
		printw("Key = %d; pos_x = %d; pos_y = %d    \r", buff, pos_x, pos_y);
		get_boardxy(pos_x, pos_y, &x, &y);
		//mvwaddch(win, y, x, ACS_BULLET);
		wmove(win, y, x);
		update_panels();
		doupdate();
	}
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
   //wmove(win, 3, 1);
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
		win[WIN_STATS] = newwin(y, STAT_X, (LINES - y) / 2, ((COLS + x) / 2) + 2);
		win[WIN_INFO] = newwin(y, INFO_X, (LINES - y) / 2, ((COLS - x) / 2) - INFO_X - 2);
		win[WIN_BOARD] = newwin(y, x, (LINES - y) / 2, (COLS - x) / 2);
		draw_win(STAT_X, 2, win[WIN_STATS], "Stats");
		draw_win(INFO_X, 3, win[WIN_INFO], "Info");
		draw_win(x, 1, win[WIN_BOARD], "Board");
		panel[WIN_INFO] = new_panel(win[WIN_INFO]);
		panel[WIN_STATS] = new_panel(win[WIN_STATS]);
		panel[WIN_BOARD] = new_panel(win[WIN_BOARD]);
	}
	else if (x + 3 + STAT_X < COLS)
	{
		win[WIN_STATS] = newwin(y, STAT_X, (LINES - y) / 2, ((COLS + x - STAT_X) / 2) + 1);
		win[WIN_INFO] = NULL;
			win[WIN_BOARD] = newwin(y, x, (LINES - y) / 2, (COLS - (x + STAT_X)) / 2 - 1);
		draw_win(STAT_X, 2, win[WIN_STATS], "Stats");
		draw_win(x, 1, win[WIN_BOARD], "Board");
		panel[WIN_INFO] = NULL;
		panel[WIN_STATS] = new_panel(win[WIN_STATS]);
		panel[WIN_BOARD] = new_panel(win[WIN_BOARD]);
	}
	else if (x + 2 < COLS)
	{
		win[WIN_STATS] = NULL;
		win[WIN_INFO] = NULL;
		win[WIN_BOARD] = newwin(y, x, (LINES - y) / 2, (COLS - x) / 2);
		draw_win(x, 1, win[WIN_BOARD], "Board");
		panel[WIN_INFO] = NULL;
		panel[WIN_STATS] =NULL;
		panel[WIN_BOARD] = new_panel(win[WIN_BOARD]);
	}
	else
		printw("window is too small (min width = %d).", (x + 3));
	wmove(win[WIN_BOARD], 4, 1);
}

int		main()
{
	WINDOW	*win[3];
	PANEL	*panel[3];
	int		x;
	int		y;

	initscr();
	start_color();
	cbreak();
	noecho();

	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);

	manage_wins(win, panel);
	get_boardcr(COLUMNS, ROWS, &x, &y);
	draw_grid(win[WIN_BOARD], COLUMNS, ROWS);

	wmove(win[WIN_BOARD], 4, 5);
	update_panels();
	doupdate();

	run_prog(win[WIN_BOARD]);

	//getch();
	endwin();
}