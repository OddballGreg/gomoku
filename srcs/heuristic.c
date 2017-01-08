#include "../includes/gomoku.h"
//j.cpp AI STARTS 	//ai algorithms

int		heuristics(int node)
{
//	int			c;//tmp variable
	int			x;
	int			y;
//	t_e			*e;

//	e = cloud(0, 1);
	if (node < 0 && (e->ai.n = e->ai.h = y = -1))
	{//reset everything and return
		while (++y < 5 && (x = -1))
			while (++x < 27)
				e->ai.hu[y][x] = 0; 
		return (-1);
	}
	e->ai.h1 = 0;//REMOVE or use to determine the switch of nodes.
	x = -1;
	while (++x < 27)
		if (!(e->ai.hu[1][x] = 0))
			 e->ai.hu[2][x] = 0; 	

	e->ai.p = e->gomoku.player_turn;//once
    e->ai.o = 2 - (e->gomoku.player_turn == 2);//only needs be done once
	e->ai.x = node % 19 + 19 * !(node % 19) - 1;
	e->ai.y = node / 19 - (e->ai.x == 18);
	//opportunities threats(+ depending on who has the advantage, weight is placed oppropriately on the better suited option in specific circumstances):

//	e->ai.h1 += e->gomoku.map[1][e->ai.y][e->ai.x] + e->gomoku.map[2][e->ai.y][e->ai.x];
//	e->ai.c = e->player[e->ai.player_no].captures - e->player[2 - (e->ai.player_no == 2)].captures;
//	e->gomoku.map[1][e->ai.y][e->ai.x] && e->ai.c >= 0 && (e->ai.h1 += e->ai.c);//needs to be 
//	e->gomoku.map[2][e->ai.y][e->ai.x] && e->ai.c < 0 && (e->ai.h1 += -e->ai.c);//ratio'd

	//ai
	e->ai.hu[1][0] = node;	
	e->ai.hu[1][1] = e->gomoku.map[1][e->ai.y][e->ai.x];//current capture opportunities
	e->ai.hu[1][2] = e->gomoku.map[2][e->ai.y][e->ai.x];//current threats
    e->ai.hu[1][7] = e->ai.x;
    e->ai.hu[1][8] = e->ai.y;
    //opponent
        //here
    heuristics1(node);//			in order to decide proportionally better as captures arent
					  // 			as important as oponent alignments but their alignment is not
					  //			as important as your alignment provided they cannot capture
					  //			on that line and thus resulting in a loss.
	calc_heuristic(node);
	return (e->ai.n);//will return node that is best fit later
}

int		minimax(int node, int depth, int maximizing_player)
{
	(void)depth;
	if (!maximizing_player)
		return (heuristics(-1));
	return (heuristics(node));
}

void	possible_solutions(void)
{
	//int	b;//best value
	int		x;
	int		y;
	int		z;
//	t_e		*e;

	z = 0;
	y = -1;
//	e = cloud(0, 1);
	while (++y < 19 && (x = -1))
		while (++x < 19 && (++z))
			if (!e->gomoku.map[0][y][x] && !e->gomoku.map[3][y][x])
				e->ai.node = minimax(z, z, 1);//node, depth, maximizing_player
			//if block is empty and playable than check in all directions all types of scenarios and place them in memory.
			//no need to place in memory anymore.
//	printf("BEST VALUE: %d\n", e->ai.node);
}
