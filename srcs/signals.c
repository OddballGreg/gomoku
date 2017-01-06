#include "../includes/gomoku.h"

void	sig_handler(int signo)
{
//	static int k;//debug
//	mvprintw(++k, 1, "Signal recieved: %d", signo);//debug
	if (SIG_R(SIGWINCH))
		redraw_all_win();
	else if (SIG_R(SIGTERM) || SIG_R(SIGQUIT) || SIG_R(SIGQUIT) || SIG_R(SIGINT))
		exit_prog();
	else if (SIG_R(SIGSEGV) || SIG_R(SIGABRT) || SIG_R(SIGBUS))
		exit_prog();
//	mvprintw(1, 1, "Signal recieved: %d", signo);//debug
//	update_panels();//debug
//	doupdate();//debug
}
