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

#include "../libft/includes/libft.h"

/*
** ----------\
** Defines    |
** ----------/
*/

#define WHITE 1
#define BLACK 2

#define AI1 env.ai1
#define AI2 env.ai2
#define GAMEMODE env.gamemode

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

typedef struct		s_node
{
	int				id;
	int				depth;
	int				minmax;
	int				branchweight;
	char			board[15][15];
	t_coord			piece_played;
	struct s_node	*parent;
	struct s_node	*sibling;
	struct s_node	*child;
}					t_node;

typedef struct		s_ai
{
	t_node			*head;
	int				id_count; //debug metric
	int				depth;
}

typedef struct		s_game
{
	t_coord			last_played;
	int				depth;
	char			board[15][15];
	char			p1_captures;
	char			p2_captures;
}					t_game;

typedef struct		s_env
{
	char			gamemode;
	char			verbose;
	t_game			game;
	t_ai			ai1;
	//t_ai			ai2;
}					t_env;

/*
** ----------\
** Globals    |
** ----------/
*/

# ifdef MAIN_FILE

	t_env			env;
# else

	extern t_env	env;
# endif

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
