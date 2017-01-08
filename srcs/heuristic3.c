/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heuristic3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:49:55 by khansman          #+#    #+#             */
/*   Updated: 2017/01/08 14:49:56 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gomoku.h"

/*
** Random Line in last else:
** if (g_e->ai.hu[3][25] >= 5) ;
*/

int		hu_algo(int node)
{
	float	oh;

	oh = 0;
	if (((COMP_11 && g_e->ai.hu[3][24] >= g_e->ai.hu[3][25]) ||
				g_e->ai.hu[3][24] >= 5) && node == g_e->ai.hu[3][0])
	{
		if (!(g_e->player[g_e->ai.p].captures + g_e->ai.hu[3][11] < 5 && COMP_10))
			g_e->ai.h1 = g_e->ai.h + 100;
		else
			g_e->ai.h1 = -100;
		return (0);
	}
	else if (((COMP_12 && g_e->ai.hu[3][25] > g_e->ai.hu[3][24]) ||
				g_e->ai.hu[3][25] == 4) && node == g_e->ai.hu[3][0])
	{
		if (!(g_e->player[g_e->ai.p].captures + g_e->ai.hu[3][10] == 5 && COMP_14))
			g_e->ai.h1 = g_e->ai.h + 100;
		else
			g_e->ai.h1 = -100;
		return (0);
	}
	else
		g_e->ai.h1 += 2 * g_e->ai.hu[1][1] - 2 * COMP_16;
	return (0);
}

int		calc_heuristic(int node)
{
	max_hu();
	hu_algo(node);
	COMP_52;
	COMP_54;
	return (0);
}

void	max_hu(void)
{
	int		x;

	x = 0;
	while (++x < 27)
	{
		if ((x < 5 || (x > 15 && x < 26)) && g_e->ai.hu[1][x] > g_e->ai.hu[3][x])
			g_e->ai.hu[3][x] = g_e->ai.hu[1][x];
		if (x == 5 && ((g_e->ai.hu[1][24] > g_e->ai.hu[3][24] && g_e->ai.hu[1][24] > \
						g_e->ai.hu[3][25]) || (g_e->ai.hu[1][25] > g_e->ai.hu[3][24] \
							&& g_e->ai.hu[1][25] > g_e->ai.hu[3][25])) && \
				(COMP_69 || 1) && ((g_e->ai.hu[3][6] = \
						g_e->ai.hu[1][6]) || 1) && ((g_e->ai.hu[3][7] = \
							g_e->ai.hu[1][7]) || 1) && ((g_e->ai.hu[3][8] = \
								g_e->ai.hu[1][8]) || 1) && ((g_e->ai.hu[3][9] = \
									g_e->ai.hu[1][9]) || 1))
		{
			g_e->ai.hu[3][0] = g_e->ai.hu[1][0];
			captures_on_max_align((int)g_e->ai.hu[3][7], (int)g_e->ai.hu[3][8], 10);
			N_MAP[(int)g_e->ai.hu[3][8]][(int)g_e->ai.hu[3][7]] = g_e->ai.p;
			captures_on_max_align((int)g_e->ai.hu[3][7], (int)g_e->ai.hu[3][8], 12);
			N_MAP[(int)g_e->ai.hu[3][8]][(int)g_e->ai.hu[3][7]] = g_e->ai.o;
			captures_on_max_align((int)g_e->ai.hu[3][7], (int)g_e->ai.hu[3][8], 14);
			N_MAP[(int)g_e->ai.hu[3][8]][(int)g_e->ai.hu[3][7]] = 0;
		}
	}
}
