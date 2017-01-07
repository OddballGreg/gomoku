/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghavenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:38:57 by ghavenga          #+#    #+#             */
/*   Updated: 2017/01/07 13:09:16 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define MAIN_FILE
#include "../includes/gomoku.h"

void		dump_mem()
{
/*	int		i;

	i = -1;
	ft_putstr("\n");
	while (AI.nodes[i].depth > 0)
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
	}*/
}

void		run_ncurses()
{
	init_curses();
	manage_wins();
	manage_ui();
}

int			main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ft_bzero(&env, sizeof(t_env));
	getopts();
	init_ai();
	init_signals();
//	dump_mem();
	run_ncurses();
}
