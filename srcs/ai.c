/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ai.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:51:55 by khansman          #+#    #+#             */
/*   Updated: 2017/01/08 16:10:50 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gomoku.h"

long	timing(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ai(void)
{
	long			t;

	t = timing();
	possible_solutions();
	g_e->gomoku.cursorx = g_e->ai.node % 19 + 19 * !(g_e->ai.node % 19) - 1;
	g_e->gomoku.cursory = 18 - (g_e->ai.node / 19 -
			(g_e->gomoku.cursorx == 18));
	mvwprintw(E_WIN[WIN_STATS], 17, 1, "TIME: %dms", timing() - t);
}

int		opportunities_threats(int d, int n, int o, int p)
{
	int				c;

	c = 0;
	g_e->ai.y + d < 19 && M_POS_01 && M_POS_02 && M_CAP_01;
	M_POS_15 && M_POS_03 && M_POS_04 && M_CAP_02;
	g_e->ai.x + d < 19 && M_POS_05 && M_POS_06 && M_CAP_03;
	g_e->ai.x - d > -1 && M_POS_07 && M_POS_08 && M_CAP_04;
	g_e->ai.x + d < 19 && M_POS_09 && M_POS_10 && M_POS_11 && M_CAP_05;
	g_e->ai.x - d > -1 && M_POS_12 && M_POS_13 && M_POS_14 && M_CAP_06;
	g_e->ai.x + d < 19 && M_POS_15 && M_POS_16 && M_POS_17 && M_CAP_07;
	g_e->ai.x - d > -1 && M_POS_15 && M_POS_18 && M_POS_19 && M_CAP_08;
	return (c);
}

void	copy(int n, int o)
{
	int				x;

	x = -1;
	while (++x < 27)
		g_e->ai.hu[o][x] = g_e->ai.hu[n][x];
}

void	reset_map(void)
{
	char			x;
	char			y;

	y = -1;
	while (++y < 19 && (x = -1))
		while (++x < 19)
			E_BOARD[x + 1][y + 1] = g_e->gomoku.map[0][y][x];
}
