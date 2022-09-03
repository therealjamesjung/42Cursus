/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/03 00:34:34 by jaekjung          #+#    #+#             */
/*   Updated: 2022/08/03 11:38:01 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	_atoi(const char *str)
{
	long long	result;
	int			is_positive;

	is_positive = 1;
	result = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_positive = -1;
		str++;
	}
	while (*str != 0 && '0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
		if (result - 1 > INT_MAX || \
			(is_positive > 0 && result > INT_MAX))
			_parse_error();
	}
	return ((int) result * is_positive);
}

void	_is_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			_parse_error();
		if ((str[i] == '+' || str[i] == '-') && i != 0)
			_parse_error();
		if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i + 1]))
			_parse_error();
	}
}

int	_sum(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}
