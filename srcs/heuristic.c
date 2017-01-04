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
				value += 2;
			if (strings[i][5] == piece)
				value += 2;
		}
		else if (piece == WHITE)
		{
			if (strings[i][3] == piece)
				value -= 2;
			if (strings[i][5] == piece)
				value -= 2;
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
				value += 4;
			if (strings[i][5] == piece && strings[i][6] == piece && strings[i][7] == piece)
				value += 4;
		}
		else if (piece == WHITE)
		{
			if (strings[i][3] == piece && strings[i][2] == piece && strings[i][1] == piece)
				value -= 4;
			if (strings[i][5] == piece && strings[i][6] == piece && strings[i][7] == piece)
				value -= 4;
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
				value += 10;
				node->gameover = WIN;
			}
			if (strings[i][5] == piece && strings[i][6] == piece && strings[i][7] == piece && strings[i][8] == piece)
			{
				node->gameover = WIN;
				value += 10;
			}
		}
		else if (piece == WHITE)
		{
			if (strings[i][3] == piece && strings[i][2] == piece && strings[i][1] == piece && strings[i][0] == piece)
			{
				node->gameover = LOSE;
				value -= 10;
			}
			if (strings[i][5] == piece && strings[i][6] == piece && strings[i][7] == piece && strings[i][8] == piece)
			{
				node->gameover = LOSE;
				value -= 10;
			}
		}
	}
	node->minmax += value;
	printf("Fives Detected\n");
}

void		h_run(t_node *node, char **strings)
{
	printf("Running Heuristics\n");
	h_pair(node, strings);
	h_quad(node, strings);
	//run additional heuristic functions here
	printf("Heuristics Completed\n");
}

char		*gen_vert(t_node *node, int x, int y)
{
	char 	*string;
	int		i;
	int		ix;
	printf("Generting Vert\n");
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

char		*gen_hor(t_node *node, int x, int y)
{
	char 	*string;
	int		i;
	int		iy;
	printf("Generting Hor\n");
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
	h_run(node, strings);
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