/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/18 12:13:24 by jaekjung          #+#    #+#             */
/*   Updated: 2022/02/07 17:57:37 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_len;
	size_t	dst_len;
	size_t	index;

	src_len = ft_strlen(src);
	dst_len = ft_strlen(dst);
	index = 0;
	while (index < size && *dst != '\0')
	{
		dst++;
		index++;
	}
	if (index == size)
		return (src_len + size);
	while (index < size - 1 && *src != '\0')
	{
		*dst++ = *src++;
		index++;
	}
	*dst = '\0';
	return (dst_len + src_len);
}
