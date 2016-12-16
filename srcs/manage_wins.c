#include "../includes/gomoku.h"

void	set_3_win(int x, int y)
{
	E_WIN[WIN_STATS] = newwin(y, STAT_X, (LINES - y) / 2, ((COLS + x) / 2) + 2);
	E_WIN[WIN_INFO] = newwin(y, INFO_X, (LINES - y) / 2, ((COLS - x) / 2) - INFO_X - 2);
	E_WIN[WIN_BOARD] = newwin(y, x, (LINES - y) / 2, (COLS - x) / 2);
	draw_win(STAT_X, 2, E_WIN[WIN_STATS], "Stats");
	draw_win(INFO_X, 3, E_WIN[WIN_INFO], "Info");
	draw_win(x, 1, E_WIN[WIN_BOARD], "Board");
	E_PAN[WIN_INFO] = new_panel(E_WIN[WIN_INFO]);
	E_PAN[WIN_STATS] = new_panel(E_WIN[WIN_STATS]);
	E_PAN[WIN_BOARD] = new_panel(E_WIN[WIN_BOARD]);
}

void	set_2_win(int x, int y)
{
	E_WIN[WIN_STATS] = newwin(y, STAT_X, (LINES - y) / 2, ((COLS + x - STAT_X) / 2) + 1);
	E_WIN[WIN_INFO] = NULL;
	E_WIN[WIN_BOARD] = newwin(y, x, (LINES - y) / 2, (COLS - (x + STAT_X)) / 2 - 1);
	draw_win(STAT_X, 2, E_WIN[WIN_STATS], "Stats");
	draw_win(x, 1, E_WIN[WIN_BOARD], "Board");
	E_PAN[WIN_INFO] = NULL;
	E_PAN[WIN_STATS] = new_panel(E_WIN[WIN_STATS]);
	E_PAN[WIN_BOARD] = new_panel(E_WIN[WIN_BOARD]);
}

void	set_1_win(int x, int y)
{
	E_WIN[WIN_STATS] = NULL;
	E_WIN[WIN_INFO] = NULL;
	E_WIN[WIN_BOARD] = newwin(y, x, (LINES - y) / 2, (COLS - x) / 2);
	draw_win(x, 1, E_WIN[WIN_BOARD], "Board");
	E_PAN[WIN_INFO] = NULL;
	E_PAN[WIN_STATS] =NULL;
	E_PAN[WIN_BOARD] = new_panel(E_WIN[WIN_BOARD]);
}

void	set_0_win(void)
{
	E_WIN[WIN_STATS] = NULL;
	E_WIN[WIN_INFO] = NULL;
	E_WIN[WIN_BOARD] = NULL;
	E_PAN[WIN_STATS] = NULL;
	E_PAN[WIN_INFO] = NULL;
	E_PAN[WIN_BOARD] = NULL;
}

void	manage_wins(void)
{
	int		x;
	int		y;

	get_boardcr(COLUMNS, ROWS, &x, &y);
	if (y + 3 > LINES)
	{
		set_0_win();
		printw("window is too small (min height = %d).", (y + 4));
	}
	else if (x + 5 + STAT_X + INFO_X < COLS)
		set_3_win(x, y);
	else if (x + 3 + STAT_X < COLS)
		set_2_win(x, y);
	else if (x + 2 < COLS)
		set_1_win(x, y);
	else
	{
		set_0_win();
		printw("window is too small (min width = %d).", (x + 3));
	}
	wmove(E_WIN[WIN_BOARD], 4, 1);
}
