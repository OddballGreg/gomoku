#include "../includes/gomoku.h"
//mapping algorithms and ai extention algorithms here onwards

//possible 5 in a row
//capture possibilities
//double threes

//h.cpp

int		is_capture(int x, int y, int o, int p)
{//would tell how many captures on block
	int		c;

	c = 0;
	c += (x + 3 < 19 && e->gomoku.map[0][y][x + 1] == o && e->gomoku.map[0][y][x + 2] == o && e->gomoku.map[0][y][x + 3] == p);// && (c += 1);
	c += (x - 3 >= 0 && e->gomoku.map[0][y][x - 1] == o && e->gomoku.map[0][y][x - 2] == o && e->gomoku.map[0][y][x - 3] == p);// && (c += 1));
	c += (y + 3 < 19 && e->gomoku.map[0][y + 1][x] == o && e->gomoku.map[0][y + 2][x] == o && e->gomoku.map[0][y + 3][x] == p);// && (c += 1));
	c += (y - 3 >= 0 && e->gomoku.map[0][y - 1][x] == o && e->gomoku.map[0][y - 2][x] == o && e->gomoku.map[0][y - 3][x] == p);// && (c += 1));
	c += (x + 3 < 19 && y + 3 < 19 && e->gomoku.map[0][y + 1][x + 1] == o && e->gomoku.map[0][y + 2][x + 2] == o && e->gomoku.map[0][y + 3][x + 3] == p);// && (c += 1);
	c += (x - 3 >= 0 && y + 3 < 19 && e->gomoku.map[0][y + 1][x - 1] == o && e->gomoku.map[0][y + 2][x - 2] == o && e->gomoku.map[0][y + 3][x - 3] == p);// && (c += 1);
	c += (x + 3 < 19 && y - 3 >= 0 && e->gomoku.map[0][y - 1][x + 1] == o && e->gomoku.map[0][y - 2][x + 2] == o && e->gomoku.map[0][y - 3][x + 3] == p);// && (c += 1);
	c += (x - 3 >= 0 && y - 3 >= 0 && e->gomoku.map[0][y - 1][x - 1] == o && e->gomoku.map[0][y - 2][x - 2] == o && e->gomoku.map[0][y - 3][x - 3] == p);// && (c += 1);	
	return (c);
}

