#include "../includes/gomoku.h"

/*
** debug code:
** printf("key pressed = %d (%c)\n", buff, (isprint(buff)) ? buff : ' ');
*/

void	draw_piece(t_coord move)
{
	t_coord		s_pos;

	get_boardxy(move.x, move.y, &s_pos.x, &s_pos.y);
	if (move.x < 1 || move.x > s_pos.x || move.y < 1 || move.y > s_pos.y)
		return ;
	mvwaddch(E_WIN[WIN_BOARD], s_pos.y, s_pos.x, (++E_DEPTH & 0b1) ?
		P1_PIECE : P2_PIECE);
	E_BOARD[move.x][move.y] = (E_DEPTH & 0b1) + 1;
}

void	init_boarders(void)
{
	AI.lxb = (E_W_BPOS.x < 6) ? 1 : E_W_BPOS.x - 5;
	AI.lyb = (E_W_BPOS.y < 6) ? 1 : E_W_BPOS.y - 5;
	AI.uxb = (E_W_BPOS.x > 14) ? 19 : E_W_BPOS.x + 5;
	AI.uyb = (E_W_BPOS.y > 14) ? 19 : E_W_BPOS.y + 5;
}

void	usermove(void)
{
	if (valid_move(E_W_BPOS) < 1)
		return ;
	draw_piece(E_W_BPOS);
	//Inform AI of users move. Prompt Ai to move returns xy of AI move
	//if (E_DEPTH < 1)
		init_boarders();
	draw_piece(prompt_ai(E_W_BPOS));
}

void	manage_ui(void)
{
	char	buff;

	while ((buff = getch()))
	{
		if (buff == 'd' || buff == 'C')
			E_W_BPOS.x = (E_W_BPOS.x == COLUMNS - 1) ? 1 : E_W_BPOS.x + 1;
		else if (buff == 'a' || buff == 'D')
			E_W_BPOS.x = (E_W_BPOS.x == 1) ? COLUMNS - 1 : E_W_BPOS.x - 1;
		else if (buff == 'w' || buff == 'A')
			E_W_BPOS.y = (E_W_BPOS.y == 1) ? ROWS - 1 : E_W_BPOS.y - 1;
		else if (buff == 's' || buff == 'B')
			E_W_BPOS.y = (E_W_BPOS.y == ROWS - 1) ? 1 : E_W_BPOS.y + 1;
		else if (buff == '\n' || buff == ' ')
			usermove();
		else if (buff == 'e')
			exit_prog();
		get_boardxy(E_W_BPOS.x, E_W_BPOS.y, &E_W_SPOS.x, & E_W_SPOS.y);
		draw_stats();
		wmove(E_WIN[WIN_BOARD], E_W_SPOS.y, E_W_SPOS.x);
		update_panels();
		doupdate();
	}
}
