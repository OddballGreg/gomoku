#include "../includes/gomoku.h"

void	sig_handler(int signo)
{
	mvprintw(1, 1, "Signal recieved: %d", signo);//debug
}