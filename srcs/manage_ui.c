#include "../includes/gomoku.h"

void	usermove(void)
{
	//validate option, then place piece and inform AI.
}

void	manage_ui(void)
{
	char	buff;

	while ((buff = getch()))
	{
		if (buff == 'd' || buff == 'C')
			E_W_BPOS.x = (E_W_BPOS.x == COLUMNS - 1) ? 1 : E_W_BPOS.x + 1;
		else if (buff == 'a' || buff == 'A')
			E_W_BPOS.x == (E_W_BPOS.x == 1) ? COLUMNS - 1 : E_W_BPOS.x -1;
		else if (buff == 'w' || buff == 'A')
			E_W_BPOS.y == (E_W_BPOS.y == 1) ? ROWS - 1 : E_W_BPOS.y - 1;
		else if (buff == 's' || buff == 'B')
			E_W_BPOS.y == (E_W_BPOS.y == ROWS - 1) ? 1 : E_W_BPOS.y + 1;
		else if (buff == '\n' || buff == 32)
			usermove();
		get_boardxy(E_W_BPOS.x, E_W_BPOS.y, &E_W_SPOS.x, & E_W_SPOS.y);
		wmove(E_WIN[WIN_BOARD], E_W_SPOS.y, E_W_SPOS.x);
		update_panels();
		doupdate();
	}
}
