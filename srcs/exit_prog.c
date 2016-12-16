#include "../includes/gomoku.h"

void    exit_prog(void)
{
    endwin();
}

void    error_quit(char *message)
{
    ft_putstr("Error: ");
    ft_putendl((message) ? message : "An unlabeled error occured");
    exit_prog();
}
