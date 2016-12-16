#include "../includes/gomoku.h"

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
