#include "../includes/gomoku.h"

void	sig_handler(int signo)
{
//	static int k;//debug
//	mvprintw(++k, 1, "Signal recieved: %d", signo);//debug
	if (signo == 28)
		redraw_all_win();
	else if (signo == SIGKILL ||signo == SIGABRT || signo == SIGSTOP || signo == SIGQUIT)
		exit_prog();
}