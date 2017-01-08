#include "../includes/gomoku.h"

float     free_three2(int x, int y,int xd, int yd)
{
    int     x1;
    int     y1;
    int     b;
    float   c;
    int     p;
    int     o;
    
    b = 0;
    c = 0.0;
    x1 = x;
    y1 = y;
    p = e->gomoku.player_turn;
    o = 2 - (p == 2);
    if (!(x - xd > -1 && x - xd < 19 && y - yd > -1 && y - yd < 19) || e->gomoku.map[0][y - yd][x - xd] != p)
        return (0);
    while (x - xd > -1 && x - xd < 19 && y - yd > -1 && y - yd < 19 && (e->gomoku.map[0][y - yd][x - xd] == p || (e->gomoku.map[0][y - yd][x - xd] == o && ++b && 0)))
    {
        c += 1.0;
        x -= xd;
        y -= yd;
    }
    x = x1;
    y = y1;
    while (x + xd > -1 && x + xd < 19 && y + yd > -1 && y + yd < 19 && (e->gomoku.map[0][y + yd][x + xd] == p || (e->gomoku.map[0][y - yd][x - xd] == o && ++b && 0)))
    {
        c += 1.0;
        x += xd;
        y += yd;
    }
    return (((c + 1 == 3) * !b) * 0.5);
}

float     free_three(int x, int y, int xd, int yd)
{
    static char     a[7];
    int             c;
    int             n;
    int             b;
    int             o;
    
    b = -1;
    c = -1;
    bzero(a, 7);
    o = 2 - (e->gomoku.player_turn == 2);
    if (!(x - xd > -1 && x - xd < 19 && y - yd > -1 && y - yd < 19) || e->gomoku.map[0][y - yd][x - xd])
        return (free_three2(x, y, xd, yd));
    a[++c] = e->gomoku.map[0][y][x] + 48 - (e->gomoku.map[0][y][x] == 2);
    while (++b < 7 && x + xd > -1 && x + xd < 19 && y + yd > -1 && y + yd < 19)
    {
        x += xd;
        y += yd;
        if (e->gomoku.map[0][y][x] == o)
        	return (0);
        a[++c] = e->gomoku.map[0][y][x] + 48 - (e->gomoku.map[0][y][x] == 2);
    }
    if (!strncmp(a, "1110", 4) || !strncmp(a, "10110", 5) || !strncmp(a, "11010", 5))
        return (1.0);
    return (0.0);
}

void    double_free_threes(void)
{
    int     x;
    int     y;
    int     p;
    float   c;

    y = -1;
    p = e->gomoku.player_turn;
    while (++y < 19 && (x = -1))
    {
        while (++x < 19)
        {
            c = 0.0;
            if (!e->gomoku.map[0][y][x])
            {
                e->gomoku.map[0][y][x] = p;
                
                c += free_three(x, y, 0, -1);
                c += free_three(x, y, 0, 1);
                c += free_three(x, y, 1, -1);
                c += free_three(x, y, -1, 1);
                c += free_three(x, y, 1, 1);
                c += free_three(x, y, -1, -1);
                c += free_three(x, y, 1, 0);
                c += free_three(x, y, -1, 0);
                c >= 2 && (e->gomoku.map[3][y][x] = c);
                e->gomoku.map[0][y][x] = 0;
            }
        }
    }
}
