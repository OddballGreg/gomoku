#include "../includes/gomoku.h"

void		getopts()
{
	char 	*input;

	input = NULL;
	ft_putendl("Select your gamemode:\n(1) Player vs Comp\n(2) Player vs Player");
	while (GAMEMODE == 0)
	{
		if (!get_next_line(0, &input))
			continue ;
		if (atoi(input) == 1)
			GAMEMODE = 1;
		else if (atoi(input) == 2)
			GAMEMODE = 2;
		else
			ft_putendl("Please select a valid option.");
	}
}