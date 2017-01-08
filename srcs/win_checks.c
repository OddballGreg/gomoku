/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 13:11:10 by khansman          #+#    #+#             */
/*   Updated: 2017/01/08 15:44:44 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gomoku.h"

int		is_vline(int pos_x)
{
	if (pos_x == 1)
		return (0);
	return (((pos_x - 1) % 4) == 0);
}

int		is_plus(int pos_x, int pos_y)
{
	if (pos_y == 1)
		return (0);
	return ((((pos_y - 2) % 2) == 0) && is_vline(pos_x));
}

void	get_boardcr(int colums, int rows, int *x, int *y)
{
	*y = 4 + rows + (rows - 1);
	*x = 4 + (colums * 3) + (colums - 1);
}

void	get_boardxy(int pos_x, int pos_y, int *x, int *y)
{
	*y = (pos_y - 1) * 2 + 4;
	*x = (pos_x - 1) * 4 + 5;
}
