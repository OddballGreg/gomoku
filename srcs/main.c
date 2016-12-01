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

int		heuristic(t_node *node)
{

}

void		make_node(s_node *parent, t_coord piece_played, char colour, int depth)
{
	t_node	*new;
	t_node	*tmp;
	char	save;

	save = 1;
	new = malloc(t_node);
	new->depth = depth;
	new->id = AI1.id_count++;

	new->minmax = heuristic(new);
	if (parent->child)
	{
		tmp = parent->child;
		if (new->minmax > tmp->minmax) //Alpha beta pruning
			save = 0;
		while (tmp->sibling)
		{
			tmp = tmp->sibling;
			if (new->max - new->min > tmp->max - tmp->min) //Alpha beta pruning
				save = 0;
		}
		if (save == 1)
			tmp->sibling = new;
	}
	else
		parent->child = new;
}

void		init()
{
	AI1.id_count = 0;
}

void		getopts()
{
	char 	*input;

	input = NULL;
	printf("Select your gamemode:\n(1) Player vs Comp\n(2) Player vs Player\n");
	while (GAMEMODE == 0)
	{
		if (!get_next_line(0, &input))
			continue ;
		if (atoi(input) == 1)
			GAMEMODE = 1;
		else if (atoi(input) == 2)
			GAMEMODE = 2;
		else
			printf("Please select a valid option.\n");
	}
}

int			main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	getopts();
	init();
}
