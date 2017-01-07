/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 13:05:57 by khansman          #+#    #+#             */
/*   Updated: 2017/01/07 13:05:58 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/gomoku.h"

void    draw_win(int x, int colour, WINDOW *win, const char *title)
{
    int     k;

    box(win, 0, 0);
    mvwaddch(win, 2, 0, ACS_LTEE);
    mvwaddch(win, 2, x - 1, ACS_RTEE);
    k = 0;
    while (++k < x - 1)
        mvwaddch(win, 2, k, ACS_HLINE);
    if (colour > 0)
        attron(COLOR_PAIR(colour));
    mvwaddstr(win, 1, (x - strlen(title)) / 2, title);
    if (colour > 0)
        attroff(COLOR_PAIR(colour));
}
