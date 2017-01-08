/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:49:43 by khansman          #+#    #+#             */
/*   Updated: 2017/01/08 14:49:44 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gomoku.h"

int		heuristics(int node)
{
	INIT_09;
	if (node < 0 && ASSI_01)
	{
		while (++y < 5 && (x = -1))
			while (++x < 27)
				g_e->ai.hu[y][x] = 0;
		return (-1);
	}
	INIT_08;
	while (++x < 27)
		if (!(g_e->ai.hu[1][x] = 0))
			g_e->ai.hu[2][x] = 0;
	g_e->ai.p = g_e->gomoku.player_turn;
	g_e->ai.o = 2 - (g_e->gomoku.player_turn == 2);
	g_e->ai.x = node % 19 + 19 * !(node % 19) - 1;
	g_e->ai.y = node / 19 - (g_e->ai.x == 18);
	g_e->ai.hu[1][0] = node;
	g_e->ai.hu[1][1] = g_e->gomoku.map[1][g_e->ai.y][g_e->ai.x];
	g_e->ai.hu[1][2] = g_e->gomoku.map[2][g_e->ai.y][g_e->ai.x];
	g_e->ai.hu[1][7] = g_e->ai.x;
	g_e->ai.hu[1][8] = g_e->ai.y;
	heuristics1(node);
	calc_heuristic(node);
	return (g_e->ai.n);
}

int		minimax(int node, int depth, int maximizing_player)
{
	(void)depth;
	if (!maximizing_player)
		return (heuristics(-1));
	return (heuristics(node));
}

void	possible_solutions(void)
{
	int			x;
	int			y;
	int			z;

	z = 0;
	y = -1;
	while (++y < 19 && (x = -1))
		while (++x < 19 && (++z))
			if (!g_e->gomoku.map[0][y][x] && !g_e->gomoku.map[3][y][x])
				g_e->ai.node = minimax(z, z, 1);
}

void	copy_map(void)
{
	char		x;
	char		y;

	y = -1;
	while (++y < 19 && (x = -1))
		while (++x < 19)
			g_e->gomoku.map[0][y][x] = E_BOARD[x + 1][y + 1];
}
