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