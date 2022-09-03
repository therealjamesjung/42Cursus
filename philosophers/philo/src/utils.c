/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:44:34 by jaekjung          #+#    #+#             */
/*   Updated: 2022/09/03 16:14:08 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

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

long long	_gettime(void)
{
	struct timeval  time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void _usleep(long long time)
{
    long long finish_time;

    finish_time = time + _gettime();
    while (finish_time > (long long) _gettime())
        usleep(100);
}
