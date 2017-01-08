/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gomoku.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khansman <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 13:37:53 by khansman          #+#    #+#             */
/*   Updated: 2016/11/28 13:37:54 by khansman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GOMOKU_H
# define GOMOKU_H

/*
** ----------\
** Includes   |
** ----------/
*/

# ifdef __APPLE__
#  include <strings.h>
# else
#  include <string.h>
# endif

# include <sys/time.h>
# include <stdlib.h>
# include <stdio.h>
# include <panel.h>
# include <ncurses.h>
# include <stdio.h>
# include <ctype.h>
# include <signal.h>
# include <time.h>

# include "../libft/includes/libft.h"

/*
** ----------\
** Defines    |
** ----------/
*/

/*
** Board
*/
# define EMPTY       0
# define WHITE       1
# define BLACK       2
# define OFF		 3

# define WIN         1
# define LOSE        2

/*
** Pattern Recognition String Offsets
*/
# define I_VERT     0
# define I_HOR		1
# define I_YEX		2
# define I_YENX		3

/*
** Node
*/
# define NODE_MAX	2000 

/*
** Weightings
*/
# define W_PAIR		2
# define W_QUAD		4
# define W_FIVE		10
# define W_CAP		25

/*
** Gameplay
*/
# define NTILES     19
# define ROWS       20
# define COLUMNS    20

# define P1_PIECE   'O'
# define P2_PIECE   'X'

/*
** Windows
*/
# define STAT_X     20
# define INFO_X     20

# define WIN_BOARD  0
# define WIN_STATS  1
# define WIN_INFO   2

# define BOARD_WID	env.win.board_size.x
# define BOARD_HEI	env.win.board_size.y

/*
** Game Mode
*/


/*
** Shorthand:
*/
# define AI env.ai
# define GAME env.game
# define GAMEMODE env.gamemode

# define E_WIN env.win.win
# define E_PAN env.win.panel

# define E_W_BPOS env.win.bpos
# define E_W_SPOS env.win.spos

# define E_BOARD  env.game.board
# define E_DEPTH  env.game.depth

# define SIG_R(X) (signo == X )

# define N_MAP  (e->gomoku.map[0]

/*
** shad ai
*/
# define HU_MAX 28

