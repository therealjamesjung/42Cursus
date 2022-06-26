/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:12:41 by jaekjung          #+#    #+#             */
/*   Updated: 2022/06/26 18:14:58 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_msg(int pid, char *str)
{
	int	index;
	int	bit;
	int	tmp;

	index = -1;
	while (++index < (int) ft_strlen(str))
	{
		bit = -1;
		while (++bit < 8)
		{
			tmp = str[index] >> (7 - bit) & 1;
			if (tmp == 0)
				kill(pid, SIGUSR1);
			else if (tmp == 1)
				kill(pid, SIGUSR2);
			usleep(30);
		}
		usleep(300);
	}
}

int	main(int argc, char **argv)
{
	pid_t	pid;
	char	*message;

	if (argc != 3)
	{
		ft_printf("Wrong number of arguments\n");
		exit(1);
	}
	pid = ft_atoi(argv[1]);
	if (pid < 100 || pid > 99998)
	{
		ft_printf("Invalid PID\n");
		exit(1);
	}
	message = ft_strjoin(argv[2], "\n");
	if (!message)
		exit(1);
	send_msg(pid, message);
	free(message);
	return (0);
}
