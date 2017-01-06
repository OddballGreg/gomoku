#include "../includes/gomoku.h"

void		copy_map(char source[NTILES][NTILES], char dest[NTILES][NTILES])
{
	int			x;
	int			y;

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
	t_node		new;
	char		save;
	int			c;
	int			i;

	save = 1;
	new.parentid = parentid;
	c = -1;
	while (++c < 255)
		new.child[c] = -1; //Initializing children to -1;
	if (parentid != -1)
	{
		copy_map(AI.nodes[parentid].board, new.board); //copy board from parent
		new.depth = AI.nodes[parentid].depth + 1;
		place_piece(&new, piece_played); //Place nodes new piece on board from parent
	}
	else
	{
		copy_map(GAME.board, new.board); //copy board from game
		new.depth = 1;
	}

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
			i = 0;
			while (i < NODE_MAX && AI.nodes[i].depth != 0) //Find empty node in nodes list
				i++;
			if (i < NODE_MAX) //Prevent assigning more nodes than we can handle.
				AI.nodes[i] = new; //Assign node to list
		}
		else // DEBUG
			printf("\nPruned");
	}
	else
		AI.nodes[0] = new;

	//Debug: Prints the node information;
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

void			gen_children(int i)
{
	t_coord		place;

	place.x = AI.lxb - 1;
	while (++place.x < AI.uxb)
	{
		place.y = AI.lyb;
		while (++place.y < AI.uyb)
			make_node(i, place);
	}
}

t_coord			prompt_ai(t_coord op_move)
{
	time_t		now;
	int			i;
	int			j;
	t_coord		new;
	t_node		*temp;


	//start timer
	now = clock(0) / CLOCKS_PER_SEC; 
	// find/generate node related to opponent move
	i = -1;
	while (i < NODE_MAX && AI.nodes[i].piece_played.x != op_move.x && AI.nodes[i].piece_played.y != op_move.y)
		i++;
	j = i;
	if (i == NODE_MAX)
	{
		ft_bzero(AI.nodes, NODE_MAX);
		j = 0;
		make_node(-1, new);
	}
	// begin checking potential moves according to boundaries, check timer against current time with each node if 0.45 seconds elapse, return best move
	while (j < NODE_MAX && (now - clock(0)) / CLOCKS_PER_SEC < 0.475 )
		gen_children(j++);
	// return best move
	j = -1;
	temp = &AI.nodes[AI.nodes[i].child[0]];
	while (AI.nodes[i].child[++j] != -1)
	{
		if (temp.minmax < AI.nodes[AI.nodes[i].child[j]].minmax)
		temp = &AI.nodes[AI.nodes[i].child[j]];
	}
	return (temp.piece_played);

}