/*
** Other
*/
# define M_POS_01 !e->gomoku.map[0][e->ai.y + d][e->ai.x]
# define M_POS_02 !e->gomoku.map[n][e->ai.y + d][e->ai.x]
# define M_POS_03 !e->gomoku.map[0][e->ai.y - d][e->ai.x]
# define M_POS_04 !e->gomoku.map[n][e->ai.y - d][e->ai.x]
# define M_POS_05 !e->gomoku.map[0][e->ai.y][e->ai.x + d]
# define M_POS_06 !e->gomoku.map[n][e->ai.y][e->ai.x + d]
# define M_POS_07 !e->gomoku.map[0][e->ai.y][e->ai.x - d]
# define M_POS_08 !e->gomoku.map[n][e->ai.y][e->ai.x - d]
# define M_POS_09 e->ai.y + d < 19
# define M_POS_10 !e->gomoku.map[0][e->ai.y + d][e->ai.x + d]
# define M_POS_11 !e->gomoku.map[n][e->ai.y + d][e->ai.x + d]
# define M_POS_12 e->ai.y + d < 19
# define M_POS_13 !e->gomoku.map[0][e->ai.y + d][e->ai.x - d]
# define M_POS_14 !e->gomoku.map[n][e->ai.y + d][e->ai.x - d]
# define M_POS_15 e->ai.y - d > -1
# define M_POS_16 !e->gomoku.map[0][e->ai.y - d][e->ai.x + d]
# define M_POS_17 !e->gomoku.map[n][e->ai.y - d][e->ai.x + d]
# define M_POS_18 !e->gomoku.map[0][e->ai.y - d][e->ai.x - d]
# define M_POS_19 !e->gomoku.map[n][e->ai.y - d][e->ai.x - d]
# define M_POS_20 e->gomoku.map[0][y][x + 1] == o
# define M_POS_21 e->gomoku.map[0][y][x + 2] == o
# define M_POS_22 e->gomoku.map[0][y][x + 3] == p
# define M_POS_23 e->gomoku.map[0][y][x - 1] == o
# define M_POS_24 e->gomoku.map[0][y][x - 2] == o
# define M_POS_25 e->gomoku.map[0][y][x - 3] == p
# define M_POS_26 e->gomoku.map[0][y + 1][x] == o
# define M_POS_27 e->gomoku.map[0][y + 2][x] == o
# define M_POS_28 e->gomoku.map[0][y + 3][x] == p
# define M_POS_29 e->gomoku.map[0][y - 1][x] == o
# define M_POS_30 e->gomoku.map[0][y - 2][x] == o
# define M_POS_31 e->gomoku.map[0][y - 3][x] == p
# define M_POS_32 y + 3 < 19 && e->gomoku.map[0][y + 1][x + 1] == o
# define M_POS_33 e->gomoku.map[0][y + 2][x + 2] == o
# define M_POS_34 e->gomoku.map[0][y + 1][x - 1] == o
# define M_POS_35 e->gomoku.map[0][y + 3][x + 3] == p
# define M_POS_36 e->gomoku.map[0][y + 2][x - 2] == o
# define M_POS_37 e->gomoku.map[0][y + 3][x - 3] == p
# define M_POS_38 e->gomoku.map[0][y - 1][x + 1] == o
# define M_POS_39 e->gomoku.map[0][y - 2][x + 2] == o
# define M_POS_40 e->gomoku.map[0][y - 3][x + 3] == p
# define M_POS_41 e->gomoku.map[0][y - 1][x - 1] == o
# define M_POS_42 e->gomoku.map[0][y - 2][x - 2] == o
# define M_POS_43 e->gomoku.map[0][y - 3][x - 3] == p
# define M_POS_44 (e->gomoku.map[n][y][x] += 1)
# define M_POS_45 e->gomoku.map[0][y + 3][x + 3] == p

# define M_DPOS01 e->gomoku.map[0][v.y + v.yd][v.x + v.xd]
# define M_DPOS02 e->gomoku.map[0][v.y + yd][v.x + xd]

# define M_CAP_01 (c += is_capture(e->ai.x, e->ai.y + d, o, p))
# define M_CAP_02 (c += is_capture(e->ai.x, e->ai.y - d, o, p))
# define M_CAP_03 (c += is_capture(e->ai.x + d, e->ai.y, o, p))
# define M_CAP_04 (c += is_capture(e->ai.x - d, e->ai.y, o, p))
# define M_CAP_05 (c += is_capture(e->ai.x + d, e->ai.y + d, o, p))
# define M_CAP_06 (c += is_capture(e->ai.x - d, e->ai.y + d, o, p))
# define M_CAP_07 (c += is_capture(e->ai.x + d, e->ai.y - d, o, p))
# define M_CAP_08 (c += is_capture(e->ai.x - d, e->ai.y - d, o, p))
# define M_CAP_09 e->player[p].captures

