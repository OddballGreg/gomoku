#include "../includes/gomoku.h"

void	init_ai(void)
{	
	t_coord initial;

	int x = -1;
	int y;
	while(++x < NTILES)
	{
		y = -1;
		while(++y < NTILES)
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

void    init_wins(void)
{
 //   manage_wins();
//	get_boardcr();
//	draw_grid(env.win.win[WIN_BOARD], COLUMNS, ROWS);
	wmove(env.win.win[WIN_BOARD], 4, 5);
	update_panels();
	doupdate();
}

void    init_curses(void)
{
    initscr();
	start_color();
	cbreak();
	noecho();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLUE, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	E_W_BPOS.x = 1;
	E_W_BPOS.y = 1;
	get_boardcr(COLUMNS, ROWS, &(env.win.board_size.x), &(env.win.board_size.y));
}

void	init_signals(void)
{
	int		k;

	k = 0;
	while (++k < 32)
		signal(k, sig_handler);
}
