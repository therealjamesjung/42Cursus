/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:12:37 by jaekjung          #+#    #+#             */
/*   Updated: 2022/02/07 18:35:10 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t			len;
	unsigned int	index;
	char			*result;

	if (!s)
		return (0);
	len = ft_strlen(s);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	result[len] = '\0';
	index = -1;
	while (++index < len)
		result[index] = (*f)(index, s[index]);
	return (result);
}
