/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:52:02 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/09 18:01:29 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
