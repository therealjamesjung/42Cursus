/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:52:08 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/09 18:01:37 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define BUFFER_SIZE 10

char	*get_next_line(int fd);
char	*get_return_val(char **line, size_t buffer);

size_t	ft_strlen(const char *str);
char	*ft_strdup(const char *src);
char	*ft_strjoin(const char *s1, const char *s2);

char	*_split(char **line, size_t index);
char	*_append(char **line, char *read_buffer);
char	*_strndup(const char *src, size_t len);
void	_clean(char *read_buffer, size_t index);
size_t	_find_newline(char *s);

#endif