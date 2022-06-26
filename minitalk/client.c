/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:12:47 by jaekjung          #+#    #+#             */
/*   Updated: 2022/06/25 19:20:37 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_info	g_info;

static int	get_bit(void)
{
	static int	str_index;
	static int	bit_sent;

	bit_sent++;
	if (bit_sent > 8)
	{
		str_index++;
		bit_sent = 1;
	}
	if (g_info.str[str_index])
		return (g_info.str[str_index] & (1 << (8 - bit_sent)));
	return (0);
}

static void	send_signal(int signo)
{
	int	bit;

	bit = get_bit();
	if (signo == SIGUSR2)
		exit(0);
	else if (signo == SIGUSR1)
	{
		if (!bit)
			kill(g_info.server_pid, SIGUSR1);
		else
			kill(g_info.server_pid, SIGUSR2);
	}
}

static void	check_connection(int signo)
{
	int	bit;

	(void)signo;
    ft_printf("Connection Success! ");
	if (signal(SIGUSR1, send_signal) == SIG_ERR
		|| signal(SIGUSR2, send_signal) == SIG_ERR)
        {
            ft_printf("[Error] Sigaction failed");
            exit(1);
        }
	bit = get_bit();
	if (!bit)
		kill(g_info.server_pid, SIGUSR1);
	else
		kill(g_info.server_pid, SIGUSR2);
}

static void	init_signal(void)
{
	if (signal(SIGUSR1, check_connection) == SIG_ERR)
		{
            ft_printf("[Error] Sigaction failed.");
            exit(1);
        }
	if (kill(g_info.server_pid, SIGUSR1) == -1)
		{
            ft_printf("[Error] Sigaction failed.");
            exit(1);
        }
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		ft_printf("[Error] Wrong parameters.");
	g_info.str = (unsigned char *)argv[2];
	g_info.server_pid = ft_atoi(argv[1]);
	_pid(0);
	init_signal();
	while (1)
		pause();
}