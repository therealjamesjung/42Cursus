/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:52:06 by jaekjung          #+#    #+#             */
/*   Updated: 2022/03/10 16:21:05 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char    *get_next_line(int fd)
{
	char		read_buffer[BUFFER_SIZE];
	char 		*result;
	static char	*line;
	static int	index;
	size_t		buffer;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	if (!line)
	{ // Inital allocation
		index = 0;
		line = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	}
	printf("line: %s index: %d\n", line, index);
	while (1)
	{
		line = realloc_line(&line, index);
		buffer = read(fd, read_buffer, BUFFER_SIZE);
		_append(line, read_buffer, (int) buffer);
		index += (int) buffer;
		if (!line || (int) find_newline(line) != -1 || buffer != BUFFER_SIZE)
			break ;
	}
	result = get_return_val(&line); 
	return (result);
}


char    *get_return_val(char **line)
{
    char	*result;
    char	*tmp;
    size_t	index;

	if (!(*line))
		return (0);
    else if ((int) find_newline(*line) != -1)
    { // if line has a newline, return string until newline and save the remainder to line
        index = find_newline(*line);
        result = _strndup(*line, index);
        tmp = _strndup(*line + index + 1, _strlen(*line + index + 1));
        (*line)[0] = -1;
		if (tmp[0] != '\0')
        	*line = _strndup(tmp, _strlen(tmp));
        free(tmp);
		tmp = NULL;
        return (result);
    }
	else if ((*line)[0] == -1)
	{ // if line ended with new line on previous call
		free(*line);
		(*line) = NULL;
		return (0);
	}
	else
	{ // if line is read smaller than given BUFFER_SIZE
		result = _strndup(*line, _strlen(*line));
		(*line)[0] = -1;
		return (result);
	}
}