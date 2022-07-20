/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 22:15:31 by jaekjung          #+#    #+#             */
/*   Updated: 2022/02/07 17:29:38 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, const char *set)
{
	int	index;

	index = 0;
	while (set[index] != '\0')
	{
		if (set[index] == c)
			return (1);
		index++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	size_t	start;
	size_t	end;
	size_t	index;
	char	*result;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	index = 0;
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_set(s1[start], set))
		start++;
	while (end > start && is_set(s1[end - 1], set))
		end--;
	result = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!result)
		return (0);
	while (start < end)
		result[index++] = s1[start++];
	result[index] = '\0';
	return (result);
}
