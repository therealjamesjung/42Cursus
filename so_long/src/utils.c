/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 12:57:32 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/18 15:48:43 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	_validate_width(int map_width, char *tmp)
{
	int	len;

	len = (int) ft_strlen(tmp);
	if (tmp[len - 1] == '\n')
		len--;
	if (len != map_width)
		return (0);
	return (1);
}

t_point	_init_point(int x, int y)
{
	t_point	point;

	point.x = x;
	point.y = y;
	return (point);
}

void	_free_input(char *input, int fd)
{
	free(input);
	input = 0;
	close(fd);
}

int	_count_char(char *str, char c)
{
	size_t	index;
	int		cnt;

	cnt = 0;
	index = -1;
	while (++index < ft_strlen(str))
		if (str[index] == c)
			cnt++;
	return (cnt);
}

char	*_join(char *input, const char *tmp)
{
	size_t	index;
	size_t	len;
	char	*result;

	if (!input)
		return (ft_strdup(tmp));
	len = ft_strlen((char *)input) + ft_strlen((char *)tmp);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (0);
	index = -1;
	while (input[++index] != '\0')
		result[index] = input[index];
	while (*tmp != '\0')
		result[index++] = *tmp++;
	result[index] = '\0';
	free(input);
	input = 0;
	return (result);
}
