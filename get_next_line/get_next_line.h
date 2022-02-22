/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 14:52:08 by jaekjung          #+#    #+#             */
/*   Updated: 2022/02/22 15:39:54 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

#define BUFFER_SIZE 2

char    *get_next_line(int fd);
int     find_newline(char *s);
char    *realloc_line(char *s, int cnt);
void    _append(char *dest, char *src, int index);
char	*_strdup(const char *src);
char    *get_return_val(char *line, size_t buffer);
size_t	_strlen(const char *str);

#endif