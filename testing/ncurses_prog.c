#include <panel.h>
#include <ncurses.h>
#include <strings.h>
#include <stdio.h>

/*
** Compile:
** gcc -lpanel -lcurses ncurses_prog.c
*/

# define ROWS    19
# define COLUMNS 19

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
	*y = 2 + rows + (rows - 1);
	*x = 4 + (colums * 3) + (colums - 1);
}

void	get_boardxy(int pos_x, int pos_y, int *x, int *y)
{
	*y = (pos_y - 1) * 2 + 2;
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
		pos_y = 0;
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
	wmove(win, 2, 5);
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
		else if ((buff == '\n' || buff == 32) && !board[x - 1][y - 1] && (board[x - 1][y - 1] = 1))
			mvwaddch(win, y, x, (move++ % 2) ? 'X' : 'O');
		//printw("Key = %d; pos_x = %d; pos_y = %d\r", buff, pos_x, pos_y);
		get_boardxy(pos_x, pos_y, &x, &y);
		//mvwaddch(win, y, x, ACS_BULLET);
		wmove(win, y, x);
		update_panels();
		doupdate();
	}
}

int		main()
{
	WINDOW	*win;
	PANEL	*panel;
	int		x;
	int		y;

	initscr();
	start_color();
	cbreak();
	noecho();

	get_boardcr(COLUMNS, ROWS, &x, &y);
	//win = newwin(y, x, LINES/2 - 4, COLS/2 - 8);
	win = newwin(y, x, (LINES - y) / 2, (COLS - x) / 2);
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	box(win, 0, 0);
	panel = new_panel(win);

	draw_grid(win, COLUMNS, ROWS);
	update_panels();
	doupdate();
	run_prog(win);

	//getch();
	endwin();
}
