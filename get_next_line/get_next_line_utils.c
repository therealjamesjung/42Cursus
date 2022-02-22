/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:52:02 by jaekjung          #+#    #+#             */
/*   Updated: 2022/02/22 16:58:21 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	_strlen(const char *str)
{
	size_t	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}


int find_newline(char *s)
{ // Finds the  first index of new line in given string. returns -1 if no occurences
    int index;
    if (!s)
        return (-1);
    index = -1;
    while (s[++index] != '\0')
        if (s[index] == '\n')
            return (index);
    return (-1);
}

char    *realloc_line(char *s, int cnt)
{
    char    *new_line;
    int     index;

    if (!s)
        return (0);
    new_line = malloc(sizeof(char) * (BUFFER_SIZE + cnt + 1));
    if (!new_line)
        return (0);
    index = -1;
    while (s[++index] != '\0')
        new_line[index] = s[index];
    free(s);
    s = NULL;
    return (new_line);
}

void    _append(char *dest, char *src, int index)
{
    int i;
    int len;

    if (!index)
        return ;
    len = 0;
    while (dest[len] != '\0')
        len++;
    i = 0;
    while (index > i)
        dest[len++] = src[i++];
    dest[len] = '\0';
}

char	*_strdup(const char *src)
{
	char	*dest;
	size_t	len;
	size_t	index;

    if (!src || src[0] == -1)
        return (0);
	len = _strlen(src);
	dest = (char *)malloc(sizeof(char) * (len + 1));
	if (!dest)
		return (0);
	index = -1;
	while (++index <= len)
		dest[index] = src[index];
	return (dest);
}
