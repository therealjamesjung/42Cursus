/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:12:41 by jaekjung          #+#    #+#             */
/*   Updated: 2022/06/25 19:20:43 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minitalk.h"

static void	init_sigaction();
static void	finish_and_wait(pid_t client_pid)
{
	write(1, "\n", 1);
	kill(client_pid, SIGUSR2);
	init_sigaction();
}

static void	confirm_and_print(int signo, siginfo_t *info, void *context)
{
	static int				bit_received;
	static unsigned char	res;
	static pid_t			client_pid;

	(void) signo;
	(void) context;
	if (!bit_received && !res)
		client_pid = info->si_pid;
	bit_received++;
	if (signo == SIGUSR1)
		res &= ~(1 << (8 - bit_received));
	if (signo == SIGUSR2)
		res |= 1 << (8 - bit_received);
	if (bit_received == 8)
	{
		bit_received = 0;
		if (!res)
		{
			finish_and_wait(client_pid);
			return ;
		}
		write(1, &res, 1);
	}
	kill(client_pid, SIGUSR1);
}

static void	connection(int signo, siginfo_t *info, void *context)
{
	struct sigaction	sigact;

	(void) signo;
	(void) context;
	ft_printf("Connection Success! ");
	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = confirm_and_print;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1
		|| sigaction(SIGUSR2, &sigact, NULL) == -1)
		{
			ft_printf("[Error] Sigaction failed");
			exit(1);
		}
	kill(info->si_pid, SIGUSR1);
}

static void	init_sigaction()
{
	struct sigaction	sigact;

	sigact.sa_flags = SA_SIGINFO;
	sigact.sa_sigaction = connection;
	if (sigaction(SIGUSR1, &sigact, NULL) == -1)
		ft_printf("[Error] Sigaction failed.");
}

int main()
{
    _pid(1);
	init_sigaction();
	while (1)
		pause();
    return (0);
}