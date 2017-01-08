/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 13:10:41 by khansman          #+#    #+#             */
/*   Updated: 2017/01/07 13:10:42 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gomoku.h"

void	sig_handler(int signo)
{
	if (SIG_R(SIGWINCH))
		redraw_all_win();
	else if (SIG_R(SIGTERM) || SIG_R(SIGQUIT) || SIG_R(SIGQUIT) ||
			SIG_R(SIGINT))
		exit_prog();
	else if (SIG_R(SIGSEGV) || SIG_R(SIGFPE) || SIG_R(SIGBUS))
	{
		mvprintw(1, 1, "Opps");
		update_panels();
		doupdate();
		manage_ui();
	}
}