void    possible_captures(int n, int o, int p)//n is map number, o is oponent, p is player
{//looking at oponents pieces.
    int     x;
    int     y;
//    t_e     *e;
    
    y = -1;
 //   e = cloud(0, 1);
    while (++y < 18 && (x = -1))
    {
        while (++x < 18)
        {
            if (!e->gomoku.map[0][y][x])
            {
//at campbus can replace below with:
	// e->gomoku.map[n][y][x] = is_capture(x, y, o, p);
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

float     free_three2(int x, int y,int xd, int yd)
{//function attempts to get count of all capture threats/ opportunities on max align
    //also perhaps to determine if a coordinate placement leads to a capture on max line.
    int     x1;
    int     y1;
    int     b;
    float   c;
    int     p;
    int     o;
//    t_e     *e;
    
    b = 0;
    c = 0.0;
    x1 = x;
    y1 = y;
//    e = cloud(0, 1);
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
    return (((c + 1 == 3) * !b) * 0.5);//then is free three
}

float     free_three(int x, int y, int xd, int yd)//free three algorithm
{
    static char     a[7];//5 integers to store three and check if its a free three
    int             c;
    int             n;
    int             b;
    int             o;
//    t_e             *e;
    
    b = -1;
    c = -1;
    bzero(a, 7);
//    e = cloud(0, 1);
    o = 2 - (e->gomoku.player_turn == 2);
    //get all values
	//going to have to add back:
    if (!(x - xd > -1 && x - xd < 19 && y - yd > -1 && y - yd < 19) || e->gomoku.map[0][y - yd][x - xd])
        return (free_three2(x, y, xd, yd));//then the data cannot possibly be a free three.
    //if (e->gomoku.map[0][y][x] == o)
    //    return (0);//cannot possibly be a free three
    a[++c] = e->gomoku.map[0][y][x] + 48 - (e->gomoku.map[0][y][x] == 2);
    while (++b < 7 && x + xd > -1 && x + xd < 19 && y + yd > -1 && y + yd < 19)
    {
        x += xd;
        y += yd;
        if (e->gomoku.map[0][y][x] == o)
            return (0);//cannot possibly be a free three
        a[++c] = e->gomoku.map[0][y][x] + 48 - (e->gomoku.map[0][y][x] == 2);
        //printf("%c", e->gomoku.map[0][y][x] + 48);
    }
    if (!strncmp(a, "1110", 4) || !strncmp(a, "10110", 5) || !strncmp(a, "11010", 5))
        return (1.0);//found a free
    //theory: catered for sides but not for center
    return (0.0);//did not find a free
}

void    double_free_threes(void)
{//
    int     x;
    int     y;
    int     p;
    float   c;
  //  t_e     *e;

    y = -1;
 //   e = cloud(0, 1);
    p = e->gomoku.player_turn;
    while (++y < 19 && (x = -1))
    {
        while (++x < 19)
        {
            c = 0.0;
            if (!e->gomoku.map[0][y][x])//0
            {
                e->gomoku.map[0][y][x] = p;//player turn
                
                c += free_three(x, y, 0, -1);//N     1
                c += free_three(x, y, 0, 1);//S     1
                c += free_three(x, y, 1, -1);//NE    2
                c += free_three(x, y, -1, 1);//SW   2
                c += free_three(x, y, 1, 1);//SE     3
                c += free_three(x, y, -1, -1);//NW  3
                c += free_three(x, y, 1, 0);//E      4
                c += free_three(x, y, -1, 0);//W    4
                c >= 2 && (e->gomoku.map[3][y][x] = c);
	            //then place on the correct map the correct value
                //counter should be capturing the returns and if return value becomes > 1 then
                //there would be more than one free three if the variable value were to be placed
                //there hence init this finding in map[]
                e->gomoku.map[0][y][x] = 0;
            }
			printw("%d", e->gomoku.player_turn);
        }
    }
}

void    get_rule_maps(void)
{//gets the extra maps for users helping(click - + keys to increment help(maps) or 'h')
 //   t_e     *e;
    
 //   e = cloud(0, 1);
    reset_rule_maps();
    double_free_threes();
    possible_captures(1, 2 - (e->gomoku.player_turn == 2), e->gomoku.player_turn);//what current player can capture(opportunities)
    possible_captures(2, e->gomoku.player_turn, 2 - (e->gomoku.player_turn == 2));//what oponent can capture(threats)
}











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

void	ai(void)
{
//    t_e		*e;
//    auto	begin = std::chrono::high_resolution_clock::now();
    // code to benchmark:
//    e = cloud(0, 1);
	possible_solutions();
	e->gomoku.cursorx = e->ai.node % 19 + 19 * !(e->ai.node % 19) - 1;
	e->gomoku.cursory = 18 - (e->ai.node / 19 - (e->gomoku.cursorx == 18)); 
    //000594374 pi
	//009013408 pi
	//010450955 pi
    //002751453 mac
    //003015375 mac latest
	//003291185
    //003254680
    //500000000 is 0.5 seconds
  //  auto end = std::chrono::high_resolution_clock::now();
  //  std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << "ns" << std::endl;  
	//print_map();
}

// k.cpp	//ai algorithms(continued)

int		opportunities_threats(int d, int n, int o, int p)
{//this function looks one a head to see if the placement of the piece at x y would result in
//more capture threats or opportunities.
	int		c;
//	t_e		*e;

	c = 0;
//	e = cloud(0, 1);
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

int     captures_on_max_align(int x1, int y1, int pos)
{//function attempts to get count of all capture threats/ opportunities on max align
//also perhaps to determine if a coordinate placement leads to a capture on max line.
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
 //   t_e     *e;
    
    c = 0;
    t = 0;
    fr = 0;//check if the line is a free
 //   e = cloud(0, 1);
    tx = e->ai.x;
    ty = e->ai.y;
    (e->ai.hu[3][24] >= e->ai.hu[3][25] && (p = e->ai.player_no)) || (p = 2 - (e->ai.player_no == 2));//will become the value we're looking for
    x = x1;//e->ai.hu[3][7];//xd yd startx start y of max
    y = y1;//e->ai.hu[3][8];
    xd = e->ai.hu[3][5] * (1 + -2 * (e->ai.hu[3][9] == 2));//e->ai.hu[3][9] determines direction
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
        c = opportunities_threats(3, 1, 2 - (p == 2), p);//this is 3 away in all directions to check
        c += opportunities_threats(2, 1, 2 - (p == 2), p);	//capture opportunities count
        c += opportunities_threats(1, 1, 2 - (p == 2), p);
        t = opportunities_threats(3, 2, p, 2 - (p == 2));
        t += opportunities_threats(2, 2, p, 2 - (p == 2));
        t += opportunities_threats(1, 2, p, 2 - (p == 2));//difference, map no, oponent, player
    }
    fr += (x - xd < 19 && x - xd > -1 && y - yd < 19 && y - yd > -1 && !e->gomoku.map[0][y - yd][x - xd]);
    e->ai.hu[3][pos] = c;
    e->ai.hu[3][pos + 1] = t;
    fr == 2 && (e->ai.hu[3][26] = 1);//then is a free
    //e->ai.hu[3][9]//direction
 //   if (p == e->ai.player_no)
 //   {
 //       printf("opportunity\n");//then t is the threat and c is the opportunity
 //    //otherwise its the other way around
 //   }
//    else
//        printf("threat\n");
    
    //travel along the line (all required directions) and           -CHECK
    //see if any captures lie on that line (later can parse a parameter x y to determine if placing a piece there causes a capture on line).
    //    1221      2112
    //o     2
        //2110     0112     oponent can capture ai
    //ai    1
        //1220     0221     ai can capture oponent
    
    //  2
    //    2
    //      2   2
    //        2                             //all directions of node placement check 1 2 3 away
    //       1  2
    //  where blank position, and if oponent can capture (where it could not before(map 1, 2)),
    //  then there is a capture threat hence increment the counter though: opponent align and ai
                            ///align need be looked at.
   //if opponent were to place their piece how many threats/opportunities would be created
   //if ai were to place the piece how may threats/opportunities would be created
   //threats to opportunities to current capture count to 5 align of oponent/ai will determine whether it is a good idea or a bad idea for ai to play at node, therefore THIS algorithm
    //will only be called if new node is introducing a greater max aligned on either oponent or ai.
    
    
    //USE:
/*
    c = opportunities_threats(3, 1, e->ai.o, e->ai.p);//this is 3 away in all directions to check
    c += opportunities_threats(2, 1, e->ai.o, e->ai.p);	//capture opportunities count
    c += opportunities_threats(1, 1, e->ai.o, e->ai.p);
    
    t = opportunities_threats(3, 2, e->ai.p, e->ai.o);
    t += opportunities_threats(2, 2, e->ai.p, e->ai.o);
    t += opportunities_threats(1, 2, e->ai.p, e->ai.o);//difference, map no, oponent, player
*/
    return (0 + (e->ai.x = tx) * 0 + (e->ai.y = ty) * 0);//resets e->ai.y and e->ai.x
}


int     max_aligns(int hu, int xd, int yd)//based off the free three algorithm(but different)
{
    int             c;
    int             n;
    int             b;
	int				node;
	int				x;
	int				y;
  //  t_e             *e;
    
    b = -1;
    c = -1;
	node = 0;//determines which player to look out for    
  //  e = cloud(0, 1);
	x = e->ai.x;
	y = e->ai.y;
    while (++b < 7 && x + xd > -1 && x + xd < 19 && y + yd > -1 && y + yd < 19 && e->gomoku.map[0][y + yd][x + xd])
	{
		x += xd;
		y += yd;
		!node && (node = e->gomoku.map[0][y][x]);
		if (node != e->gomoku.map[0][y][x] && (b = 8))
			continue;//returns out of the loop
		++c;//] = e->gomoku.map[0][y][x] + 48;
	}
	e->ai.hu[1][hu] = ++c * (1 + (-2 * (node != e->ai.player_no)));
	return (c * (1 + (-2 * (node != e->ai.player_no))));//SHOULD RETURN the counter of how many
}

int		get_max_aligned(int x, int y, int z)
{//places the aligns into the array: 24 25
	int		b;
//	t_e		*e;

	b = 0;
//	e = cloud(0, 1);
    //1 directional:
	x > e->ai.hu[1][24]  && (b = 1) && (e->ai.hu[1][24] = x);
	-x > e->ai.hu[1][25] && (b = 1) && (e->ai.hu[1][25] = -x);
    //1 -directional:
	y > e->ai.hu[1][24]  && (b = 2) && (e->ai.hu[1][24] = y);
	-y > e->ai.hu[1][25] && (b = 2) && (e->ai.hu[1][25] = -y);

	x <= 0 && y <= 0  && (z = x + y);
	x >= 0 && y >= 0  && (z = x + y);
    //bi directional:
	z > e->ai.hu[1][24]  && (b = 3) && (e->ai.hu[1][24] = z);
	-z > e->ai.hu[1][25] && (b = 3) && (e->ai.hu[1][25] = -z);
	return (b);
}

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

//l.cpp	//heuristics(ai algorithms) continued

void	print_hu(int n)
{
    int     tx;
//	t_e		*e;

    tx = -1;
 //   e = cloud(0, 1);
//	e->ai.h < 0 && printf("\t\tDEBUG MODE:\n");
//	while (++tx < 27)
//	{
		//tx == 0 && printf("%d ", node);
		//printf("%d ", (int)e->ai.hu[n][tx]);
		//if (tx == 26)
		//	printf("\n");
//	}
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

void	copy(int n, int o)
{
	int		x;
//	t_e		*e;

	x = -1;
//	e = cloud(0, 1);
	while (++x < 27)
		e->ai.hu[o][x] = e->ai.hu[n][x];
}

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
    print_hu(1);//hu number to print out
    hu_algo(node);//will apply approximately zdoc SEUDO here. and h1 will determine whether or not this node is the best opportunity. 
//	e = cloud(0, 1);
	//calc heuristics here and store in n the node

    !e->ai.startmove && ++e->ai.startmove && e->ai.p == 1 && !e->gomoku.map[0][9][9] && e->ai.h < 1 && (e->ai.n = 181);//player start position (should preferably be minutely more random || calculated though needs to be only when is player 1 and when it is the start move)
	e->ai.h < e->ai.h1 && (e->ai.n = node) && (e->ai.h = e->ai.h1);//get heuristics for node here and then compare h and n thereafter to		
	return (0);
}


//g.cpp
void	reset_rule_maps(void)
{
    char	x;
    char	y;
    char    z;
//    t_e     *e;
    
    y = -1;
//    e = cloud(0, 1);
    while (++y < 19 && (x = -1))
        while (++x < 19 && !(z = 0))
            while (++z < 7)//1 up to 7 maps
                e->gomoku.map[z][y][x] = 0;
}

void	reset_map(void)
{//on 
	char	x;
	char	y;
//	t_e     *e;

	y = -1;
//	e = cloud(0, 1);
	while (++y < 19 && (x = -1))
		while (++x < 19)
			E_BOARD[x + 1][y + 1] = e->gomoku.map[0][y][x];
}


//i.cpp			//rules application


void    apply_capture(void)
{
    int     o;
    int     p;
    int     x;
    int     y;
 //   t_e     *e;
    
  //  e = cloud(0, 1);
    x = e->gomoku.cursorx;
    y = e->gomoku.cursory;
    o = 2 - (e->gomoku.player_turn == 2);//old player is the player
    p = e->gomoku.player_turn;//the current player is now the opponent
    e->player[p].captures += x + 3 < 19 && e->gomoku.map[0][y][x + 1] == o && e->gomoku.map[0][y][x + 2] == o && e->gomoku.map[0][y][x + 3] == p && !(e->gomoku.map[0][y][x + 2] = 0) && !(e->gomoku.map[0][y][x + 1] = 0);
    
    e->player[p].captures += x - 3 >= 0 && e->gomoku.map[0][y][x - 1] == o && e->gomoku.map[0][y][x - 2] == o && e->gomoku.map[0][y][x - 3] == p && !(e->gomoku.map[0][y][x - 2] = 0) && !(e->gomoku.map[0][y][x - 1] = 0);
    
    e->player[p].captures += y + 3 < 19 && e->gomoku.map[0][y + 1][x] == o && e->gomoku.map[0][y + 2][x] == o && e->gomoku.map[0][y + 3][x] == p && !(e->gomoku.map[0][y + 2][x] = 0) && !(e->gomoku.map[0][y + 1][x] = 0);
    
    e->player[p].captures += y - 3 >= 0 && e->gomoku.map[0][y - 1][x] == o && e->gomoku.map[0][y - 2][x] == o && e->gomoku.map[0][y - 3][x] == p && !(e->gomoku.map[0][y - 2][x] = 0) && !(e->gomoku.map[0][y - 1][x] = 0);
    
    e->player[p].captures += x + 3 < 19 && y + 3 < 19 && e->gomoku.map[0][y + 1][x + 1] == o && e->gomoku.map[0][y + 2][x + 2] == o && e->gomoku.map[0][y + 3][x + 3] == p && !(e->gomoku.map[0][y + 2][x + 2] = 0) && !(e->gomoku.map[0][y + 1][x + 1] = 0);
    
    e->player[p].captures += x - 3 >= 0 && y + 3 < 19 && e->gomoku.map[0][y + 1][x - 1] == o && e->gomoku.map[0][y + 2][x - 2] == o && e->gomoku.map[0][y + 3][x - 3] == p && !(e->gomoku.map[0][y + 2][x - 2] = 0) && !(e->gomoku.map[0][y + 1][x - 1] = 0);
    
    e->player[p].captures += x + 3 < 19 && y - 3 >= 0 && e->gomoku.map[0][y - 1][x + 1] == o && e->gomoku.map[0][y - 2][x + 2] == o && e->gomoku.map[0][y - 3][x + 3] == p && !(e->gomoku.map[0][y - 2][x + 2] = 0) && !(e->gomoku.map[0][y - 1][x + 1] = 0);
    
    e->player[p].captures += (x - 3 >= 0 && y - 3 >= 0 && e->gomoku.map[0][y - 1][x - 1] == o && e->gomoku.map[0][y - 2][x - 2] == o && e->gomoku.map[0][y - 3][x - 3] == p && !(e->gomoku.map[0][y - 2][x - 2] = 0) && !(e->gomoku.map[0][y - 1][x - 1] = 0));
}

void    apply_rules(void)
{//applies rules onto the move made by ai or (normal)player
    apply_capture();//if there are any captures applies captures
    //determining who wins can be seen in f.cpp : void  gomoku(void)
}

int    player_wins_check(void)
{//checks if player wins by 5 aligns.
    int     p;
    int     x;
    int     y;
    int     tx;
    int     ty;
//    t_e     *e;
//instead of exit should rather change a bool to wait and go back to main menu, but is not mandatory
    y = -1;
 //   e = cloud(0, 1);
    p = e->gomoku.player_turn;
    while (++y < 19 && (x = -1))
    {
        while (++x < 19)
        {
            if (x + 4 < 19 && e->gomoku.map[0][y][x] == p && e->gomoku.map[0][y][x + 1] == p && e->gomoku.map[0][y][x + 2] == p && e->gomoku.map[0][y][x + 3] == p && e->gomoku.map[0][y][x + 4] == p)
                return (1);
            if (y + 4 < 19 && e->gomoku.map[0][y][x] == p && e->gomoku.map[0][y + 1][x] == p && e->gomoku.map[0][y + 2][x] == p && e->gomoku.map[0][y + 3][x] == p && e->gomoku.map[0][y + 4][x] == p)
                return (1);//exit(printf("player %d wins\n", e->gomoku.player_turn));
            if (y + 4 < 19 && x + 4 < 19 && e->gomoku.map[0][y][x] == p && e->gomoku.map[0][y + 1][x + 1] == p && e->gomoku.map[0][y + 2][x + 2] == p && e->gomoku.map[0][y + 3][x + 3] == p && e->gomoku.map[0][y + 4][x + 4] == p)
                return (1);//exit(printf("player %d wins\n", e->gomoku.player_turn));
            if (y + 4 < 19 && x - 4 >= 0 && e->gomoku.map[0][y][x] == p && e->gomoku.map[0][y + 1][x - 1] == p && e->gomoku.map[0][y + 2][x - 2] == p && e->gomoku.map[0][y + 3][x - 3] == p && e->gomoku.map[0][y + 4][x - 4] == p)
                return (1);//exit(printf("player %d wins\n", e->gomoku.player_turn));
            //check all directions below if player has 5 in a row
            
        }
    }
    return (0);
}