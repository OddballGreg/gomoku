#include "../includes/gomoku.h"

int		heuristics2(int node)
{//this heuristic will check aligns as per the written document.
    int     b;
    int		c[3];
//	t_e		*e;

	bzero(c, 3);
//	e = cloud(0, 1);
	c[0] = max_aligns(16, 0, -1);//N		1
    c[1] = max_aligns(17, 0, 1);//S			1
	(b = get_max_aligned(c[0], c[1], 0)) > 0 && ((e->ai.hu[1][5] = 0) || 1) && (e->ai.hu[1][6] = -1) && (e->ai.hu[1][9] = b);
	bzero(c, 3);    
	c[0] = max_aligns(18, 1, -1);//NE		2
	c[1] = max_aligns(21, -1, 1);//SW		2
	(b = get_max_aligned(c[0], c[1], 0)) > 0 && (e->ai.hu[1][5] = 1) && (e->ai.hu[1][6] = -1) && (e->ai.hu[1][9] = b);
	bzero(c, 3);
    c[0] = max_aligns(19, -1, -1);//NW		3
    c[1] = max_aligns(20, 1, 1);//SE		3
	(b = get_max_aligned(c[0], c[1], 0)) > 0 && (e->ai.hu[1][5] = -1) && (e->ai.hu[1][6] = -1) && (e->ai.hu[1][9] = b);
	bzero(c, 3);
    c[0] = max_aligns(22, 1, 0);//E         4
    c[1] = max_aligns(23, -1, 0);//W		4
	(b = get_max_aligned(c[0], c[1], 0)) > 0 && (e->ai.hu[1][5] = 1) && ((e->ai.hu[1][6] = 0) || 1) && (e->ai.hu[1][9] = b);
	return (0);//in all directions returns a counter of how many 3 threats occur to current block
}

int		heuristics1(int node)
{	//get the rest of the heuristics here.
//this heuristics determines capture opportunities vs threats.
	int		o;//SHOULD PROBABLY PLACE THESE IN THE AI STRUCT.
	int		p;
	int		c;//counter for oportunities created
	int		t;//threats created
//	t_e		*e;

//	e = cloud(0, 1);
	heuristics2(node);//gets max_align info
	e->gomoku.map[0][e->ai.y][e->ai.x] = e->ai.p;
	//look at node as if have already played here(thus looking around the node)
	//tmp place the piece and then count the capture oportunities and threats
	//around the node.
	c = opportunities_threats(3, 1, e->ai.o, e->ai.p);//this is 3 away in all directions to check
	c += opportunities_threats(2, 1, e->ai.o, e->ai.p);	//capture opportunities count
	c += opportunities_threats(1, 1, e->ai.o, e->ai.p);

	t = opportunities_threats(3, 2, e->ai.p, e->ai.o);
	t += opportunities_threats(2, 2, e->ai.p, e->ai.o);
	t += opportunities_threats(1, 2, e->ai.p, e->ai.o);//difference, map no, oponent, player
		//capture opponent threats on current node count

	//ai
	e->ai.hu[1][3] = c;//one ahead capture opportunities
	e->ai.hu[1][4] = t;//one ahead capture threats

	//opponent
	e->ai.hu[2][3] = t;//one ahead capture opportunities
	e->ai.hu[2][4] = c;//one ahead capture threats

//	e->ai.h1 += c;
//	e->ai.h1 -= t;//* 2 if we are losing on captures count
//e->gomoku.map[0][e->ai.y][e->ai.x]
//is_capture(int x, int y, int o, int p)
	e->gomoku.map[0][e->ai.y][e->ai.x] = e->ai.o;
	//look at node as oponent here	
	e->gomoku.map[0][e->ai.y][e->ai.x] = 0;	
	///e->ai.h1 += heuristics2(node);//requires map[y][x] to be 0
	return (1);
}
