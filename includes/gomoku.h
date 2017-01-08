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
{//struct for ai algorithm
	int             startmove;//if player 1 and startmove then player has to thus place the piece first.
	int				node;//node number to be able to get appropriate x y coords
	int				p;//player
	int				o;//oponent
	int				n;//node in memory to compare heuristics with other nodes	
	float			h;//heuristic value of above node
	float			h1;//tmp to get heuristics and compare with h(best value) above
	float			hu[5][HU_MAX];
	int				c;//determines who is winning by captures currently.
	int				x;//x
	int				y;//y coords for calculating huristics
	int				difficulty;
	char			player_no;
	char    		prev_player_no;//will be used to determin ai's current
	//player number
}					t_ai;

typedef struct		s_player
{//struct to stor players information
	int				captures;//5 captures(which amounts to 10 stones wins you the game).
}               	t_player;

typedef struct		s_gomoku
{//struct for the gomoku map and displaying of the map and player piece placement: cursor x and y.
	char			map_pointer;//tells which map to display
	//map for 'double threes', '5 in row/more', possible 'capture' placements, oponent 'capture-threats', and debug map(which shows everything simultaneously)
	char			map[7][19][19];//0 main, 1 opportunity captures, 2 threat captures, 3 double freethrees,
	//4 free threes
	char			player_turn;//not yet used
	char			curr_player;//bool to wait for player to
	//finalize their move.
//	long			sub;//changes icosahedron / map
	char			cursorx;
	char			cursory;
//	float			scalex;
//	float			scaley;
//	float			scalez;
}					t_gomoku;

typedef struct		s_e
{//environment struct for everything
//	t_menu			main;
//	t_menu			difficulty;
//	t_menu			pause;

//	int				game_mode;//to identify whether to wait for player or wait let ai takeover.
	//the move.
	t_ai			ai;
//	t_eye			eye;
	t_gomoku		gomoku;
	t_player		player[3];//data of both players
	int				x;//map looping for diplay
	int				y;//map looping     "
	//about gomoku:
//	GLfloat         starwarsvelocity;//message
//	float           starwarsview;//message
//	char            quotes[21][80];//message
//	int             noquotes;//message
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
** Proposed data structure:
*/

typedef struct		s_p_node
{
	int				depth; //total number of moves made to this point.
	int				minmax; //Weighting of the current move;
	int				max;//optional
	int				min;//optional
	int				child_weight;//Average/minmax weight of the branches children.
	t_coord			move;//the coordinates of the played piece.
	struct s_p_node	*child1;//Child with the best weight.
	struct s_p_node	*child2;//Child with the second best weight.
	struct s_p_node	*child3;//Child with the third best weight.
	struct s_p_node	*child4;//Child with the fourth best weight.
	struct s_p_node	*child5;//Child with the fith best weight.
}					t_p_node;

//Everytime a node gets created, it gets added to this list,
//to simplify the process of deleting nodes.
typedef struct		s_p_list
{
	t_p_node		*node;//pointer to the node.
	int				node_depth;//speeds up cleaning process.
	struct s_p_list	*next;
}					t_p_list;

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

void	get_rule_maps(void);//h.cpp

int		heuristics(int node);//j.cpp
void	ai(void);//k.cpp
int		heuristics1(int node);//k.cpp
int		calc_heuristic(int node);//l.cpp

void	reset_rule_maps(void);//g.cpp
void	reset_map(void);//g.cpp
void    apply_rules(void);//i.cpp
int    player_wins_check(void);//i.cpp

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
** free_wins.c
*/
void		free_wins(void);
void		clear_win(WINDOW *win, int width, int height);
void		clear_all_wins(void);
void		redraw_all_win(void);

/*
** heuristic.chars
*/
void		hpair(t_node *node, char **strings);
void		heuristic(t_node *node);

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
** options.chars
*/
void		getopts();

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
