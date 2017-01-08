#include "../includes/gomoku.h"

int		is_capture(int x, int y, int o, int p)
{
	int		c;

	c = 0;
	x + 3 < 19 && e->gomoku.map[0][y][x + 1] == o && e->gomoku.map[0][y][x + 2] == o && e->gomoku.map[0][y][x + 3] == p && (c += 1);
	x - 3 >= 0 && e->gomoku.map[0][y][x - 1] == o && e->gomoku.map[0][y][x - 2] == o && e->gomoku.map[0][y][x - 3] == p && (c += 1);
    y + 3 < 19 && e->gomoku.map[0][y + 1][x] == o && e->gomoku.map[0][y + 2][x] == o && e->gomoku.map[0][y + 3][x] == p && (c += 1);
	y - 3 >= 0 && e->gomoku.map[0][y - 1][x] == o && e->gomoku.map[0][y - 2][x] == o && e->gomoku.map[0][y - 3][x] == p && (c += 1);

	x + 3 < 19 && y + 3 < 19 && e->gomoku.map[0][y + 1][x + 1] == o && e->gomoku.map[0][y + 2][x + 2] == o && e->gomoku.map[0][y + 3][x + 3] == p && (c += 1);
                
	x - 3 >= 0 && y + 3 < 19 && e->gomoku.map[0][y + 1][x - 1] == o && e->gomoku.map[0][y + 2][x - 2] == o && e->gomoku.map[0][y + 3][x - 3] == p && (c += 1);
                
	x + 3 < 19 && y - 3 >= 0 && e->gomoku.map[0][y - 1][x + 1] == o && e->gomoku.map[0][y - 2][x + 2] == o && e->gomoku.map[0][y - 3][x + 3] == p && (c += 1);
                
	x - 3 >= 0 && y - 3 >= 0 && e->gomoku.map[0][y - 1][x - 1] == o && e->gomoku.map[0][y - 2][x - 2] == o && e->gomoku.map[0][y - 3][x - 3] == p && (c += 1);	
	return (c);
}

void    possible_captures(int n, int o, int p)
{
    int     x;
    int     y;
    
    y = -1;
    while (++y < 18 && (x = -1))
    {
        while (++x < 18)
        {
            if (!e->gomoku.map[0][y][x])
            {
                x + 3 < 19 && e->gomoku.map[0][y][x + 1] == o && e->gomoku.map[0][y][x + 2] == o && e->gomoku.map[0][y][x + 3] == p && (e->gomoku.map[n][y][x] += 1);
                x - 3 >= 0 && e->gomoku.map[0][y][x - 1] == o && e->gomoku.map[0][y][x - 2] == o && e->gomoku.map[0][y][x - 3] == p && (e->gomoku.map[n][y][x] += 1);
                y + 3 < 19 && e->gomoku.map[0][y + 1][x] == o && e->gomoku.map[0][y + 2][x] == o && e->gomoku.map[0][y + 3][x] == p && (e->gomoku.map[n][y][x] += 1);
                y - 3 >= 0 && e->gomoku.map[0][y - 1][x] == o && e->gomoku.map[0][y - 2][x] == o && e->gomoku.map[0][y - 3][x] == p && (e->gomoku.map[n][y][x] += 1);
                x + 3 < 19 && y + 3 < 19 && e->gomoku.map[0][y + 1][x + 1] == o && e->gomoku.map[0][y + 2][x + 2] == o && e->gomoku.map[0][y + 3][x + 3] == p && (e->gomoku.map[n][y][x] += 1);
                x - 3 >= 0 && y + 3 < 19 && e->gomoku.map[0][y + 1][x - 1] == o && e->gomoku.map[0][y + 2][x - 2] == o && e->gomoku.map[0][y + 3][x - 3] == p && (e->gomoku.map[n][y][x] += 1);
                x + 3 < 19 && y - 3 >= 0 && e->gomoku.map[0][y - 1][x + 1] == o && e->gomoku.map[0][y - 2][x + 2] == o && e->gomoku.map[0][y - 3][x + 3] == p && (e->gomoku.map[n][y][x] += 1);
                x - 3 >= 0 && y - 3 >= 0 && e->gomoku.map[0][y - 1][x - 1] == o && e->gomoku.map[0][y - 2][x - 2] == o && e->gomoku.map[0][y - 3][x - 3] == p && (e->gomoku.map[n][y][x] += 1);
            }
        }
    }
}


void    apply_capture(void)
{
    int     o;
    int     p;
    int     x;
    int     y;

    x = e->gomoku.cursorx;
    y = e->gomoku.cursory;
    o = 2 - (e->gomoku.player_turn == 2);
    p = e->gomoku.player_turn;
    e->player[p].captures += x + 3 < 19 && e->gomoku.map[0][y][x + 1] == o && e->gomoku.map[0][y][x + 2] == o && e->gomoku.map[0][y][x + 3] == p && !(e->gomoku.map[0][y][x + 2] = 0) && !(e->gomoku.map[0][y][x + 1] = 0);
    e->player[p].captures += x - 3 >= 0 && e->gomoku.map[0][y][x - 1] == o && e->gomoku.map[0][y][x - 2] == o && e->gomoku.map[0][y][x - 3] == p && !(e->gomoku.map[0][y][x - 2] = 0) && !(e->gomoku.map[0][y][x - 1] = 0);
    e->player[p].captures += y + 3 < 19 && e->gomoku.map[0][y + 1][x] == o && e->gomoku.map[0][y + 2][x] == o && e->gomoku.map[0][y + 3][x] == p && !(e->gomoku.map[0][y + 2][x] = 0) && !(e->gomoku.map[0][y + 1][x] = 0);
    e->player[p].captures += y - 3 >= 0 && e->gomoku.map[0][y - 1][x] == o && e->gomoku.map[0][y - 2][x] == o && e->gomoku.map[0][y - 3][x] == p && !(e->gomoku.map[0][y - 2][x] = 0) && !(e->gomoku.map[0][y - 1][x] = 0);
    e->player[p].captures += x + 3 < 19 && y + 3 < 19 && e->gomoku.map[0][y + 1][x + 1] == o && e->gomoku.map[0][y + 2][x + 2] == o && e->gomoku.map[0][y + 3][x + 3] == p && !(e->gomoku.map[0][y + 2][x + 2] = 0) && !(e->gomoku.map[0][y + 1][x + 1] = 0);
    e->player[p].captures += x - 3 >= 0 && y + 3 < 19 && e->gomoku.map[0][y + 1][x - 1] == o && e->gomoku.map[0][y + 2][x - 2] == o && e->gomoku.map[0][y + 3][x - 3] == p && !(e->gomoku.map[0][y + 2][x - 2] = 0) && !(e->gomoku.map[0][y + 1][x - 1] = 0);
    e->player[p].captures += x + 3 < 19 && y - 3 >= 0 && e->gomoku.map[0][y - 1][x + 1] == o && e->gomoku.map[0][y - 2][x + 2] == o && e->gomoku.map[0][y - 3][x + 3] == p && !(e->gomoku.map[0][y - 2][x + 2] = 0) && !(e->gomoku.map[0][y - 1][x + 1] = 0);
    e->player[p].captures += (x - 3 >= 0 && y - 3 >= 0 && e->gomoku.map[0][y - 1][x - 1] == o && e->gomoku.map[0][y - 2][x - 2] == o && e->gomoku.map[0][y - 3][x - 3] == p && !(e->gomoku.map[0][y - 2][x - 2] = 0) && !(e->gomoku.map[0][y - 1][x - 1] = 0));
}
