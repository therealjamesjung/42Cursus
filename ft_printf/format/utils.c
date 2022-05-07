/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 16:08:17 by jaekjung          #+#    #+#             */
/*   Updated: 2022/05/07 15:58:59 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

static int	_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	_calc_len(long n)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		len++;
	while (n)
	{
		len++;
		n /= 10;
	}
	return (len);
}

char	*_itoa(long n)
{
	int		len;
	int		index;
	char	*result;

	len = _calc_len(n);
	result = (char *) malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = '\0';
	if (!n)
		result[0] = '0';
	else if (n < 0)
		result[0] = '-';
	index = len - 1;
	while (n)
	{
		result[index] = _abs(n % 10) + '0';
		n /= 10;
		index--;
	}
	return (result);
}
