#include "apue.h"

/*
Interruption of system calls and library functions by signal handlers

If a signal handler is invoked while a system call or library function call is blocked, then either:
* the call is automatically restarted after the signal handler returns; or
* the call fails with the error EINTR.

in this case, read is interuppted by SIGALRM

*/
static void	sig_alrm(int);

int
main(void)
{
	int		n;
	char	line[MAXLINE];

	if (signal(SIGALRM, sig_alrm) == SIG_ERR)
		err_sys("signal(SIGALRM) error");

	alarm(10);
	if ((n = read(STDIN_FILENO, line, MAXLINE)) < 0)
		err_sys("read error");
	alarm(0);

	write(STDOUT_FILENO, line, n);
	exit(0);
}

static void
sig_alrm(int signo)
{
	/* nothing to do, just return to interrupt the read */
}
