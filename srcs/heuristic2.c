#include "../includes/gomoku.h"

int		heuristics2(int node)
{
    int     b;
    int		c[3];

	bzero(c, 3);
	c[0] = max_aligns(16, 0, -1);
    c[1] = max_aligns(17, 0, 1);
	(b = get_max_aligned(c[0], c[1], 0)) > 0 && ((e->ai.hu[1][5] = 0) || 1)
		&& (e->ai.hu[1][6] = -1) && (e->ai.hu[1][9] = b);
	bzero(c, 3);    
	c[0] = max_aligns(18, 1, -1);
	c[1] = max_aligns(21, -1, 1);
	(b = get_max_aligned(c[0], c[1], 0)) > 0 && (e->ai.hu[1][5] = 1)
		&& (e->ai.hu[1][6] = -1) && (e->ai.hu[1][9] = b);
	bzero(c, 3);
    c[0] = max_aligns(19, -1, -1);
    c[1] = max_aligns(20, 1, 1);
	(b = get_max_aligned(c[0], c[1], 0)) > 0 && (e->ai.hu[1][5] = -1)
		&& (e->ai.hu[1][6] = -1) && (e->ai.hu[1][9] = b);
	bzero(c, 3);
    c[0] = max_aligns(22, 1, 0);
    c[1] = max_aligns(23, -1, 0);
	(b = get_max_aligned(c[0], c[1], 0)) > 0 && (e->ai.hu[1][5] = 1) &&
		((e->ai.hu[1][6] = 0) || 1) && (e->ai.hu[1][9] = b);
	return (0);
}

int		heuristics1(int node)
{
	int		o;
	int		p;
	int		c;
	int		t;

	heuristics2(node);
	e->gomoku.map[0][e->ai.y][e->ai.x] = e->ai.p;
	c = opportunities_threats(3, 1, e->ai.o, e->ai.p);
	c += opportunities_threats(2, 1, e->ai.o, e->ai.p);
	c += opportunities_threats(1, 1, e->ai.o, e->ai.p);
	t = opportunities_threats(3, 2, e->ai.p, e->ai.o);
	t += opportunities_threats(2, 2, e->ai.p, e->ai.o);
	t += opportunities_threats(1, 2, e->ai.p, e->ai.o);
	e->ai.hu[1][3] = c;
	e->ai.hu[1][4] = t;
	e->ai.hu[2][3] = t;
	e->ai.hu[2][4] = c;
	e->gomoku.map[0][e->ai.y][e->ai.x] = e->ai.o;
	e->gomoku.map[0][e->ai.y][e->ai.x] = 0;	
	return (1);
}
