/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_threes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:49:31 by khansman          #+#    #+#             */
/*   Updated: 2017/01/08 15:41:32 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gomoku.h"

float		free_three2(int x, int y, int xd, int yd)
{
	t_f_three		v;

	INIT_07;
	v.p = e->gomoku.player_turn;
	v.o = 2 - (v.p == 2);
	if (!(x - xd > -1 && x - xd < 19 && y - yd > -1 && y - yd < 19) ||
			e->gomoku.map[0][y - yd][x - xd] != v.p)
		return (0);
	while (x - xd > -1 && x - xd < 19 && y - yd > -1 && y - yd < 19 &&
			(N_MAP[y - yd][x - xd] == v.p || COMP_08))
	{
		v.c += 1.0;
		x -= xd;
		y -= yd;
	}
	x = v.x1;
	y = v.y1;
	while (x + xd > -1 && x + xd < 19 && y + yd > -1 && y + yd < 19 &&
			(N_MAP[y + yd][x + xd] == v.p || COMP_08))
	{
		v.c += 1.0;
		x += xd;
		y += yd;
	}
	return (((v.c + 1 == 3) * !v.b) * 0.5);
}

float		free_three(int x, int y, int xd, int yd)
{
	static char		a[7];
	t_f_three2		v;

	v.b = -1;
	v.c = -1;
	bzero(a, 7);
	v.o = 2 - (e->gomoku.player_turn == 2);
	if (!(x - xd > -1 && x - xd < 19 && y - yd > -1 && y - yd < 19) ||
			e->gomoku.map[0][y - yd][x - xd])
		return (free_three2(x, y, xd, yd));
	a[++v.c] = e->gomoku.map[0][y][x] + 48 - (N_MAP[y][x] == 2);
	while (++v.b < 7 && x + xd > -1 && x + xd < 19 &&
			y + yd > -1 && y + yd < 19)
	{
		x += xd;
		y += yd;
		if (N_MAP[y][x] == v.o)
			return (0);
		a[++v.c] = e->gomoku.map[0][y][x] + 48 - (N_MAP[y][x] == 2);
	}
	if (!strncmp(a, "1110", 4) || !strncmp(a, "10110", 5) ||
			!strncmp(a, "11010", 5))
		return (1.0);
	return (0.0);
}

void		double_free_threes(void)
{
	INIT_10;
	y = -1;
	p = e->gomoku.player_turn;
	while (++y < 19 && (x = -1))
	{
		while (++x < 19)
		{
			c = 0.0;
			if (!e->gomoku.map[0][y][x])
			{
				e->gomoku.map[0][y][x] = p;
				c += free_three(x, y, 0, -1);
				c += free_three(x, y, 0, 1);
				c += free_three(x, y, 1, -1);
				c += free_three(x, y, -1, 1);
				c += free_three(x, y, 1, 1);
				c += free_three(x, y, -1, -1);
				c += free_three(x, y, 1, 0);
				c += free_three(x, y, -1, 0);
				c >= 2 && (e->gomoku.map[3][y][x] = c);
				e->gomoku.map[0][y][x] = 0;
			}
		}
	}
}
