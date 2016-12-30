#include "../includes/gomoku.h"

void    exit_prog(void)
{
    endwin();
    ft_putstr("Goodbye!\n");
    exit(0);
}

void    error_quit(char *message)
{
    ft_putstr("Error: ");
    ft_putendl((message) ? message : "An unlabeled error occured");
    exit_prog();
}
