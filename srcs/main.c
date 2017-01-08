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

void		run_ncurses(void)
{
	init_curses();
	manage_wins();
	manage_ui();
}

int			main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	ft_bzero(&g_env, sizeof(t_g_env));
	getopts();
	init_ai();
	init_signals();
	run_ncurses();
}
