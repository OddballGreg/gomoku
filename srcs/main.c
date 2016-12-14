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
	node->minmax = rand() % 500;
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

t_node		*make_node(int parentid, t_coord piece_played)
{
	t_node	*new;
	char	save;
	int		c;

	save = 1;
	new = malloc(sizeof(t_node));
	new->parentid = parentid;
	c = -1;
	while (++c <= 255)
		new->child[c] = -1;
	if (parentid != -1)
	{
		copy_map(AI.nodes[parentid].board, new->board);
		new->depth = AI.nodes[parentid].depth + 1;
	}
	else
	{
		copy_map(GAME.board, new->board);
		new->depth = 0;
	}
	place_piece(new, piece_played);

	heuristic(new);
	c = -1;
	if (parentid != -1) //Has parent
	{
		while (++c <= 255 && AI.nodes[parentid].child[c] != -1 && save == 1) //Cycle parent children
			if (AI.nodes[AI.nodes[parentid].child[c]].minmax > new->minmax) //Alpha Beta Pruning
				save = 0;
		if (save == 1) //If unpruned, save child to parent
		{
			printf("\nNot Pruned");
			AI.nodes[parentid].child[c] = AI.id_count;
			AI.nodes[parentid].branchweight += new->minmax;
			AI.nodes[AI.id_count] = *new;
			AI.id_count++;
				 
		}
	}
	else
	{
		AI.nodes[AI.id_count] = *new;
		AI.id_count++;
	}

	//Debug: Prints the node infor;
	int x;
	int y;
	printf("\nID: %i\tPID: %i\tDEPTH: %i\tMM: %i\tBW: %i\n", AI.id_count, new->parentid,  new->depth, new->minmax, new->branchweight);
	ft_putendl("Board:");
	x = -1;
	while(++x < 15)
	{
		y = -1;
		while(++y < 15)
			ft_putnbr(new->board[x][y]);
		ft_putendl("");
	}
	//End Debug 

	return (new);
}

void		init()
{
	t_coord initial;

	AI.id_count = 0;
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
	
	make_node(-1, initial);
 // debug
	initial.x = 3;
	initial.y = 2;
	make_node(0, initial);

	initial.x = 5;
	initial.y = 6;
	make_node(0, initial);

	initial.x = 6;
	initial.y = 6;
	make_node(1, initial);

	initial.x = 8;
	initial.y = 6;
	make_node(2, initial);
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

void		dump_mem()
{
	int		i;

	i = -1;
	ft_putstr("\n");
	while (++i < AI.id_count)
	{
		ft_putstr("ID: ");
		ft_putnbr(i);
		ft_putstr(" PID: ");
		ft_putnbr(AI.nodes[i].parentid);
		ft_putstr(" MM: ");
		ft_putnbr(AI.nodes[i].minmax);
		ft_putstr(" BW: ");
		ft_putnbr(AI.nodes[i].branchweight);
		ft_putstr("\n");
	}
}

int			main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	getopts();
	init();
	dump_mem();
}
