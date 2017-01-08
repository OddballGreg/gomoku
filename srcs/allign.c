/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:49:07 by khansman          #+#    #+#             */
/*   Updated: 2017/01/08 14:49:09 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gomoku.h"

int		captures_on_max_align(int x1, int y1, int pos)
{
	t_max_align		v;

	INIT_04;
	v.xd = e->ai.hu[3][5] * (1 + -2 * (e->ai.hu[3][9] == 2));
	v.yd = e->ai.hu[3][6] * (1 + -2 * (e->ai.hu[3][9] == 2));
	if (!(COMP_05 > -1 && M_DPOS01 && (v.p = M_DPOS01)))
		return (-1);
	while (COMP_05 > -1 && M_DPOS01 == v.p)
		LTRUE_01;
	v.fr += (COMP_05 > -1 && !M_DPOS01);
	while (COMP_04 && v.y - v.yd > -1 && COMP_06 == v.p)
	{
		INIT_03;
		v.c = opportunities_threats(3, 1, 2 - (v.p == 2), v.p);
		v.c += opportunities_threats(2, 1, 2 - (v.p == 2), v.p);
		v.c += opportunities_threats(1, 1, 2 - (v.p == 2), v.p);
		v.t = opportunities_threats(3, 2, v.p, 2 - (v.p == 2));
		v.t += opportunities_threats(2, 2, v.p, 2 - (v.p == 2));
		v.t += opportunities_threats(1, 2, v.p, 2 - (v.p == 2));
	}
	v.fr += (COMP_04 && v.y - v.yd > -1 && !COMP_06);
	e->ai.hu[3][pos] = v.c;
	e->ai.hu[3][pos + 1] = v.t;
	v.fr == 2 && (e->ai.hu[3][26] = 1);
	return (RET_01);
}

int		max_aligns(int hu, int xd, int yd)
{
	t_max_align2		v;

	v.b = -1;
	v.c = -1;
	v.node = 0;
	v.x = e->ai.x;
	v.y = e->ai.y;
	while (++v.b < 7 && COMP_07 && v.y + yd < 19 && M_DPOS02)
	{
		v.x += xd;
		v.y += yd;
		!v.node && (v.node = e->gomoku.map[0][v.y][v.x]);
		if (v.node != e->gomoku.map[0][v.y][v.x] && (v.b = 8))
			continue;
		++v.c;
	}
	e->ai.hu[1][hu] = ++v.c * (1 + (-2 * (v.node != e->ai.player_no)));
	return (v.c * (1 + (-2 * (v.node != e->ai.player_no))));
}

int		get_max_aligned(int x, int y, int z)
{
	int		b;

	b = 0;
	COMP_35;
	COMP_36;
	COMP_37;
	COMP_38;
	x <= 0 && y <= 0 && (z = x + y);
	x >= 0 && y >= 0 && (z = x + y);
	COMP_39;
	COMP_40;
	return (b);
}
