#include "../includes/gomoku.h"

void		h_pair(t_node *node, char **strings)
{
	int		value;
	int		i;
	char	piece;

	value = 0;
	i = -1;
	piece = strings[I_VERT][4];
	while (++i < 4)
	{
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
}


void		h_run(t_node *node, char **strings)
{
	h_pair(node, strings);
	//run additional heuristic functions here
}

char		*gen_vert(t_node *node, int x, int y)
{
	char 	*string;
	int		i;
	int		ix;

	i = -1;
		string = malloc(sizeof(char) * 10);
	ix = x - 4;
	if (ix < 0)
		while (ix < 0)
		{
			string[++i] = OFF;
			ix++;
		} 
	while (ix < NTILES && ix <= x + 4)
		string[++i] = node->board[ix][y];
	while (i < 9)
		string[i] = OFF;
	string[++i] = '\0';
	return(string);
}

char		*gen_hor(t_node *node, int x, int y)
{
	char 	*string;
	int		i;
	int		iy;

	i = -1;
		string = malloc(sizeof(char) * 10);
	iy = y - 4;
	if (iy < 0)
		while (iy < 0)
		{
			string[++i] = OFF;
			iy++;
		} 
	while (iy < NTILES && iy <= x + 4)
		string[++i] = node->board[x][iy];
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
	while (iy < NTILES && ix < NTILES && ix <= x + 4)
		string[++i] = node->board[ix][iy];
	while (++i < 9)
		string[i] = OFF;
	string[++i] = '\0';
	return(string);
}

char		*gen_yenx(t_node *node, int x, int y) //yenx: y equals negative x
{
	char 	*string;
	int		i;
	int		ix;
	int		iy;

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
	while (iy < NTILES && ix < NTILES && ix <= x + 4)
		string[++i] = node->board[ix][iy];
	while (++i < 9)
		string[i] = OFF;
	string[++i] = '\0';
	return(string);
}

void		h_prep(t_node *node, int x, int y)
{
	char	**strings;
	int i;
	
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
}

void		heuristic(t_node *node)
{
	int		x;
	int		y;

	y = -1;
	while (++y < NTILES)
	{
		x = -1;
		while (++x < NTILES)
			h_prep(node, x, y);
	}
}