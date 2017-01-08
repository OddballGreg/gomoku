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

void    possible_captures(int n, int o, int p)
{
    int     x;
    int     y;
    
    y = -1;
    while (++y < 18 && (x = -1))
    {
        while (++x < 18)
        {
            if (!e->gomoku.map[0][y][x])
            {
                x + 3 < 19 && M_POS_20 && M_POS_21 && M_POS_22 && M_POS_44;
                x - 3 >= 0 && M_POS_23 && M_POS_24 && M_POS_25 && M_POS_44;
                y + 3 < 19 && M_POS_26 && M_POS_27 && M_POS_28 && M_POS_44;
                y - 3 >= 0 && M_POS_29 && M_POS_30 && M_POS_31 && M_POS_44;
                x + 3 < 19 && M_POS_32 && M_POS_33 && M_POS_45 && M_POS_44;
                x - 3 >= 0 && y + 3 < 19 && M_POS_34 && M_POS_36 &&
                    M_POS_37 && M_POS_44;
                x + 3 < 19 && y - 3 >= 0 && M_POS_38 && M_POS_39 &&
                    M_POS_40 && M_POS_44;
                x - 3 >= 0 && y - 3 >= 0 && M_POS_41 && M_POS_42 &&
                    M_POS_43 && M_POS_44;
            }
        }
    }
}


void    apply_capture(void)
{
    int     o;
    int     p;
    int     x;
    int     y;

    x = e->gomoku.cursorx;
    y = e->gomoku.cursory;
    o = 2 - (e->gomoku.player_turn == 2);
    p = e->gomoku.player_turn;
    M_CAP_09 += x + 3 < 19 && M_POS_20 && M_POS_21 && M_POS_22 &&
        N_MAP[y][x + 2] = 0) && N_MAP[y][x + 1] = 0);
    M_CAP_09 += x - 3 >= 0 && M_POS_23 && M_POS_24 && M_POS_25 &&
        N_MAP[y][x - 2] = 0) && N_MAP[y][x - 1] = 0);
    M_CAP_09 += y + 3 < 19 && M_POS_26 && M_POS_27 && M_POS_28 &&
        N_MAP[y + 2][x] = 0) && N_MAP[y + 1][x] = 0);
    M_CAP_09 += y - 3 >= 0 && M_POS_29 && M_POS_30 && M_POS_31 &&
        N_MAP[y - 2][x] = 0) && N_MAP[y - 1][x] = 0);
    M_CAP_09 += x + 3 < 19 && M_POS_32 && M_POS_33 && M_POS_45 &&
        N_MAP[y + 2][x + 2] = 0) && N_MAP[y + 1][x + 1] = 0);
    M_CAP_09 += x - 3 >= 0 && y + 3 < 19 && M_POS_34 && M_POS_36 &&
        M_POS_37 && N_MAP[y + 2][x - 2] = 0) && N_MAP[y + 1][x - 1] = 0);
    M_CAP_09 += x + 3 < 19 && y - 3 >= 0 && M_POS_38 && M_POS_39 &&
        M_POS_40 && N_MAP[y - 2][x + 2] = 0) && N_MAP[y - 1][x + 1] = 0);
    M_CAP_09 += (x - 3 >= 0 && y - 3 >= 0 && M_POS_41 && M_POS_42 &&
        M_POS_43 && N_MAP[y - 2][x - 2] = 0) && N_MAP[y - 1][x - 1] = 0));
}
