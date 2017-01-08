#include "../includes/gomoku.h"

int		is_capture(int x, int y, int o, int p)
{
	int		c;

	c = 0;
	x + 3 < 19 && M_POS_20 && M_POS_21 && M_POS_22 && (c += 1);
	x - 3 >= 0 && M_POS_23 && M_POS_24 && M_POS_25 && (c += 1);
	y + 3 < 19 && M_POS_26 && M_POS_27 && M_POS_28 && (c += 1);
	y - 3 >= 0 && M_POS_29 && M_POS_30 && M_POS_31 && (c += 1);
	x + 3 < 19 && M_POS_32 && M_POS_33 && M_POS_35 && (c += 1);
	x - 3 >= 0 && y + 3 < 19 && M_POS_34 && M_POS_36 && M_POS_37 && (c += 1);
	x + 3 < 19 && y - 3 >= 0 && M_POS_38 && M_POS_39 && M_POS_40 && (c += 1);
	x - 3 >= 0 && y - 3 >= 0 && M_POS_41 && M_POS_42 && M_POS_43 && (c += 1);
	return (c);
}

void	possible_captures(int n, int o, int p)
{
	int		x;
	int		y;

	y = -1;
	while (++y < 18 && (x = -1))
	{
		while (++x < 18)
		{
			if (!e->gomoku.map[0][y][x])
			{
				x + 3 < 19 && M_POS_20 && M_POS_21 && M_POS_22 && INC_CAP;
				x - 3 >= 0 && M_POS_23 && M_POS_24 && M_POS_25 && INC_CAP;
				y + 3 < 19 && M_POS_26 && M_POS_27 && M_POS_28 && INC_CAP;
				y - 3 >= 0 && M_POS_29 && M_POS_30 && M_POS_31 && INC_CAP;
				x + 3 < 19 && M_POS_32 && M_POS_33 && M_POS_35 && INC_CAP;
				x - 3 >= 0 && y + 3 < 19 && M_POS_34 && M_POS_36 && M_POS_37 &&
					INC_CAP;
				x + 3 < 19 && y - 3 >= 0 && M_POS_38 && M_POS_39 && M_POS_40 &&
					INC_CAP;
				x - 3 >= 0 && y - 3 >= 0 && M_POS_41 && M_POS_42 && M_POS_43 &&
					INC_CAP;
			}
		}
	}
}


void	apply_capture(void)
{
	INIT_06;
	INIT_05;
	o = 2 - (e->gomoku.player_turn == 2);
	p = e->gomoku.player_turn;
	e->player[p].captures += x + 3 < 19 && M_POS_20 && M_POS_21 && M_POS_22 &&
		!(e->gomoku.map[0][y][x + 2] = 0) && !(e->gomoku.map[0][y][x + 1] = 0);
	e->player[p].captures += x - 3 >= 0 && M_POS_23 && M_POS_24 && M_POS_25 &&
		!(e->gomoku.map[0][y][x - 2] = 0) && !(e->gomoku.map[0][y][x - 1] = 0);
	e->player[p].captures += y + 3 < 19 && M_POS_26 && M_POS_27 && M_POS_28 &&
		!(e->gomoku.map[0][y + 2][x] = 0) && !(e->gomoku.map[0][y + 1][x] = 0);
	e->player[p].captures += y - 3 >= 0 && M_POS_29 && M_POS_30 && M_POS_31 &&
		!(e->gomoku.map[0][y - 2][x] = 0) && !(e->gomoku.map[0][y - 1][x] = 0);
	e->player[p].captures += x + 3 < 19 && M_POS_32 && M_POS_33 && M_POS_35 &&
		!(e->gomoku.map[0][y + 2][x + 2] = 0) &&
		!(e->gomoku.map[0][y + 1][x + 1] = 0);
	e->player[p].captures += x - 3 >= 0 && y + 3 < 19 && M_POS_34 && M_POS_36
		&& M_POS_37 && !(e->gomoku.map[0][y + 2][x - 2] = 0) &&
		!(e->gomoku.map[0][y + 1][x - 1] = 0);
	e->player[p].captures += x + 3 < 19 && y - 3 >= 0 && M_POS_38 && M_POS_39
		&& M_POS_40 && !(e->gomoku.map[0][y - 2][x + 2] = 0) &&
		!(e->gomoku.map[0][y - 1][x + 1] = 0);
	e->player[p].captures += (x - 3 >= 0 && y - 3 >= 0 && M_POS_41 &&
			M_POS_42 && M_POS_43 && !(e->gomoku.map[0][y - 2][x - 2] = 0) &&
			!(e->gomoku.map[0][y - 1][x - 1] = 0));
}
