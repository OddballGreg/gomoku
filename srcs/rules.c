/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:50:14 by khansman          #+#    #+#             */
/*   Updated: 2017/01/08 14:50:18 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gomoku.h"

void	get_rule_maps(void)
{
	reset_rule_maps();
	double_free_threes();
	possible_captures(1, 2 - (g_e->gomoku.player_turn == 2),
			g_e->gomoku.player_turn);
	possible_captures(2, g_e->gomoku.player_turn,
			2 - (g_e->gomoku.player_turn == 2));
}

void	reset_rule_maps(void)
{
	char	x;
	char	y;
	char	z;

	y = -1;
	while (++y < 19 && (x = -1))
		while (++x < 19 && !(z = 0))
			while (++z < 7)
				g_e->gomoku.map[z][y][x] = 0;
}

void	apply_rules(void)
{
	apply_capture();
}

int		player_wins_check(void)
{
	t_pwin	v;

	v.y = -1;
	v.p = g_e->gomoku.player_turn;
	while (++v.y < 19 && (v.x = -1))
	{
		while (++v.x < 19)
		{
			if (COMP_17 == v.p && COMP_18 && COMP_19 && COMP_20 && COMP_21)
				return (1);
			if (v.y + 4 < 19 && COMP_22 && COMP_23 && COMP_24 && COMP_25 &&
					COMP_26)
				return (1);
			if (v.y + 4 < 19 && COMP_17 == v.p && COMP_27 && COMP_28 &&
					COMP_29 && COMP_30)
				return (1);
			if (v.y + 4 < 19 && v.x - 4 >= 0 && COMP_22 && COMP_31 && COMP_32
					&& COMP_33 && COMP_34)
				return (1);
		}
	}
	return (0);
}
