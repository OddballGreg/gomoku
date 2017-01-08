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
	e = (t_e *)&env.e;
	//bzero(&e, sizeof(t_e));//req
//	bzero(&e->eye, sizeof(t_eye));//RM
//	bzero(&e->main, sizeof(t_menu));//RM
//	bzero(&e->pause, sizeof(t_menu));//RM
//	bzero(&e->player[0], sizeof(t_player));//RM
//	bzero(&e->player[1], sizeof(t_player));//RM
//	bzero(&e->player[2], sizeof(t_player));//RM
//	e->eye.ey = 6;
//	e->eye.ez = 0.4;
//	e->gomoku.sub = 0;
//	e->gomoku.scalex = 0.05;
//	e->gomoku.scaley = 0.05;
//	e->gomoku.scalez = 0.05;
	e->gomoku.cursorx = -1;//req M
	e->gomoku.cursory = -1;//req M


}

void    init_wins(void)
{
 //   manage_wins();
//	get_boardcr();
//	draw_grid(env.win.win[WIN_BOARD], COLUMNS, ROWS);
	wmove(env.win.win[WIN_BOARD], 4, 5);
	update_panels();
	doupdate();
}

void    init_curses(void)
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
	get_boardcr(COLUMNS, ROWS, &(env.win.board_size.x), &(env.win.board_size.y));
}

void	init_signals(void)
{
	int		k;

	k = 0;
	while (++k < 32)
		signal(k, sig_handler);
}
