/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gomoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:37:53 by khansman          #+#    #+#             */
/*   Updated: 2016/11/28 13:37:54 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOMOKU_H
# define GOMOKU_H

/*
** ----------\
** Includes   |
** ----------/
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <libft.h>

/*
** ----------\
** Defines    |
** ----------/
*/

/*
** ----------\
** Structures |
** ----------/
*/

typedef struct		s_coord
{
	int				x;
	int				y;
}					t_coord;

typedef struct		s_game
{
	t_coord			last_played;
	int				turn;
	char			board[15][15];
	char			p1_captures;
	char			p2_captures;
}					t_game;

typedef struct		s_env
{
	int				gamemode;
	char			verbose;
	t_game			game;
}					t_env;

/*
** ----------\
** Globals    |
** ----------/
*/

t_env				env;

/*
** ----------\
** Prototypes |
** ----------/
*/

/*
**                                /----------\                                **
** ----- ----- ----- ----- ----- |  The End   | ----- ----- ----- ----- ----- **
**                                \----------/                                **
*/
#endif
