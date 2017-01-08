/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghavenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 13:08:23 by ghavenga          #+#    #+#             */
/*   Updated: 2017/01/07 13:08:44 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gomoku.h"

void	init_ai(void)
{
	t_coord		pos;

	pos.x = -1;
	while (++pos.x < COLUMNS)
	{
		pos.y = -1;
		while (++pos.y < ROWS)
			E_BOARD[pos.x][pos.y] = 0;
	}
	g_e = (t_e *)&g_env.e;
	g_e->gomoku.cursorx = -1;
	g_e->gomoku.cursory = -1;
}

void	init_wins(void)
{
	wmove(g_env.win.win[WIN_BOARD], 4, 5);
	update_panels();
	doupdate();
}

void	init_curses(void)
{
	initscr();
	start_color();
	cbreak();
	noecho();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	E_W_BPOS.x = 1;
	E_W_BPOS.y = 1;
	get_boardcr(COLUMNS, ROWS, &(g_env.win.board_size.x),
			&(g_env.win.board_size.y));
}

void	init_signals(void)
{
	int		k;

	k = 0;
	while (++k < 32)
		signal(k, sig_handler);
}
