/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:52:06 by jaekjung          #+#    #+#             */
/*   Updated: 2022/03/03 16:32:38 by jaekjung         ###   ########.fr       */
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
	if (!line)
	{ // Inital allocation
		index = 0;
		line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	}
	// printf("line: %s index: %d\n", line, index);
	while (1)
	{
		line = realloc_line(&line, index);
		// printf("reallocated line: %s\n", line);
		buffer = read(fd, read_buffer, BUFFER_SIZE);
		// printf("read: %s buffer: %d\n", read_buffer, buffer);
		_append(line, read_buffer, (int) buffer);
		// printf("copied line: %s\n", line);
		if (line[0] != -1 && (int) find_newline(line) == -1 && buffer == BUFFER_SIZE)
			index += BUFFER_SIZE;
		else
			break ;
	}
	result = get_return_val(&line); 
	return (result);
}


char    *get_return_val(char **line)
{
    char    *result;
    char    *tmp;
    int     index;

    // printf("val line: #%s# buf: %d\n", *line, buffer);
    if ((int) find_newline(*line) != -1)
    { // if line has a newline, return string until newline and save the remainder to line
        index = find_newline(*line);
        result = _strndup(*line, index);
        tmp = _strdup(*line + index + 1);
        (*line)[0] = -1;
		if (tmp[0] != '\0')
        	*line = _strdup(tmp);
        free(tmp);
		tmp = NULL;
        return (result);
    }
	else if ((*line)[0] == -1)
	{
		free(*line);
		(*line) = NULL;
		return (0);
	}
	else
	{
		result = _strdup(*line);
		(*line)[0] = -1;
		return (result);
	}
}