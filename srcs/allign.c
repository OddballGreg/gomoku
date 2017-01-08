#include "../includes/gomoku.h"

int     captures_on_max_align(int x1, int y1, int pos)
{
    int     p;
    int     x;
    int     y;
    int     xd;
    int     yd;
    int     c;
    int     t;
    int     tx;
    int     ty;
    int     fr;
    
    c = 0;
    t = 0;
    fr = 0;
    tx = e->ai.x;
    ty = e->ai.y;
    (e->ai.hu[3][24] >= e->ai.hu[3][25] && (p = e->ai.player_no)) || (p = 2 - (e->ai.player_no == 2));
    x = x1;
    y = y1;
    xd = e->ai.hu[3][5] * (1 + -2 * (e->ai.hu[3][9] == 2));
    yd = e->ai.hu[3][6] * (1 + -2 * (e->ai.hu[3][9] == 2));
    if (!(x + xd < 19 && x + xd > -1 && y + yd < 19 && y + yd > -1 && e->gomoku.map[0][y + yd][x + xd] && (p = e->gomoku.map[0][y + yd][x + xd])))
        return (-1);
    while (x + xd < 19 && x + xd > -1 && y + yd < 19 && y + yd > -1 && e->gomoku.map[0][y + yd][x + xd] == p)
    {
        x += xd;
        y += yd;
    }
    fr += (x + xd < 19 && x + xd > -1 && y + yd < 19 && y + yd > -1 && !e->gomoku.map[0][y + yd][x + xd]);
    while (x - xd < 19 && x - xd > -1 && y - yd < 19 && y - yd > -1 && e->gomoku.map[0][y - yd][x - xd] == p)
    {
        x -= xd;
        y -= yd;
        e->ai.x = x;
        e->ai.y = y;
        c = opportunities_threats(3, 1, 2 - (p == 2), p);
        c += opportunities_threats(2, 1, 2 - (p == 2), p);
        c += opportunities_threats(1, 1, 2 - (p == 2), p);
        t = opportunities_threats(3, 2, p, 2 - (p == 2));
        t += opportunities_threats(2, 2, p, 2 - (p == 2));
        t += opportunities_threats(1, 2, p, 2 - (p == 2));
    }
    fr += (x - xd < 19 && x - xd > -1 && y - yd < 19 && y - yd > -1 && !e->gomoku.map[0][y - yd][x - xd]);
    e->ai.hu[3][pos] = c;
    e->ai.hu[3][pos + 1] = t;
    fr == 2 && (e->ai.hu[3][26] = 1);
    return (0 + (e->ai.x = tx) * 0 + (e->ai.y = ty) * 0);
}

int     max_aligns(int hu, int xd, int yd)
{
    int             c;
    int             n;
    int             b;
	int				node;
	int				x;
	int				y;
    
    b = -1;
    c = -1;
	node = 0;
	x = e->ai.x;
	y = e->ai.y;
    while (++b < 7 && x + xd > -1 && x + xd < 19 && y + yd > -1 && y + yd < 19 && e->gomoku.map[0][y + yd][x + xd])
	{
		x += xd;
		y += yd;
		!node && (node = e->gomoku.map[0][y][x]);
		if (node != e->gomoku.map[0][y][x] && (b = 8))
			continue;
		++c;
	}
	e->ai.hu[1][hu] = ++c * (1 + (-2 * (node != e->ai.player_no)));
	return (c * (1 + (-2 * (node != e->ai.player_no))));
}

int		get_max_aligned(int x, int y, int z)
{
	int		b;

	b = 0;
	x > e->ai.hu[1][24]  && (b = 1) && (e->ai.hu[1][24] = x);
	-x > e->ai.hu[1][25] && (b = 1) && (e->ai.hu[1][25] = -x);
	y > e->ai.hu[1][24]  && (b = 2) && (e->ai.hu[1][24] = y);
	-y > e->ai.hu[1][25] && (b = 2) && (e->ai.hu[1][25] = -y);
	x <= 0 && y <= 0  && (z = x + y);
	x >= 0 && y >= 0  && (z = x + y);
	z > e->ai.hu[1][24]  && (b = 3) && (e->ai.hu[1][24] = z);
	-z > e->ai.hu[1][25] && (b = 3) && (e->ai.hu[1][25] = -z);
	return (b);
}
