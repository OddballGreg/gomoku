#include "../includes/gomoku.h"

int		ft_free(void **var)
{
	if (*var != NULL)
	{
		free(*var);
		*var = NULL;
		return (1);
	}
	return (0);
}
