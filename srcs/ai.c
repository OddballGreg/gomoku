#include "../includes/gomoku.h"

long	timing(void)
{
	struct timeval		time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	ai(void)
{
    long    t;

    t = timing();
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
    //             0.001
    //500000000 is 0.5 seconds
  //  auto end = std::chrono::high_resolution_clock::now();
  //  std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(end-begin).count() << "ns" << std::endl;  
	//print_map();
    mvwprintw(E_WIN[WIN_STATS], 17, 1, "TIME: %dms", timing() - t);
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





//l.cpp	//heuristics(ai algorithms) continued
/*
void	print_hu(int n)
{//REMOVE
//    int     tx;
//	t_e		*e;

//    tx = -1;
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
*/


void	copy(int n, int o)
{
	int		x;
//	t_e		*e;

	x = -1;
//	e = cloud(0, 1);
	while (++x < 27)
		e->ai.hu[o][x] = e->ai.hu[n][x];
}




//g.cpp


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



