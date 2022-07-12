/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 16:21:20 by jaekjung          #+#    #+#             */
/*   Updated: 2022/02/02 14:43:20 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	_calc_len(int n)
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

char	*ft_itoa(int n)
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