# define COMP_01  e->ai.hu[3][24] >= e->ai.hu[3][25] && (v.p = e->ai.player_no)
# define COMP_02  (COMP_01) || (v.p = 2 - (e->ai.player_no == 2))
# define COMP_03 v.x + v.xd < 19 && v.x + v.xd > -1
# define COMP_04 v.x - v.xd < 19 && v.x - v.xd > -1 && v.y - v.yd < 19
# define COMP_05 COMP_03 && v.y + v.yd < 19 && v.y + v.yd
# define COMP_06 e->gomoku.map[0][v.y - v.yd][v.x - v.xd]
# define COMP_07 v.x + xd > -1 && v.x + xd < 19 && v.y + yd > -1
# define COMP_08 (e->gomoku.map[0][y - yd][x - xd] == v.o && ++v.b && 0)
# define COMP_09 e->ai.hu[3][24] >= 5) && node == e->ai.hu[3][0]
# define COMP_10 e->player[e->ai.o].captures + e->ai.hu[3][10] == 5
# define COMP_11 e->ai.hu[3][26] && e->ai.hu[3][24] > 2
# define COMP_12 e->ai.hu[3][26] && e->ai.hu[3][25] > 2
# define COMP_13 e->ai.hu[3][25] == 4) && node == e->ai.hu[3][0]
# define COMP_14 e->player[e->ai.o].captures + e->ai.hu[3][11] < 5
# define COMP_15 !e->gomoku.map[0][9][9] && e->ai.h < 1 && (e->ai.n = 181)
# define COMP_16 (e->ai.hu[1][2]) + e->ai.hu[1][3] - e->ai.hu[1][4]
# define COMP_17 v.x + 4 < 19 && e->gomoku.map[0][v.y][v.x]
# define COMP_18 e->gomoku.map[0][v.y][v.x + 1] == v.p
# define COMP_19 e->gomoku.map[0][v.y][v.x + 2] == v.p
# define COMP_20 e->gomoku.map[0][v.y][v.x + 3] == v.p
# define COMP_21 e->gomoku.map[0][v.y][v.x + 4] == v.p
# define COMP_22 e->gomoku.map[0][v.y][v.x] == v.p
# define COMP_23 e->gomoku.map[0][v.y + 1][v.x] == v.p
# define COMP_24 e->gomoku.map[0][v.y + 2][v.x] == v.p
# define COMP_25 e->gomoku.map[0][v.y + 3][v.x] == v.p
# define COMP_26 e->gomoku.map[0][v.y + 4][v.x] == v.p
# define COMP_27 e->gomoku.map[0][v.y + 1][v.x + 1] == v.p
# define COMP_28 e->gomoku.map[0][v.y + 2][v.x + 2] == v.p
# define COMP_29 e->gomoku.map[0][v.y + 3][v.x + 3] == v.p
# define COMP_30 e->gomoku.map[0][v.y + 4][v.x + 4] == v.p
# define COMP_31 e->gomoku.map[0][v.y + 1][v.x - 1] == v.p
# define COMP_32 e->gomoku.map[0][v.y + 2][v.x - 2] == v.p
# define COMP_33 e->gomoku.map[0][v.y + 3][v.x - 3] == v.p
# define COMP_34 e->gomoku.map[0][v.y + 4][v.x - 4] == v.p

/*
** ----------\
** Structures |
** ----------/
*/

typedef struct	s_coord
{
	int			x;
	int			y;
}				t_coord;

typedef struct	s_max_align
{
	int			p;
    int			x;
    int			y;
    int			xd;
    int			yd;
    int			c;
    int			t;
    int			tx;
    int			ty;
    int			fr;
}				t_max_align;

typedef struct	s_max_align2
{
	int			c;
	int			n;
	int			b;
	int			node;
	int			x;
	int			y;
}				t_max_align2;

typedef struct	s_f_three
{
	int			x1;
    int			y1;
    int			b;
    float		c;
    int			p;
	int			o;
}				t_f_three;

typedef struct	s_pwin
{
	int			p;
    int			x;
    int			y;
    int			tx;
    int			ty;
}				t_pwin;

typedef struct	s_node
{
	int			depth;
	int			minmax;
	int			branchweight;
	int			captures;
	int			gameover;
	char		board[NTILES + 1][NTILES + 1];
	t_coord		piece_played;
	int			parentid;
	int			child[255];
}				t_node;

typedef struct	s_game
{
	t_coord		last_played;
	int			depth;
	char		board[NTILES + 1][NTILES + 1];
	char		p1_captures;
	char		p2_captures;
}				t_game;

typedef struct		s_ai
{
	int             startmove;
	int				node;
	int				p;
	int				o;
	int				n;	
	float			h;
	float			h1;
	float			hu[5][HU_MAX];
	int				c;
	int				x;
	int				y;
	int				difficulty;
	char			player_no;
	char    		prev_player_no;
}					t_ai;

typedef struct		s_player
{
	int				captures;
}               	t_player;

