/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 13:46:57 by jaekjung          #+#    #+#             */
/*   Updated: 2022/02/09 15:31:26 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	_word_count(char *str, size_t length)
{
	size_t	index;
	int		cnt;
	int		flag;

	index = -1;
	cnt = 0;
	flag = (str[0] != '\0');
	while (++index < length)
	{
		if (str[index] == '\0')
			flag = 1;
		else
		{
			if (flag == 1)
				cnt++;
			flag = 0;
		}
	}
	return (cnt);
}

char	*_init_str(const char *str, char c, int length)
{
	int		i;
	char	*new_str;

	new_str = ft_strdup(str);
	if (!new_str)
		return (0);
	i = -1;
	while (++i < length)
	{
		if (new_str[i] == c)
			new_str[i] = '\0';
	}
	return (new_str);
}

void	_free_all(char **result, int index)
{
	int	i;

	i = -1;
	while (++i < index)
		free(result[i]);
	free(result);
	result = NULL;
}

void	_get_result(char **result, char *_removed, size_t len)
{
	size_t	i;
	size_t	index;

	i = 0;
	index = 0;
	while (i < len)
	{
		if (_removed[i] == '\0' || !ft_strlen(_removed + i))
		{
			i++;
			continue ;
		}
		result[index] = ft_strdup(_removed + i);
		if (!result[index])
			return (_free_all(result, index));
		index++;
		i += ft_strlen(_removed + i);
	}
	result[index] = NULL;
}

char	**ft_split(const char *str, char c)
{
	char	*_removed;
	char	**result;

	if (!str)
		return (0);
	_removed = _init_str(str, c, ft_strlen(str));
	if (!_removed)
		return (0);
	result = (char **)malloc(sizeof(char *) * \
		(_word_count(_removed, ft_strlen(str)) + 1));
	if (!result)
		return (0);
	_get_result(result, _removed, ft_strlen(str));
	free(_removed);
	_removed = NULL;
	return (result);
}
