#include "../includes/gomoku.h"

void		copy_map(char source[15][15], char dest[15][15])
{
	int		x;
	int		y;

	x = -1;
	while(++x < 15)
	{
		y = -1;
		while (++y < 15)
			dest[x][y] = source[x][y];
	}
}

void		place_piece(t_node *node, t_coord piece_played)
{
	if (piece_played.x != -1 && piece_played.y != -1)
	{
		if (node->depth % 2 == 1)
			node->board[piece_played.x][piece_played.y] = BLACK;
		else
			node->board[piece_played.x][piece_played.y] = WHITE;
	}
}

t_node		make_node(int parentid, t_coord piece_played)
{
	t_node	new;
	char	save;
	int		c;

	save = 1;
	new.parentid = parentid;
	c = -1;
	while (++c < 255)
		new.child[c] = -1;
	if (parentid != -1)
	{
		copy_map(AI.nodes[parentid].board, new.board);
		new.depth = AI.nodes[parentid].depth + 1;
	}
	else
	{
		copy_map(GAME.board, new.board);
		new.depth = 0;
	}
	place_piece(&new, piece_played);

	heuristic(&new);
	c = -1;
	if (parentid != -1) //Has parent
	{
		while (++c < 255 && AI.nodes[parentid].child[c] != -1 && save == 1) //Cycle parent children
			if (AI.nodes[AI.nodes[parentid].child[c]].minmax > new.minmax) //Alpha Beta Pruning
				save = 0;
		if (save == 1) //If unpruned, save child to parent
		{
			printf("\nNot Pruned"); // DEBUG
			AI.nodes[parentid].child[c] = AI.id_count;
			AI.nodes[parentid].branchweight += new.minmax;
			AI.nodes[AI.id_count] = new;
			AI.id_count++;
		}
		else // DEBUG
			printf("\nPruned");
	}
	else
	{
		AI.nodes[AI.id_count] = new;
		AI.id_count++;
	}

	//Debug: Prints the node infor;
	int x;
	int y;
	printf("\nID: %i\tPID: %i\tDEPTH: %i\tMM: %i\tBW: %i\n", AI.id_count, new.parentid,  new.depth, new.minmax, new.branchweight);
	ft_putendl("Board:");
	x = -1;
	while(++x < 15)
	{
		y = -1;
		while(++y < 15)
			ft_putnbr(new.board[x][y]);
		ft_putendl("");
	}
	//End Debug 

	return (new);
}