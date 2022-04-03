/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:52:02 by jaekjung          #+#    #+#             */
/*   Updated: 2022/04/03 15:25:18 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	size_t	len;
	size_t	index;

	len = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	index = -1;
	while (++index <= len)
		dest[index] = src[index];
	return (dest);
}

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

char	*_strndup(const char *src, size_t len)
{
	char	*dest;
	size_t	index;

	if (len < 0)
		return (0);
	dest = (char *)malloc(sizeof(char) * (len + 2));
	if (!dest)
		return (0);
	index = -1;
	while (++index <= len)
		dest[index] = src[index];
	dest[index] = '\0';
	return (dest);
}

size_t	_find_newline(char *s)
{
	size_t	index;

	if (!s)
		return (-1);
	index = -1;
	while (s[++index] != '\0')
		if (s[index] == '\n')
			return (index);
	return (-1);
}
