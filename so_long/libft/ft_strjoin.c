/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 20:18:21 by jaekjung          #+#    #+#             */
/*   Updated: 2022/02/05 14:19:35 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	size_t	index;
	size_t	len;
	char	*result;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	index = 0;
	while (*s1 != '\0')
		result[index++] = *s1++;
	while (*s2 != '\0')
		result[index++] = *s2++;
	result[index] = '\0';
	return (result);
}
