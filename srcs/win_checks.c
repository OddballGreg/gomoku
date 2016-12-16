#include "../includes/gomoku.h"

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
