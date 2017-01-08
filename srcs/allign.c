#include "../includes/gomoku.h"

int     captures_on_max_align(int x1, int y1, int pos)
{
    t_max_align     v;
    
    v.c = 0;
    v.t = 0;
    v.fr = 0;
    v.tx = e->ai.x;
    v.ty = e->ai.y;
    COMP_02;
    v.x = x1;
    v.y = y1;
    v.xd = e->ai.hu[3][5] * (1 + -2 * (e->ai.hu[3][9] == 2));
    v.yd = e->ai.hu[3][6] * (1 + -2 * (e->ai.hu[3][9] == 2));
    if (!(COMP_05 > -1 && M_DPOS01 && (v.p = M_DPOS01)))
        return (-1);
    while (COMP_05 > -1 && M_DPOS01 == v.p)
    {
        v.x += v.xd;
        v.y += v.yd;
    }
    v.fr += (COMP_05 > -1 && !M_DPOS01);
    while (COMP_04 && v.y - v.yd > -1 && COMP_06 == v.p)
    {
        v.x -= v.xd;
        v.y -= v.yd;
        e->ai.x = v.x;
        e->ai.y = v.y;
        v.c = opportunities_threats(3, 1, 2 - (v.p == 2), v.p);
        v.c += opportunities_threats(2, 1, 2 - (v.p == 2), v.p);
        v.c += opportunities_threats(1, 1, 2 - (v.p == 2), v.p);
        v.t = opportunities_threats(3, 2, v.p, 2 - (v.p == 2));
        v.t += opportunities_threats(2, 2, v.p, 2 - (v.p == 2));
        v.t += opportunities_threats(1, 2, v.p, 2 - (v.p == 2));
    }
    v.fr += (COMP_04 && v.y - v.yd > -1 && !COMP_06);
    e->ai.hu[3][pos] = v.c;
    e->ai.hu[3][pos + 1] = v.t;
    v.fr == 2 && (e->ai.hu[3][26] = 1);
    return (0 + (e->ai.x = v.tx) * 0 + (e->ai.y = v.ty) * 0);
}

int     max_aligns(int hu, int xd, int yd)
{
    t_max_align2    v;
    
    v.b = -1;
    v.c = -1;
	v.node = 0;
	v.x = e->ai.x;
	v.y = e->ai.y;
    while (++v.b < 7 && COMP_07 && v.y + yd < 19 && M_DPOS02)
	{
		v.x += xd;
		v.y += yd;
		!v.node && (v.node = e->gomoku.map[0][v.y][v.x]);
		if (v.node != e->gomoku.map[0][v.y][v.x] && (v.b = 8))
			continue;
		++v.c;
	}
	e->ai.hu[1][hu] = ++v.c * (1 + (-2 * (v.node != e->ai.player_no)));
	return (v.c * (1 + (-2 * (v.node != e->ai.player_no))));
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
