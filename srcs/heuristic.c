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
				e->ai.hu[y][x] = 0;
		return (-1);
	}
	INIT_08;
	while (++x < 27)
		if (!(e->ai.hu[1][x] = 0))
			e->ai.hu[2][x] = 0;
	e->ai.p = e->gomoku.player_turn;
	e->ai.o = 2 - (e->gomoku.player_turn == 2);
	e->ai.x = node % 19 + 19 * !(node % 19) - 1;
	e->ai.y = node / 19 - (e->ai.x == 18);
	e->ai.hu[1][0] = node;
	e->ai.hu[1][1] = e->gomoku.map[1][e->ai.y][e->ai.x];
	e->ai.hu[1][2] = e->gomoku.map[2][e->ai.y][e->ai.x];
	e->ai.hu[1][7] = e->ai.x;
	e->ai.hu[1][8] = e->ai.y;
	heuristics1(node);
	calc_heuristic(node);
	return (e->ai.n);
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
			if (!e->gomoku.map[0][y][x] && !e->gomoku.map[3][y][x])
				e->ai.node = minimax(z, z, 1);
}

void	copy_map(void)
{
	char		x;
	char		y;

	y = -1;
	while (++y < 19 && (x = -1))
		while (++x < 19)
			e->gomoku.map[0][y][x] = E_BOARD[x + 1][y + 1];
}
