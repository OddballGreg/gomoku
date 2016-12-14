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
	initial.x = 7;
	initial.y = 7;
	
	make_node(-1, initial);
 // debug
	initial.x = 6;
	initial.y = 7;
	make_node(0, initial);

	initial.x = 5;
	initial.y = 6;
	make_node(0, initial);

	initial.x = 6;
	initial.y = 6;
	make_node(1, initial);

	initial.x = 8;
	initial.y = 7;
	make_node(2, initial);
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
