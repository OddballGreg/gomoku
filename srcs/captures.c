/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   captures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/08 14:49:12 by khansman          #+#    #+#             */
/*   Updated: 2017/01/08 14:49:14 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gomoku.h"

int		is_capture(int x, int y, int o, int p)
{
	int		c;

	c = 0;
	x + 3 < 19 && M_POS_20 && M_POS_21 && M_POS_22 && (c += 1);
	x - 3 >= 0 && M_POS_23 && M_POS_24 && M_POS_25 && (c += 1);
	y + 3 < 19 && M_POS_26 && M_POS_27 && M_POS_28 && (c += 1);
	y - 3 >= 0 && M_POS_29 && M_POS_30 && M_POS_31 && (c += 1);
	x + 3 < 19 && M_POS_32 && M_POS_33 && M_POS_35 && (c += 1);
	x - 3 >= 0 && y + 3 < 19 && M_POS_34 && M_POS_36 && M_POS_37 && (c += 1);
	x + 3 < 19 && y - 3 >= 0 && M_POS_38 && M_POS_39 && M_POS_40 && (c += 1);
	x - 3 >= 0 && y - 3 >= 0 && M_POS_41 && M_POS_42 && M_POS_43 && (c += 1);
	return (c);
}

void	possible_captures(int n, int o, int p)
{
	int		x;
	int		y;

	y = -1;
	while (++y < 18 && (x = -1))
	{
		while (++x < 18)
		{
			if (!N_MAP[y][x])
			{
				x + 3 < 19 && M_POS_20 && M_POS_21 && M_POS_22 && INC_CAP;
				x - 3 >= 0 && M_POS_23 && M_POS_24 && M_POS_25 && INC_CAP;
				y + 3 < 19 && M_POS_26 && M_POS_27 && M_POS_28 && INC_CAP;
				y - 3 >= 0 && M_POS_29 && M_POS_30 && M_POS_31 && INC_CAP;
				x + 3 < 19 && M_POS_32 && M_POS_33 && M_POS_35 && INC_CAP;
				x - 3 >= 0 && y + 3 < 19 && M_POS_34 && M_POS_36 && M_POS_37 &&
					INC_CAP;
				x + 3 < 19 && y - 3 >= 0 && M_POS_38 && M_POS_39 && M_POS_40 &&
					INC_CAP;
				x - 3 >= 0 && y - 3 >= 0 && M_POS_41 && M_POS_42 && M_POS_43 &&
					INC_CAP;
			}
		}
	}
}

void	apply_capture(void)
{
	INIT_06;
	INIT_05;
	ASSI_02;
	ASSI_03;
	ASSI_04;
	COMP_68 && !(N_MAP[y][x - 1] = 0);
	M_CAP_09 += y + 3 < 19 && M_POS_26 && M_POS_27 && M_POS_28 && COMP_57;
	M_CAP_09 += y - 3 >= 0 && M_POS_29 && M_POS_30 && M_POS_31 && COMP_58;
	COMP_60;
	COMP_62;
	COMP_65;
	M_CAP_09 += (x - 3 >= 0 && y - 3 >= 0 && M_POS_41 && COMP_67);
}
