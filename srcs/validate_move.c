/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_move.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 13:11:03 by khansman          #+#    #+#             */
/*   Updated: 2017/01/07 13:11:05 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gomoku.h"

int		valid_move(t_coord move)
{
	if (move.x >= NTILES + 1 || move.y >= NTILES + 1)
		return (-1);
	if (E_BOARD[move.x][move.y] != EMPTY)
		return (0);
	return (1);
}

int		on_board(t_coord move)
{
	if (move.x < 0 || move.x > 19)
		return (-1);
	if (move.y < 0 || move.y > 19)
		return (0);
	return (1);
}
