#include "../includes/gomoku.h"

int     hu_algo(int node)
{
	float	oh;//oponent heuristic on current node
//	t_e		*e;

	oh = 0;
//	e = cloud(0, 1);
	if (((e->ai.hu[3][26] && e->ai.hu[3][24] > 2 && e->ai.hu[3][24] >= e->ai.hu[3][25]) || e->ai.hu[3][24] >= 5) && node == e->ai.hu[3][0])
    {//o is o and t is t
        if (!(e->player[e->ai.p].captures + e->ai.hu[3][11] < 5 && e->player[e->ai.o].captures + e->ai.hu[3][10] == 5))//the opposite of below
            e->ai.h1 = e->ai.h + 100;
        else
            e->ai.h1 = -100;
        //printf("CHECK AI ALIGNED\n");
        return (0);
    }
    else if (((e->ai.hu[3][26] && e->ai.hu[3][25] > 2 && e->ai.hu[3][25] > e->ai.hu[3][24]) || e->ai.hu[3][25] == 4) && node == e->ai.hu[3][0])
    {//o is t and t is o
        if (!(e->player[e->ai.p].captures + e->ai.hu[3][10] == 5 && e->player[e->ai.o].captures + e->ai.hu[3][11] < 5))
            e->ai.h1 = e->ai.h + 100;
        else
            e->ai.h1 = -100;
        //printf("CHECK OPONENT ALIGNED\n");
        return (0);
    }
    else//otherwise:
    {//base decision particularly on capture: opportunities vs threats here:
        if (e->ai.hu[3][25] >= 5)
            ;
        e->ai.h1 += 2 * e->ai.hu[1][1] - 2 * (e->ai.hu[1][2]) + e->ai.hu[1][3] - e->ai.hu[1][4];
       // printf("CHECK CAPTURES\n");
    }
    return (0);
}

int		calc_heuristic(int node)
{
//	t_e		*e;

	max_hu();//gets max
 //   print_hu(1);//hu number to print out
    hu_algo(node);//will apply approximately zdoc SEUDO here. and h1 will determine whether or not this node is the best opportunity. 
//	e = cloud(0, 1);
	//calc heuristics here and store in n the node

    !e->ai.startmove && ++e->ai.startmove && e->ai.p == 1 && !e->gomoku.map[0][9][9] && e->ai.h < 1 && (e->ai.n = 181);//player start position (should preferably be minutely more random || calculated though needs to be only when is player 1 and when it is the start move)
	e->ai.h < e->ai.h1 && (e->ai.n = node) && (e->ai.h = e->ai.h1);//get heuristics for node here and then compare h and n thereafter to		
	return (0);
}

void	max_hu(void)
{//gets the max value of each value
	int		x;
//	t_e		*e;

	x = 0;
//	e = cloud(0, 1);
	while (++x < 27)
	{
		if ((x < 5 || (x > 15 && x < 26)) && e->ai.hu[1][x] > e->ai.hu[3][x])
			e->ai.hu[3][x] = e->ai.hu[1][x];
        //below gets coordinates for max for later to determine if capture
        //hits max aligned:
        if (x == 5 && ((e->ai.hu[1][24] > e->ai.hu[3][24] && e->ai.hu[1][24] > e->ai.hu[3][25]) || (e->ai.hu[1][25] > e->ai.hu[3][24] && e->ai.hu[1][25] > e->ai.hu[3][25])) && ((e->ai.hu[3][5] = e->ai.hu[1][5]) || 1) && ((e->ai.hu[3][6] = e->ai.hu[1][6]) || 1) && ((e->ai.hu[3][7] = e->ai.hu[1][7]) || 1) && ((e->ai.hu[3][8] = e->ai.hu[1][8]) || 1) && ((e->ai.hu[3][9] = e->ai.hu[1][9]) || 1))
        {
            e->ai.hu[3][0] = e->ai.hu[1][0];//max node
            captures_on_max_align((int)e->ai.hu[3][7], (int)e->ai.hu[3][8], 10);//gets capture count on max aligned
            e->gomoku.map[0][(int)e->ai.hu[3][8]][(int)e->ai.hu[3][7]] = e->ai.p;//if ai placed piece at position:
            captures_on_max_align((int)e->ai.hu[3][7], (int)e->ai.hu[3][8], 12);
            e->gomoku.map[0][(int)e->ai.hu[3][8]][(int)e->ai.hu[3][7]] = e->ai.o;//if opponent placed piece at position:
            captures_on_max_align((int)e->ai.hu[3][7], (int)e->ai.hu[3][8], 14);
            e->gomoku.map[0][(int)e->ai.hu[3][8]][(int)e->ai.hu[3][7]] = 0;
            //e->ai.hu[3][26] = e->ai.hu[1][26];
        }
    }
    //    //x y of that node is at max; x y of current node should also be compared.
    //captures_on_max_align(e->ai.hu[3][7], e->ai.hu[3][8]);//if oponent played
    //this may vary as node is placed hence does this need to be tested and compared if oponent placed piece at node (to determine if placement at position is an opportunity or more of a threat to the oponent) and ai piece at node (to determine if it is more likely to win by blocking or by captures) etc ...
}
