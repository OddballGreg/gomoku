#include "../includes/gomoku.h"

void    get_rule_maps(void)
{
	reset_rule_maps();
    double_free_threes();
    possible_captures(1, 2 - (e->gomoku.player_turn == 2), e->gomoku.player_turn);
    possible_captures(2, e->gomoku.player_turn, 2 - (e->gomoku.player_turn == 2));
}

void	reset_rule_maps(void)
{
    char	x;
    char	y;
    char    z;
    
    y = -1;
    while (++y < 19 && (x = -1))
        while (++x < 19 && !(z = 0))
            while (++z < 7)//1 up to 7 maps
                e->gomoku.map[z][y][x] = 0;
}

void    apply_rules(void)
{
    apply_capture();
}

int    player_wins_check(void)
{
    int     p;
    int     x;
    int     y;
    int     tx;
    int     ty;

    y = -1;
    p = e->gomoku.player_turn;
    while (++y < 19 && (x = -1))
    {
        while (++x < 19)
        {
            if (x + 4 < 19 && e->gomoku.map[0][y][x] == p && e->gomoku.map[0][y][x + 1] == p && e->gomoku.map[0][y][x + 2] == p && e->gomoku.map[0][y][x + 3] == p && e->gomoku.map[0][y][x + 4] == p)
                return (1);
            if (y + 4 < 19 && e->gomoku.map[0][y][x] == p && e->gomoku.map[0][y + 1][x] == p && e->gomoku.map[0][y + 2][x] == p && e->gomoku.map[0][y + 3][x] == p && e->gomoku.map[0][y + 4][x] == p)
                return (1);
            if (y + 4 < 19 && x + 4 < 19 && e->gomoku.map[0][y][x] == p && e->gomoku.map[0][y + 1][x + 1] == p && e->gomoku.map[0][y + 2][x + 2] == p && e->gomoku.map[0][y + 3][x + 3] == p && e->gomoku.map[0][y + 4][x + 4] == p)
                return (1);
            if (y + 4 < 19 && x - 4 >= 0 && e->gomoku.map[0][y][x] == p && e->gomoku.map[0][y + 1][x - 1] == p && e->gomoku.map[0][y + 2][x - 2] == p && e->gomoku.map[0][y + 3][x - 3] == p && e->gomoku.map[0][y + 4][x - 4] == p)
                return (1);
        }
    }
    return (0);
}
