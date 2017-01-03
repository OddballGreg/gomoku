#include "../includes/gomoku.h"

void	free_wins(void)
{
	delwin(E_WIN[WIN_BOARD]);
	delwin(E_WIN[WIN_INFO]);
	delwin(E_WIN[WIN_STATS]);
	del_panel(E_PAN[WIN_BOARD]);
	del_panel(E_PAN[WIN_INFO]);
	del_panel(E_PAN[WIN_STATS]);
	set_0_win();
}

void	clear_win(WINDOW *win, int width, int height)
{
	t_coord		pos;

	pos.y = -1;
	while (++pos.y < height)
	{
		pos.x = -1;
		while (++pos.x < width)
			mvwaddch(win, pos.y, pos.x, ' ');
	}
}

void	clear_all_wins(void)
{
	t_coord		size;

	get_boardcr(COLUMNS, ROWS, &size.x, &size.y);
	clear_win(E_WIN[WIN_BOARD], size.x, size.y);
	clear_win(E_WIN[WIN_INFO], INFO_X, size.y);
	clear_win(E_WIN[WIN_STATS], STAT_X, size.y);
}

void	redraw_all_win(void)
{
//	clear_all_wins();
//	free_wins();
//	manage_wins();
//	wmove(E_WIN[WIN_BOARD], E_W_SPOS.y, E_W_SPOS.x);
	update_panels();
	doupdate();
}
