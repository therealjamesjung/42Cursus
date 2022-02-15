/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 22:03:32 by jaekjung          #+#    #+#             */
/*   Updated: 2022/02/02 19:36:53 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (dest == src || n <= 0)
		return (dest);
	if (dest > src)
	{
		i = n;
		while (--i > 0)
			((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
		return (dest);
	}
	i = -1;
	while (++i < n)
		((unsigned char *)dest)[i] = ((const unsigned char *)src)[i];
	return (dest);
}
