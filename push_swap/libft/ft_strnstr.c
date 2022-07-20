/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 23:20:14 by jaekjung          #+#    #+#             */
/*   Updated: 2022/02/05 15:14:58 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	index;
	size_t	find_index;

	index = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[index] != '\0' && index < len)
	{
		find_index = 0;
		while (haystack[index + find_index] == needle[find_index] && \
				haystack[index + find_index] != '\0' && \
				index + find_index < len)
		{
			if (needle[find_index + 1] == '\0')
				return ((char *)&haystack[index]);
			find_index++;
		}
		index++;
	}
	return (0);
}
