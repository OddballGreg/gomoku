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

void		getopts()
{
	char 	*input;

	input = NULL;
	opt1:
	printf("Select your gamemode:\n(1) Player vs Comp\n(2) Player vs Player\n");
	input = get_line(&input);
	if (atoi(input) == 1)
		env.gamemode = 1;
	else if (atoi(input) == 2)
		env.gamemode = 2;
	else
		goto opt1;
}

int			main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	getopts();
	//init();
}
