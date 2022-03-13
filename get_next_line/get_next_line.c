/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:52:06 by jaekjung          #+#    #+#             */
/*   Updated: 2022/03/13 18:44:46 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*_append(char **line, char *read_buffer)
{
	char	*result;

	result = ft_strjoin(*line, read_buffer);
	free(*line);
	*line = NULL;
	return (result);
}

char	*_split(char **line, size_t index)
{
	char	*return_val;
	char	*save_val;

	return_val = _strndup(*line, index);
	save_val = ft_strdup(*line + index + 1);
	free(*line);
	*line = NULL;
	*line = save_val;
	return (return_val);
}

char	*get_return_val(char **line, size_t buffer)
{
	char	*return_val;

	if ((int) buffer < 0)
		return (0);
	else if (*line && (int) _find_newline(*line) >= 0)
		return (_split(line, buffer));
	else if (*line)
	{
		if ((*line)[0] == '\0')
			return_val = NULL;
		else
			return_val = ft_strdup(*line);
		free(*line);
		*line = NULL;
		return (return_val);
	}
	else
		return (0);
}

void	_clean(char *read_buffer, size_t index)
{
	while (index <= BUFFER_SIZE)
		read_buffer[index++] = '\0';
}

char	*get_next_line(int fd)
{
	char		read_buffer[BUFFER_SIZE + 1];
	size_t		buffer;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	while (1)
	{
		if ((int) _find_newline(line) >= 0)
			return (_split(&line, (int) _find_newline(line)));
		buffer = read(fd, read_buffer, BUFFER_SIZE);
		if ((int) buffer <= 0)
			break ;
		_clean(read_buffer, buffer);
		line = _append(&line, read_buffer);
	}
	return (get_return_val(&line, buffer));
}
