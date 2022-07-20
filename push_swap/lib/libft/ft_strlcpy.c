/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/13 16:18:29 by jaekjung          #+#    #+#             */
/*   Updated: 2022/02/05 14:46:46 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	index;
	size_t	src_len;

	index = 0;
	src_len = ft_strlen(src);
	if (!size)
		return (src_len);
	while (index < src_len && index < size - 1)
	{
		dst[index] = src[index];
		index++;
	}
	if (size > 0)
		dst[index] = '\0';
	return (src_len);
}
