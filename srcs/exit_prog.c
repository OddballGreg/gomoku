/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_prog.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 13:06:04 by khansman          #+#    #+#             */
/*   Updated: 2017/01/07 13:06:05 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gomoku.h"

void    exit_prog(void)
{
    endwin();
    ft_putstr("\nGoodbye!\n");
    free_wins();
    exit(0);
}

void    error_quit(char *message)
{
    ft_putstr("Error: ");
    ft_putendl((message) ? message : "An unlabeled error occured");
    exit_prog();
}
