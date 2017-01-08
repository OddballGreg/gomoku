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


/*
** shad ai
*/
# define HU_MAX 28

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
