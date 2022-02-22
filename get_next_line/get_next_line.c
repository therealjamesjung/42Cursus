/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:52:06 by jaekjung          #+#    #+#             */
/*   Updated: 2022/02/22 17:15:52 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
	char			read_buffer[BUFFER_SIZE];
	char *result;
	static char		*line;
	static int		index;
	size_t			buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	printf("line: %s index: %d\n", line, index);
	if (!line)
	{
		index = 0;
		line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	}
	printf("line: %s index: %d\n", line, index);
	while (1)
	{
		line = realloc_line(line, index);
		// printf("realloced line: %s\n", line);
		buffer = read(fd, read_buffer, BUFFER_SIZE);
		// printf("read: %s buffer: %d\n", read_buffer, buffer);
		_append(line, read_buffer, (int) buffer);
		// printf("copied line: %s\n", line);
		if (line[0] != -1 && find_newline(line) == -1 && buffer == BUFFER_SIZE)
			index += BUFFER_SIZE;
		else
			break ;
	}
	result = get_return_val(line, buffer); 
	printf("@@@@@@@ %s\n", result);
	return (result);
}


char    *get_return_val(char *line, size_t buffer)
{
    char    *result;
    char    *tmp;
    int     index;

    // printf("val line: %s buf: %d\n", line, buffer);
    if (find_newline(line) != -1)
    { // if line has a newline, return string before newline and save the remainder to line
        index = find_newline(line);
        line[index] = '\0';
        result = _strdup(line);
        tmp = _strdup(line + index + 1);
        line[0] = -1;
		printf("WTF %s\n", line);
		if (tmp[0] != '\0')
		{
			printf("HEY\n");
        	line = _strdup(tmp);
		}
		printf("Why not this? %s\n", line);
        free(tmp);
		tmp = NULL;
		printf("Why not this? %s\n", line);
        return (result);
    }
	else if (line[0] == -1)
	{
		free(line);
		return (0);
	}
	else
	{
		printf("asd\n");
		result = _strdup(line);
		line[0] = -1;
		return (result);
	}
}