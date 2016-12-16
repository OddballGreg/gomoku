#include "../includes/gomoku.h"

int			hpair(t_node *node, int x, int y)
{
	int		value;

	value = 0;
	if (node->board[x][y] == EMPTY)
		return (value);
	else
	{
		if (node->board[x][y] == BLACK && node->board[x][y] == node->board[x + 1][y + 1])
			value += 1;
		if (node->board[x][y] == BLACK && node->board[x][y] == node->board[x][y + 1])
			value += 1;
		if (node->board[x][y] == BLACK && node->board[x][y] == node->board[x - 1][y + 1])
			value += 1;
		if (node->board[x][y] == BLACK && node->board[x][y] == node->board[x + 1][y - 1])
			value += 1;
		if (node->board[x][y] == BLACK && node->board[x][y] == node->board[x][y - 1])
			value += 1;
		if (node->board[x][y] == BLACK && node->board[x][y] == node->board[x - 1][y - 1])
			value += 1;
		if (node->board[x][y] == BLACK && node->board[x][y] == node->board[x - 1][y])
			value += 1;
		if (node->board[x][y] == BLACK && node->board[x][y] == node->board[x + 1][y])
			value += 1;
		if (node->board[x][y] == WHITE && node->board[x][y] == node->board[x + 1][y + 1])
			value -= 1;
		if (node->board[x][y] == WHITE && node->board[x][y] == node->board[x][y + 1])
			value -= 1;
		if (node->board[x][y] == WHITE && node->board[x][y] == node->board[x - 1][y + 1])
			value -= 1;
		if (node->board[x][y] == WHITE && node->board[x][y] == node->board[x + 1][y - 1])
			value -= 1;
		if (node->board[x][y] == WHITE && node->board[x][y] == node->board[x][y - 1])
			value -= 1;
		if (node->board[x][y] == WHITE && node->board[x][y] == node->board[x - 1][y - 1])
			value -= 1;
		if (node->board[x][y] == WHITE && node->board[x][y] == node->board[x - 1][y])
			value -= 1;
		if (node->board[x][y] == WHITE && node->board[x][y] == node->board[x + 1][y])
			value -= 1;
		return (value);
	}
}

void		heuristic(t_node *node)
{
	int		value;
	int		x;
	int		y;

	value = 0;
	y = -1;
	while (++y < 15)
	{
		x = -1;
		while (++x < 15)
		{
			value += hpair(node, x, y); // Add additional heuristic functions here
		}
	}
	node->minmax = value;
}