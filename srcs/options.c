/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghavenga <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 13:10:17 by ghavenga          #+#    #+#             */
/*   Updated: 2017/01/08 15:43:15 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gomoku.h"

void		getopts(void)
{
	char	*input;

	input = NULL;
	ft_putendl("Select your gamemode:\n(1) Player vs Comp");
	ft_putendl("(2) Player vs Player");
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
