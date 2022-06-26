/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:12:41 by jaekjung          #+#    #+#             */
/*   Updated: 2022/06/26 18:21:23 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	sig_handler(int sig)
{
	static char	tmp;
	static int	bit;

	if (sig == SIGUSR1)
		tmp |= 0;
	else if (sig == SIGUSR2)
		tmp |= 1;
	if (bit < 7)
		tmp <<= 1;
	bit++;
	if (bit == 8)
	{
		ft_printf("%c", tmp);
		bit = 0;
		tmp = 0;
	}
}

int	main(void)
{
	ft_printf("Server's PID is: %d\n", getpid());
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
	return (0);
}
