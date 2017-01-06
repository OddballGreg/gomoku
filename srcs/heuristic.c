#include "../includes/gomoku.h"

void		h_pair(t_node *node, char **strings)
{
	int		value;
	int		i;
	char	piece;

	printf("Detecting Pairs\n");
	value = 0;
	i = -1;
	piece = strings[I_VERT][4];
	printf("Set Focal Point\n");
	while (++i < 4)
	{
		printf("I = %i\n", i);
		if (piece == BLACK)
		{
			if (strings[i][3] == piece)
				value += W_PAIR;
			if (strings[i][5] == piece)
				value += W_PAIR;
		}
		else if (piece == WHITE)
		{
			if (strings[i][3] == piece)
				value -= W_PAIR;
			if (strings[i][5] == piece)
				value -= W_PAIR;
		}
	}
	node->minmax += value;
	printf("Pairs Detected\n");
}

void		h_quad(t_node *node, char **strings)
{
	int		value;
	int		i;
	char	piece;

	printf("Detecting Quads\n");
	value = 0;
	i = -1;
	piece = strings[I_VERT][4];
	printf("Set Focal Point\n");
	while (++i < 4)
	{
		printf("I = %i\n", i);
		if (piece == BLACK)
		{
			if (strings[i][3] == piece && strings[i][2] == piece && strings[i][1] == piece)
				value += W_QUAD;
			if (strings[i][5] == piece && strings[i][6] == piece && strings[i][7] == piece)
				value += W_QUAD;
		}
		else if (piece == WHITE)
		{
			if (strings[i][3] == piece && strings[i][2] == piece && strings[i][1] == piece)
				value -= W_QUAD;
			if (strings[i][5] == piece && strings[i][6] == piece && strings[i][7] == piece)
				value -= W_QUAD;
		}
	}
	node->minmax += value;
	printf("Quads Detected\n");
}

void		h_five(t_node *node, char **strings)
{
	int		value;
	int		i;
	char	piece;

	printf("Detecting Fives\n");
	value = 0;
	i = -1;
	piece = strings[I_VERT][4];
	printf("Set Focal Point\n");
	while (++i < 4)
	{
		printf("I = %i\n", i);
		if (piece == BLACK)
		{
			if (strings[i][3] == piece && strings[i][2] == piece && strings[i][1] == piece && strings[i][0] == piece)
			{
				value += W_FIVE;
				node->gameover = WIN;
			}
			if (strings[i][5] == piece && strings[i][6] == piece && strings[i][7] == piece && strings[i][8] == piece)
			{
				node->gameover = WIN;
				value += W_FIVE;
			}
		}
		else if (piece == WHITE)
		{
			if (strings[i][3] == piece && strings[i][2] == piece && strings[i][1] == piece && strings[i][0] == piece)
			{
				node->gameover = LOSE;
				value -= W_FIVE;
			}
			if (strings[i][5] == piece && strings[i][6] == piece && strings[i][7] == piece && strings[i][8] == piece)
			{
				node->gameover = LOSE;
				value -= W_FIVE;
			}
		}
	}
	node->minmax += value;
	printf("Fives Detected\n");
}

void		rm_captures(t_node *node, int x, int y, int i, int dir)
{
	if (i == I_VERT)
	{
		if (dir == 0)
		{
			node->board[x - 1][y] = EMPTY;
			node->board[x - 2][y] = EMPTY;
		}
		else if (dir == 1)
		{
			node->board[x + 1][y] = EMPTY;
			node->board[x + 2][y] = EMPTY;
		}
	}
	else if (i == I_HOR)
	{
		if (dir == 0)
		{
			node->board[x][y - 1] = EMPTY;
			node->board[x][y - 2] = EMPTY;
		}
		else if (dir == 1)
		{
			node->board[x][y + 1] = EMPTY;
			node->board[x][y + 2] = EMPTY;
		}
	}
	else if (i == I_YEX)
	{
		if (dir == 0)
		{
			node->board[x - 1][y - 1] = EMPTY;
			node->board[x - 2][y - 2] = EMPTY;
		}
		else if (dir == 1)
		{
			node->board[x + 1][y + 1] = EMPTY;
			node->board[x + 2][y + 2] = EMPTY;
		}
	}
	else if (i == I_YENX)
	{
		if (dir == 0)
		{
			node->board[x - 1][y + 1] = EMPTY;
			node->board[x - 2][y + 2] = EMPTY;
		}
		else if (dir == 1)
		{
			node->board[x + 1][y - 1] = EMPTY;
			node->board[x + 2][y + 2] = EMPTY;
		}
	}
}

