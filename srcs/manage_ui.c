/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_ui.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 13:09:25 by khansman          #+#    #+#             */
/*   Updated: 2017/01/07 13:09:26 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gomoku.h"

/*
** debug code:
** printf("key pressed = %d (%c)\n", buff, (isprint(buff)) ? buff : ' ');
*/

void	update_map(void)
{
	t_coord		pos;
	t_coord		tmp;

//	get_boardcr(COLUMNS, ROWS, &max.x, &max.y);
	pos.x = 0;
	while (++pos.x < ROWS)
	{
		pos.y = 0;
		while (++pos.y < COLUMNS)
		{
			get_boardcr(pos.x, pos.y, &tmp.x, &tmp.y);
			if (E_BOARD[pos.x][pos.y] == 1)
				mvwaddch(E_WIN[WIN_BOARD], tmp.y - 1, tmp.x - 2, P1_PIECE);
			else if (E_BOARD[pos.x][pos.y] == 2)
				mvwaddch(E_WIN[WIN_BOARD], tmp.y - 1, tmp.x - 2, P2_PIECE);
			else
				mvwaddch(E_WIN[WIN_BOARD], tmp.y - 1, tmp.x - 2, ACS_PLUS);
		}
	}
}

void	draw_piece(t_coord move)
{
	t_coord		s_pos;

	get_boardxy(move.x, move.y, &s_pos.x, &s_pos.y);
	mvwprintw(E_WIN[WIN_STATS], 6, 1, "LAST (%2d; %2d)", move.x, move.y);
	if (e->gomoku.map[3][move.y - 1][move.x - 1] != 0)
	{
		
		return ;
	}
	mvwaddch(E_WIN[WIN_BOARD], s_pos.y, s_pos.x, (++E_DEPTH & 0b1) ?
		P1_PIECE : P2_PIECE);
	E_BOARD[move.x][move.y] = (E_DEPTH & 0b1) + 1;
	e->gomoku.cursorx = move.x - 1;
	e->gomoku.cursory = move.y - 1;

	e->gomoku.map[0][move.y - 1][move.x - 1] = (E_DEPTH & 0b1) + 1;
	e->gomoku.player_turn = (E_DEPTH & 0b1) + 1;//right player
	apply_rules();
	e->gomoku.player_turn = ((E_DEPTH + 1) & 0b1) + 1;//oposite player of who's placing the piece.
	get_rule_maps();//FIX
	if (e->player[1].captures >= 5 || e->player[2].captures >= 5)
			exit_player_win(2 - (e->gomoku.player_turn == 2));//exit(printf("player %d wins by captures\n", 2 - (e->gomoku.player_turn == 2)));
    if (player_wins_check())//if 5 or more aligned
        	exit_player_win(e->gomoku.player_turn);//exit(printf("player %d wins\n", e->gomoku.player_turn));
	reset_map();//resets YOUR map to my map
	//		checks if one of the players win
//		initializes everything necessary for next player	-

	update_map();
//		apply_capture_rules();								-CHECK

	mvwprintw(E_WIN[WIN_STATS], 5, 1, "MOVE STAT: OK");
}

void	init_boarders(void)
{
	/*
	AI.lxb = (E_W_BPOS.x < 6) ? 1 : E_W_BPOS.x - 5;
	AI.lyb = (E_W_BPOS.y < 6) ? 1 : E_W_BPOS.y - 5;
	AI.uxb = (E_W_BPOS.x > 14) ? 19 : E_W_BPOS.x + 5;
	AI.uyb = (E_W_BPOS.y > 14) ? 19 : E_W_BPOS.y + 5;
*/
}

void	usermove(void)
{//algorithm section where ai should be called.
	t_coord		tmp;

	if (valid_move(E_W_BPOS) < 1)
		return ;
	draw_piece(E_W_BPOS);
	init_boarders();
	heuristics(-1);
	ai();
	e->gomoku.map[0][18 - e->gomoku.cursory][e->gomoku.cursorx] = e->gomoku.player_turn;//which the ai will thus use the cursor and place piece.
    tmp.x = e->gomoku.cursorx + 1;
	tmp.y = 18 - e->gomoku.cursory + 1;
	if (GAMEMODE == 1)
		draw_piece(tmp);
	else
		mvwprintw(E_WIN[WIN_STATS], 6, 1, "BEST: (%2d; %2d)", tmp.x, tmp.y);
}

void	manage_ui(void)
{//infinite loop
	char	buff;

//E_DEPTH

//	if current_player != player_turn
//	{
//		checks if one of the players win
//		initializes everything necessary for next player	
//	}
//if (player_turn == ai.player_no)
//{
//		ai plays
//		apply_capture rules
//		changes player_turn]
//		return ;
//}
//printf("one of the user players turns");

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
		else if (buff == '\n' || buff == ' ')//exec
			usermove();//
		else if (buff == 'e')
			exit_prog();
		get_boardxy(E_W_BPOS.x, E_W_BPOS.y, &E_W_SPOS.x, & E_W_SPOS.y);
		draw_stats();
		wmove(E_WIN[WIN_BOARD], E_W_SPOS.y, E_W_SPOS.x);
		update_panels();
		doupdate();
	}
}
