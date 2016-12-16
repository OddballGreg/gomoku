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

#define EMPTY 0
#define WHITE 1
#define BLACK 2
#define WIN 1
#define LOSE 2


/*
** Shorthand:
*/
#define AI env.ai
#define GAME env.game
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
	int				depth;
	int				minmax;
	int				branchweight;
	int				gameover;
	char			board[15][15];
	t_coord			piece_played;
	int				parentid;
	int				child[255];
}					t_node;

typedef struct		s_ai
{
	t_node			nodes[2000];
	int				id_count;
}					t_ai;

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
	t_ai			ai;
}					t_env;

/*
** Proposed data structure:
*/

typedef struct		s_p_node
{
	int				depth; //total number of moves made to this point.
	int				minmax; //Weighting of the current move;
	int				max;//optional
	int				min;//optional
	int				child_weight;//Average/minmax weight of the branches children.
	t_coord			move;//the coordinates of the played piece.
	struct s_p_node	*child1;//Child with the best weight.
	struct s_p_node	*child2;//Child with the second best weight.
	struct s_p_node	*child3;//Child with the third best weight.
	struct s_p_node	*child4;//Child with the fourth best weight.
	struct s_p_node	*child5;//Child with the fith best weight.
}					t_p_node;

//Everytime a node gets created, it gets added to this list,
//to simplify the process of deleting nodes.
typedef struct		s_p_list
{
	t_p_node		*node;//pointer to the node.
	int				node_depth;//speeds up cleaning process.
	struct s_p_list	*next;
}					t_p_list;

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
** heuristic.chars
*/
int			hpair(t_node *node, int x, int y);
void		heuristic(t_node *node);

/*
** options.chars
*/
void		getopts();

/*
** ai.c
*/
void		copy_map(char source[15][15], char dest[15][15]);
void		place_piece(t_node *node, t_coord piece_played);
t_node		make_node(int parentid, t_coord piece_played);

/*
**                                /----------\                                **
** ----- ----- ----- ----- ----- |  The End   | ----- ----- ----- ----- ----- **
**                                \----------/                                **
*/
#endif
