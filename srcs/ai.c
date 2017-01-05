#include "../includes/gomoku.h"

void		copy_map(char source[NTILES][NTILES], char dest[NTILES][NTILES])
{
	int		x;
	int		y;

	x = -1;
	while(++x < NTILES)
	{
		y = -1;
		while (++y < NTILES)
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
		new.child[c] = -1; //Initializing children to -1;
	if (parentid != -1)
	{
		copy_map(AI.nodes[parentid].board, new.board); //copy board from parent
		new.depth = AI.nodes[parentid].depth + 1;
	}
	else
	{
		copy_map(GAME.board, new.board); //copy board from game
		new.depth = 0;
	}
	place_piece(&new, piece_played); //Place nodes new piece on board from parent

	heuristic(&new); //Generate heuristic value of nodes board state
	c = -1;
	if (parentid != -1) //Has parent
	{
		while (++c < 255 && AI.nodes[parentid].child[c] != -1 && save == 1) //Cycle parent children
			if (AI.nodes[AI.nodes[parentid].child[c]].minmax > new.minmax) //Alpha Beta Pruning
				save = 0;
		if (save == 1) //If unpruned, save child to parent
		{
			printf("\nNot Pruned"); // DEBUG
			AI.nodes[parentid].child[c] = AI.id_count; //Give offset to parent
			AI.nodes[parentid].branchweight += new.minmax; //Add to parents branchweight from own minmax NB: Currently only passes weight up to immediate parent
			AI.nodes[AI.id_count] = new; //DETERMINE EMPTY SPACE, Insert self rather than use id_count
			AI.id_count++;
		}
		else // DEBUG
			printf("\nPruned");
	}
	else
	{
		AI.nodes[AI.id_count] = new; //DETERMINE EMPTY SPACE, Insert self rather than use id_count
		AI.id_count++;
	}

	//Debug: Prints the node infor;
	int x;
	int y;
	printf("\nID: %i\tPID: %i\tDEPTH: %i\tMM: %i\tBW: %i\n", AI.id_count, new.parentid,  new.depth, new.minmax, new.branchweight);
	ft_putendl("Board:");
	x = -1;
	while(++x < NTILES)
	{
		y = -1;
		while(++y < NTILES)
			ft_putnbr(new.board[x][y]);
		ft_putendl("");
	}
	//End Debug 

	return (new);
}