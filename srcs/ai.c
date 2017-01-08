#include "../includes/gomoku.h"

long	timing(void)
{
	struct timeval		time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ai(void)
{
    long    t;

    t = timing();
	possible_solutions();
	e->gomoku.cursorx = e->ai.node % 19 + 19 * !(e->ai.node % 19) - 1;
	e->gomoku.cursory = 18 - (e->ai.node / 19 - (e->gomoku.cursorx == 18)); 
    mvwprintw(E_WIN[WIN_STATS], 17, 1, "TIME: %dms", timing() - t);
}

int		opportunities_threats(int d, int n, int o, int p)
{
	int		c;

	c = 0;
	e->ai.y + d < 19 && !e->gomoku.map[0][e->ai.y + d][e->ai.x] && !e->gomoku.map[n][e->ai.y + d][e->ai.x] && (c += is_capture(e->ai.x, e->ai.y + d, o, p));
	e->ai.y - d > -1 && !e->gomoku.map[0][e->ai.y - d][e->ai.x] && !e->gomoku.map[n][e->ai.y - d][e->ai.x] && (c += is_capture(e->ai.x, e->ai.y - d, o, p));
	e->ai.x + d < 19 && !e->gomoku.map[0][e->ai.y][e->ai.x + d] && !e->gomoku.map[n][e->ai.y][e->ai.x + d] && (c += is_capture(e->ai.x + d, e->ai.y, o, p));
	e->ai.x - d > -1 && !e->gomoku.map[0][e->ai.y][e->ai.x - d] && !e->gomoku.map[n][e->ai.y][e->ai.x - d] && (c += is_capture(e->ai.x - d, e->ai.y, o, p));
	e->ai.x + d < 19 && e->ai.y + d < 19 && !e->gomoku.map[0][e->ai.y + d][e->ai.x + d] && !e->gomoku.map[n][e->ai.y + d][e->ai.x + d] && (c += is_capture(e->ai.x + d, e->ai.y + d, o, p));
	e->ai.x - d > -1 && e->ai.y + d < 19 && !e->gomoku.map[0][e->ai.y + d][e->ai.x - d] && !e->gomoku.map[n][e->ai.y + d][e->ai.x - d] && (c += is_capture(e->ai.x - d, e->ai.y + d, o, p));
e->ai.x + d < 19 && e->ai.y - d > -1 && !e->gomoku.map[0][e->ai.y - d][e->ai.x + d] && !e->gomoku.map[n][e->ai.y - d][e->ai.x + d] && (c += is_capture(e->ai.x + d, e->ai.y - d, o, p));
e->ai.x - d > -1 && e->ai.y - d > -1 && !e->gomoku.map[0][e->ai.y - d][e->ai.x - d] && !e->gomoku.map[n][e->ai.y - d][e->ai.x - d] && (c += is_capture(e->ai.x - d, e->ai.y - d, o, p));
	return (c);
}

void	copy(int n, int o)
{
	int		x;

	x = -1;
	while (++x < 27)
		e->ai.hu[o][x] = e->ai.hu[n][x];
}

void	reset_map(void)
{
	char	x;
	char	y;

	y = -1;
	while (++y < 19 && (x = -1))
		while (++x < 19)
			E_BOARD[x + 1][y + 1] = e->gomoku.map[0][y][x];
}