typedef struct		s_gomoku
{
	char			map_pointer;
	char			map[7][19][19];
	char			player_turn;
	char			curr_player;
	char			cursorx;
	char			cursory;
}					t_gomoku;

typedef struct		s_e
{
	t_ai			ai;
	t_gomoku		gomoku;
	t_player		player[3];
	int				x;
	int				y;
}					t_e;

typedef struct	s_window
{
	WINDOW		*win[3];
	PANEL		*panel[3];
	t_coord		bpos;
	t_coord		spos;
	t_coord		board_size;
}				t_window;

typedef struct	s_env
{
	char		gamemode;
	char		verbose;
	t_game		game;
	t_ai		ai;
	t_window	win;
	t_e			e;
}				t_env;

/*
** ----------\
** Globals    |
** ----------/
*/

# ifdef MAIN_FILE
	t_env			env;
	t_e				*e;
# else

	extern t_env	env;
	extern t_e		*e;
# endif

/*
** ----------\
** Prototypes |
** ----------/
*/

/*
** ai.c
*/
long	timing(void);
void	ai(void);
int		opportunities_threats(int d, int n, int o, int p);
void	copy(int n, int o);
void	reset_map(void);

/*
** allign.c
*/
int     captures_on_max_align(int x1, int y1, int pos);
int     max_aligns(int hu, int xd, int yd);
int		get_max_aligned(int x, int y, int z);

/*
** captures.c
*/
int		is_capture(int x, int y, int o, int p);
void    possible_captures(int n, int o, int p);
void    apply_capture(void);

/*
** draw_grid.c
*/
void		draw_grid(WINDOW *win, int columns, int rows);

/*
** draw_win.c
*/
void    	draw_win(int x, int colour, WINDOW *win, const char *title);

/*
** exit_prog.c
*/
void		exit_prog(void);
void		error_quit(char *message);
void		exit_player_win(char player);

/*
** free.c
*/
int			ft_free(void **var);

/*
** free_threes.c
*/
float		free_three2(int x, int y,int xd, int yd);
float		free_three(int x, int y, int xd, int yd);
void		double_free_threes(void);

/*
** free_wins.c
*/
void		free_wins(void);
void		clear_win(WINDOW *win, int width, int height);
void		clear_all_wins(void);
void		redraw_all_win(void);

/*
** heuristic.chars (j.cpp)
*/
int			heuristics(int node);
int			minimax(int node, int depth, int maximizing_player);
void		possible_solutions(void);

/*
** heuristic2.c
*/
int		heuristics2(int node);
int		heuristics1(int node);

/*
** heuristic3.c
*/
int     hu_algo(int node);
int		calc_heuristic(int node);
void	max_hu(void);

/*
** init.c
*/
void		init_ai(void);
void    	init_wins(void);
void    	init_curses(void);
void		init_signals(void);

/*
** main.c
*/
void		dump_mem();
void		run_ncurses();

/*
** manage_ui.c
*/
void		draw_piece(t_coord move);
void		usermove(void);
void		manage_ui(void);

/*
** manage_wins.c
*/
void		set_3_win(int x, int y);
void		set_2_win(int x, int y);
void		set_1_win(int x, int y);
void		set_0_win(void);
void		manage_wins(void);

/*
** options.c
*/
void		getopts();

/*
** rules.c
*/
void    get_rule_maps(void);
void	reset_rule_maps(void);
void	apply_rules(void);
int		player_wins_check(void);

/*
** signals.c
*/
void		sig_handler(int signo);

/*
** ui_info.c
*/
void		draw_info(void);
void		draw_stats(void);

/*
** validate_move.c
*/
int			valid_move(t_coord move);
int			on_board(t_coord move);

/*
** win_checks.c
*/
int			is_vline(int pos_x);
int			is_plus(int pos_x, int	pos_y);
void		get_boardcr(int colums, int rows, int *x, int *y);
void		get_boardxy(int pos_x, int pos_y, int *x, int *y);

/*
**                                /----------\                                **
** ----- ----- ----- ----- ----- |  The End   | ----- ----- ----- ----- ----- **
**                                \----------/                                **
*/
#endif
