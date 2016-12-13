/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:38:57 by khansman          #+#    #+#             */
/*   Updated: 2016/11/28 13:39:43 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAIN_FILE
#include "../includes/gomoku.h"

void		heuristic(t_node *node)
{
	node->minmax = rand();
}

void		copy_map(char source[15][15], char dest[15][15])
{
	int		x;
	int		y;

	x = -1;
	while(++x < 15)
	{
		y = -1;
		while (++y < 15)
			dest[x][y] = source[x][y];
	}
}

void		place_piece(t_node *node, t_coord piece_played)
{
	if (piece_played.x != -1 && piece_played.y != -1)
	{
		if (node->depth % 2 == 1)
			node->board[piece_played.x][piece_played.y] = BLACK;
		else
			node->board[piece_played.x][piece_played.y] = WHITE;
	}
}

t_node		*make_node(t_node *parent, t_coord piece_played, int depth)
{
	t_node	*new;
	t_node	*tmp;
	char	save;

	save = 1;
	new = malloc(sizeof(t_node));
	new->depth = depth;
	new->parent = NULL;
	new->child = NULL;
	new->sibling = NULL;
	if (parent)
		copy_map(parent->board, new->board);
	else
		copy_map(GAME.board, new->board);
	place_piece(new, piece_played);

	heuristic(new);
	if (parent)
	{
		parent->branchweight += new->minmax;
		new->parent = parent;
		if (parent->child)
		{
			tmp = parent->child;
			if (new->minmax > tmp->minmax) //Alpha beta pruning
				save = 0;
			while (tmp->sibling)
			{
				tmp = tmp->sibling;
				if (new->minmax > tmp->minmax) //Alpha beta pruning
					save = 0;
			}
			if (save == 1)
				tmp->sibling = new;
		}
		else
			parent->child = new;
	}
	/* //Debug: Prints the node infor;
	int x;
	int y;
	printf("\nID: %i\tDEPTH: %i\tMM: %i\tBW: %i\n", new->id, new->depth, new->minmax, new->branchweight);
	ft_putendl("Board:");
	x = -1;
	while(++x < 15)
	{
		y = -1;
		while(++y < 15)
			ft_putnbr(new->board[x][y]);
		ft_putendl("");
	}
	//End Debug */
	return (new);
}

void		init()
{
	t_coord initial;

	AI.id_count = 0;
	AI.depth = -1;
	int x = -1;
	int y;
	while(++x < 15)
	{
		y = -1;
		while(++y < 15)
			GAME.board[x][y] = EMPTY;
	}

	// final code will not create ai nodes in init function
	initial.x = 1;
	initial.y = 1;
	
	AI.nodes[AI.id_count] = make_node(NULL, initial, ++AI.depth);
	AI.id_count++;
 // debug
	initial.x = 3;
	initial.y = 2;
	AI.nodes[AI.id_count] = make_node(AI.head, initial, ++AI.depth);
	AI.id_count++;
	initial.x = 5;
	initial.y = 6;
	AI.nodes[AI.id_count] = make_node(AI.head, initial, AI.depth);
	AI.id_count++;
	initial.x = 6;
	initial.y = 6;
	AI.nodes[AI.id_count] = make_node(AI.head->child, initial, ++AI.depth);
	AI.id_count++;
	initial.x = 8;
	initial.y = 6;
	AI.nodes[AI.id_count] = make_node(AI.head->child->child, initial, ++AI.depth);
	AI.id_count++;
}

void		getopts()
{
	char 	*input;

	input = NULL;
	ft_putendl("Select your gamemode:\n(1) Player vs Comp\n(2) Player vs Player");
	while (GAMEMODE == 0)
	{
		if (!get_next_line(0, &input))
			continue ;
		if (atoi(input) == 1)
			GAMEMODE = 1;
		else if (atoi(input) == 2)
			GAMEMODE = 2;
		else
			ft_putendl("Please select a valid option.");
	}
}

int			main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	getopts();
	init();
}
