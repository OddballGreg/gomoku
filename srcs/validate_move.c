#include "../includes/gomoku.h"

int		valid_move(t_coord move)
{
	if (move.x >= NTILES || move.y >= NTILES)
		return (-1);
	if (E_BOARD[move.x][move.y] != EMPTY)
		return (0);
	//Need to account for double threes, and game ended.
	//Also needs to check if it is the user's turn.
	//Check for captures.
	return (1);
}

int		on_board(t_coord move)
{
	if (move.x < 0 || move.x > 19)
		return (-1);
	if (move.y < 0 || move.y > 19)
		return (0);
	return (1);
}
