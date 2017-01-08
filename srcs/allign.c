#include "../includes/gomoku.h"

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
