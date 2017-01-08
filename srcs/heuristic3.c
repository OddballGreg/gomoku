#include "../includes/gomoku.h"

/*
** Random Line in last else:
** if (e->ai.hu[3][25] >= 5) ;
*/

int     hu_algo(int node)
{
	float	oh;

	oh = 0;
	if (((COMP_11 && e->ai.hu[3][24] >= e->ai.hu[3][25]) || COMP_09)
    {
        if (!(e->player[e->ai.p].captures + e->ai.hu[3][11] < 5 && COMP_10))
            e->ai.h1 = e->ai.h + 100;
        else
            e->ai.h1 = -100;
        return (0);
    }
    else if (((COMP_12 && e->ai.hu[3][25] > e->ai.hu[3][24]) || COMP_13)
    {
        if (!(e->player[e->ai.p].captures + e->ai.hu[3][10] == 5 && COMP_14))
            e->ai.h1 = e->ai.h + 100;
        else
            e->ai.h1 = -100;
        return (0);
    }
    else
        e->ai.h1 += 2 * e->ai.hu[1][1] - 2 * COMP_16;
    return (0);
}

int		calc_heuristic(int node)
{
    max_hu();
    hu_algo(node);
    !e->ai.startmove && ++e->ai.startmove && e->ai.p == 1 && COMP_15;
	e->ai.h < e->ai.h1 && (e->ai.n = node) && (e->ai.h = e->ai.h1);
	return (0);
}

void	max_hu(void)
{
	int		x;

	x = 0;
	while (++x < 27)
	{
		if ((x < 5 || (x > 15 && x < 26)) && e->ai.hu[1][x] > e->ai.hu[3][x])
			e->ai.hu[3][x] = e->ai.hu[1][x];
        if (x == 5 && ((e->ai.hu[1][24] > e->ai.hu[3][24] && e->ai.hu[1][24]
            > e->ai.hu[3][25]) || (e->ai.hu[1][25] > e->ai.hu[3][24] &&
            e->ai.hu[1][25] > e->ai.hu[3][25])) && ((e->ai.hu[3][5] = \
            e->ai.hu[1][5]) || 1) && ((e->ai.hu[3][6] = e->ai.hu[1][6]) || 1)
            && ((e->ai.hu[3][7] = e->ai.hu[1][7]) || 1) && ((e->ai.hu[3][8] = \
            e->ai.hu[1][8]) || 1) && ((e->ai.hu[3][9] = e->ai.hu[1][9]) || 1))
        {
            e->ai.hu[3][0] = e->ai.hu[1][0];
            captures_on_max_align((int)e->ai.hu[3][7], (int)e->ai.hu[3][8], 10);
            e->gomoku.map[0][(int)e->ai.hu[3][8]][(int)e->ai.hu[3][7]] = e->ai.p;
            captures_on_max_align((int)e->ai.hu[3][7], (int)e->ai.hu[3][8], 12);
            e->gomoku.map[0][(int)e->ai.hu[3][8]][(int)e->ai.hu[3][7]] = e->ai.o;
            captures_on_max_align((int)e->ai.hu[3][7], (int)e->ai.hu[3][8], 14);
            e->gomoku.map[0][(int)e->ai.hu[3][8]][(int)e->ai.hu[3][7]] = 0;
        }
    }
}
