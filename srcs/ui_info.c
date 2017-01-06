#include "../includes/gomoku.h"

void	draw_info(void)
{
	mvwprintw(E_WIN[WIN_INFO], 3, 1, "ACTIVE GAMEPLAY:");
	mvwprintw(E_WIN[WIN_INFO], 4, 1, "captures");
	mvwprintw(E_WIN[WIN_INFO], 5, 1, "No double threes");
	mvwprintw(E_WIN[WIN_INFO], 6, 1, "gameend captures");
	mvwprintw(E_WIN[WIN_INFO], 8, 1, "RULES:");
	mvwprintw(E_WIN[WIN_INFO], 9, 1, "get five in a row");
	mvwprintw(E_WIN[WIN_INFO], 10, 1, "or capture 10");
	mvwprintw(E_WIN[WIN_INFO], 11, 1, "pieces to win.");
	mvwprintw(E_WIN[WIN_INFO], 13, 1, "KEYS:");
	mvwprintw(E_WIN[WIN_INFO], 14, 1, "WASD or arrows");
	mvwprintw(E_WIN[WIN_INFO], 15, 1, "to move cursor.");
	mvwprintw(E_WIN[WIN_INFO], 16, 1, "Enter or space");
	mvwprintw(E_WIN[WIN_INFO], 17, 1, "to select square.");
	mvwprintw(E_WIN[WIN_INFO], 19, 1, "CAPTURES:");
	mvwprintw(E_WIN[WIN_INFO], 20, 1, "Place pieces on");
	mvwprintw(E_WIN[WIN_INFO], 21, 1, "either side of");
	mvwprintw(E_WIN[WIN_INFO], 22, 1, "a pair of your");
	mvwprintw(E_WIN[WIN_INFO], 23, 1, "opponents pieces");
	mvwprintw(E_WIN[WIN_INFO], 24, 1, "to capture them.");
	mvwprintw(E_WIN[WIN_INFO], BOARD_HEI - 2, 1, "Press 'E' to exit.");
}

void	draw_stats(void)
{
	mvwprintw(E_WIN[WIN_STATS], 3, 1, "TURN: %s", (E_DEPTH & 0b1) ? "P2" : "P1");
	mvwprintw(E_WIN[WIN_STATS], 4, 1, "MOVE: %d", (E_DEPTH + 1) >> 1);
}
