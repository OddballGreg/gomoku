/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:49:48 by khansman          #+#    #+#             */
/*   Updated: 2017/01/08 14:49:50 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gomoku.h"

int		heuristics2(int node)
{
	int		b;
	int		c[3];

	bzero(c, 3);
	c[0] = max_aligns(16, 0, -1);
	c[1] = max_aligns(17, 0, 1);
	COMP_46;
	bzero(c, 3);
	c[0] = max_aligns(18, 1, -1);
	c[1] = max_aligns(21, -1, 1);
	COMP_47;
	bzero(c, 3);
	c[0] = max_aligns(19, -1, -1);
	c[1] = max_aligns(20, 1, 1);
	COMP_48;
	bzero(c, 3);
	c[0] = max_aligns(22, 1, 0);
	c[1] = max_aligns(23, -1, 0);
	COMP_50;
	return (0);
}

int		heuristics1(int node)
{
	int		o;
	int		p;
	int		c;
	int		t;

	heuristics2(node);
	e->gomoku.map[0][e->ai.y][e->ai.x] = e->ai.p;
	c = opportunities_threats(3, 1, e->ai.o, e->ai.p);
	c += opportunities_threats(2, 1, e->ai.o, e->ai.p);
	c += opportunities_threats(1, 1, e->ai.o, e->ai.p);
	t = opportunities_threats(3, 2, e->ai.p, e->ai.o);
	t += opportunities_threats(2, 2, e->ai.p, e->ai.o);
	t += opportunities_threats(1, 2, e->ai.p, e->ai.o);
	e->ai.hu[1][3] = c;
	e->ai.hu[1][4] = t;
	e->ai.hu[2][3] = t;
	e->ai.hu[2][4] = c;
	e->gomoku.map[0][e->ai.y][e->ai.x] = e->ai.o;
	e->gomoku.map[0][e->ai.y][e->ai.x] = 0;
	return (1);
}
