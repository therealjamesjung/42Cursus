/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:46:12 by jaekjung          #+#    #+#             */
/*   Updated: 2021/11/08 16:58:52 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	index;

	index = -1;
	while (src[++index] != '\0')
		dest[index] = src[index];
	dest[index] = '\0';
	return (dest);
}

long long	_calc_length(int size, char **strs, int sep_len)
{
	int			index;
	long long	res_length;

	index = -1;
	res_length = 0;
	while (++index < size)
	{
		res_length += ft_strlen(strs[index]);
		res_length += sep_len;
	}
	return (res_length - sep_len + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	long long	result_len;
	long long	index;
	char		*result;
	char		*tmp;

	if (!size)
		return ((char *)malloc(sizeof(char)));
	result_len = _calc_length(size, strs, ft_strlen(sep));
	result = (char *)malloc(sizeof(char) * result_len);
	tmp = result;
	index = -1;
	while (++index < size)
	{
		ft_strcpy(tmp, strs[index]);
		tmp += ft_strlen(strs[index]);
		if (index < size - 1)
		{
			ft_strcpy(tmp, sep);
			tmp += ft_strlen(sep);
		}
	}
	*tmp = '\0';
	return (result);
}
