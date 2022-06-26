/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:12:47 by jaekjung          #+#    #+#             */
/*   Updated: 2022/06/25 19:12:01 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void    _pid(int is_server)
{
    if (is_server)
        ft_printf("Server PID: %d", (int) getpid());
    else
        ft_printf("Client PID: %d", (int) getpid());
    write(1, "\n", 1);
}


static int	check_space(const char *str)
{
	int	index;

	index = 0;
	while (str[index] == ' ' || (str[index] >= 9 && str[index] <= 13))
		index++;
	return (index);
}

int	ft_atoi(const char *str)
{
	unsigned long long	result;
	int					is_positive;
	int					index;

	index = check_space(str);
	is_positive = 1;
	if (str[index] == '-')
		is_positive = -1;
	if (str[index] == '-' || str[index] == '+')
		index++;
	result = 0;
	while (str[index] >= '0' && str[index] <= '9')
		result = result * 10 + str[index++] - '0';
	if (result > 9223372036854775807 && is_positive == 1)
		return (-1);
	else if (result > 9223372036854775808ULL && is_positive == -1)
		return (0);
	return ((int)result * is_positive);
}