void		h_captures(t_node *node, char **strings, int x, int y)
{
	int		value;
	int		i;
	char	piece;

	printf("Detecting Captures\n");
	value = 0;
	i = -1;
	piece = strings[I_VERT][4];
	printf("Set Focal Point\n");
	while (++i < 4)
	{
		printf("I = %i\n", i);
		if (piece == BLACK)
		{
			if (strings[i][3] == WHITE && strings[i][2] == WHITE && strings[i][1] == BLACK)
			{
				value += W_CAP;
				node->captures += 1;
				if (node->captures == 5)
					node->gameover = WIN;
				rm_captures(node, x, y, i, 0);

			}
			if (strings[i][5] == WHITE && strings[i][6] == WHITE && strings[i][7] == BLACK)
			{
				value += W_CAP;
				node->captures += 1;
				if (node->captures == 5)
					node->gameover = WIN;
				rm_captures(node, x, y, i, 1);
			}
		}
		else if (piece == WHITE)
		{
			if (strings[i][3] == BLACK && strings[i][2] == BLACK && strings[i][1] == WHITE)
			{
				value -= W_CAP;
				node->captures += 1;
				if (node->captures == 5)
					node->gameover = LOSE;
				rm_captures(node, x, y, i, 0);
			}
			if (strings[i][5] == BLACK && strings[i][6] == BLACK && strings[i][7] == WHITE)
			{
				value -= W_CAP;
				node->captures += 1;
				if (node->captures == 5)
					node->gameover = LOSE;
				rm_captures(node, x, y, i, 1);
			}
		}
	}
	node->minmax += value;
	printf("Fives Detected\n");
}

void		h_run(t_node *node, char **strings, int x, int y)
{
	printf("Running Heuristics\n");
	h_pair(node, strings);
	h_quad(node, strings);
	h_five(node, strings);
	h_captures(node, strings, x, y);
	//run additional heuristic functions here
	printf("Heuristics Completed\n");
}

char		*gen_hor(t_node *node, int x, int y)
{
	char 	*string;
	int		i;
	int		ix;
	printf("Generting hor\n");
	i = -1;
	string = malloc(sizeof(char) * 10);
	ix = x - 4;
	if (ix < 0)
		while (ix < 0)
		{
			string[++i] = OFF;
			ix++;
		}
	printf("Off Board Padding Added\n");
	printf("IX = %i, I = %i\n", ix, i);
	while (ix < NTILES && ix <= x + 4 && printf("IX = %i, I = %i\n", ix, i))
		string[++i] = node->board[ix++][y];
	printf("Board Pieces Added\n");
	while (++i < 9)
		string[i] = OFF;
	string[++i] = '\0';
	return(string);
}

char		*gen_vert(t_node *node, int x, int y)
{
	char 	*string;
	int		i;
	int		iy;
	printf("Generting vert\n");
	i = -1;
	string = malloc(sizeof(char) * 10);
	iy = y - 4;
	if (iy < 0)
		while (iy < 0)
		{
			string[++i] = OFF;
			iy++;
		} 
	while (iy < NTILES && iy <= y + 4 && printf("IY = %i, I = %i\n", iy, i))
		string[++i] = node->board[x][iy++];
	while (++i < 9)
		string[i] = OFF;
	string[++i] = '\0';
	return(string);
}

char		*gen_yenx(t_node *node, int x, int y) //yenx: y equals neg x
{
	char 	*string;
	int		i;
	int		ix;
	int		iy;
	printf("Generting Yenx\n");
	string = malloc(sizeof(char) * 10);
	i = -1;
	ix = x - 4;
	iy = y - 4;
	if (iy < 0)
		while (iy < 0)
		{
			string[++i] = OFF;
			iy++;
		}
	if (ix < 0)
		while (ix < 0)
		{
			string[++i] = OFF;
			ix++;
		} 
	while (iy > -1 && ix < NTILES && ix <= x + 4 && printf("IX = %i, IY = %i, I = %i\n", ix, iy, i))
		string[++i] = node->board[ix++][iy--];
	while (++i < 9)
		string[i] = OFF;
	string[++i] = '\0';
	return(string);
}

char		*gen_yex(t_node *node, int x, int y) //yex: y equals x
{
	char 	*string;
	int		i;
	int		ix;
	int		iy;
	printf("Generting Yex\n");
	string = malloc(sizeof(char) * 10);
	i = -1;
	ix = x - 4;
	iy = y - 4;
	if (iy < 0)
		while (iy < 0)
		{
			string[++i] = OFF;
			iy++;
		} 
	if (ix < 0)
		while (ix < 0)
		{
			string[++i] = OFF;
			ix++;
		} 
	while (iy < NTILES && ix < NTILES && ix <= x + 4 && printf("IX = %i, IY = %i, I = %i\n", ix, iy, i))
		string[++i] = node->board[ix++][iy++];
	while (++i < 9)
		string[i] = OFF;
	string[++i] = '\0';
	return(string);
}

void		h_prep(t_node *node, int x, int y)
{
	char	**strings;
	int i;
	printf("Heuristic Preparation Initiated\n");
	strings = malloc(sizeof(char *) * 4);
	strings[I_VERT] = gen_vert(node, x, y);
	strings[I_HOR] = gen_hor(node, x, y);
	strings[I_YEX] = gen_yex(node, x, y);
	strings[I_YENX] = gen_yenx(node, x, y);
	h_run(node, strings, x, y);
	i = -1;
	while (++i < 4)
		free(strings[i]);
	free(strings);
	printf("Heuristic Preparation Completed\n");
}

void		heuristic(t_node *node)
{
	int		x;
	int		y;
	printf("Heuristic Initiated\n");
	y = -1;
	while (++y < NTILES)
	{
		x = -1;
		while (++x < NTILES)
			h_prep(node, x, y);
	}
	printf("Heuristic Completed\n");
}