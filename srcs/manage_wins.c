/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_wins.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 13:09:33 by khansman          #+#    #+#             */
/*   Updated: 2017/01/07 13:10:00 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gomoku.h"

void	set_3_win(int x, int y)
{
	E_WIN[WIN_STATS] = newwin(y, STAT_X, (LINES - y) / 2,
			((COLS + x) / 2) + 2);
	E_WIN[WIN_INFO] = newwin(y, INFO_X, (LINES - y) / 2, ((COLS - x) / 2) -
			INFO_X - 2);
	E_WIN[WIN_BOARD] = newwin(y, x, (LINES - y) / 2, (COLS - x) / 2);
	draw_win(STAT_X, 2, E_WIN[WIN_STATS], "Stats");
	draw_win(INFO_X, 3, E_WIN[WIN_INFO], "Info");
	draw_win(x, 1, E_WIN[WIN_BOARD], "Board");
	E_PAN[WIN_INFO] = new_panel(E_WIN[WIN_INFO]);
	E_PAN[WIN_STATS] = new_panel(E_WIN[WIN_STATS]);
	E_PAN[WIN_BOARD] = new_panel(E_WIN[WIN_BOARD]);
	draw_grid(E_WIN[WIN_BOARD], COLUMNS, ROWS);
}

void	set_2_win(int x, int y)
{
	E_WIN[WIN_STATS] = newwin(y, STAT_X, (LINES - y) / 2,
			((COLS + x - STAT_X) / 2) + 1);
	E_WIN[WIN_INFO] = NULL;
	E_WIN[WIN_BOARD] = newwin(y, x, (LINES - y) / 2,
			(COLS - (x + STAT_X)) / 2 - 1);
	draw_win(STAT_X, 2, E_WIN[WIN_STATS], "Stats");
	draw_win(x, 1, E_WIN[WIN_BOARD], "Board");
	E_PAN[WIN_INFO] = NULL;
	E_PAN[WIN_STATS] = new_panel(E_WIN[WIN_STATS]);
	E_PAN[WIN_BOARD] = new_panel(E_WIN[WIN_BOARD]);
	draw_grid(E_WIN[WIN_BOARD], COLUMNS, ROWS);
}

void	set_1_win(int x, int y)
{
	E_WIN[WIN_STATS] = NULL;
	E_WIN[WIN_INFO] = NULL;
	E_WIN[WIN_BOARD] = newwin(y, x, (LINES - y) / 2, (COLS - x) / 2);
	draw_win(x, 1, E_WIN[WIN_BOARD], "Board");
	E_PAN[WIN_INFO] = NULL;
	E_PAN[WIN_STATS] =NULL;
	E_PAN[WIN_BOARD] = new_panel(E_WIN[WIN_BOARD]);
	draw_grid(E_WIN[WIN_BOARD], COLUMNS, ROWS);
}

void	set_0_win(void)
{
	E_WIN[WIN_STATS] = NULL;
	E_WIN[WIN_INFO] = NULL;
	E_WIN[WIN_BOARD] = NULL;
	E_PAN[WIN_STATS] = NULL;
	E_PAN[WIN_INFO] = NULL;
	E_PAN[WIN_BOARD] = NULL;
}

void	manage_wins(void)
{
	if (BOARD_HEI + 3 > LINES)
	{
		set_0_win();
		printw("window is too small (min height = %d).", (BOARD_HEI + 4));
	}
	else if (BOARD_WID + 5 + STAT_X + INFO_X < COLS)
		set_3_win(BOARD_WID,BOARD_HEI);
	else if (BOARD_WID + 3 + STAT_X < COLS)
		set_2_win(BOARD_WID, BOARD_HEI);
	else if (BOARD_WID + 2 < COLS)
		set_1_win(BOARD_WID, BOARD_HEI);
	else
	{
		set_0_win();
		printw("window is too small (min width = %d).", (BOARD_WID + 3));
	}
	if (E_WIN[WIN_INFO])
		draw_info();
	if (E_WIN[WIN_STATS])
		draw_stats();
	wmove(E_WIN[WIN_BOARD], 4, 5);
	update_panels();
	doupdate();
}
