/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:22:43 by jaekjung          #+#    #+#             */
/*   Updated: 2022/02/02 19:36:45 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	void	*tmp;

	if (!dest && !src)
		return (0);
	tmp = dest;
	while (n--)
	{
		*(unsigned char *)dest = *(unsigned char *)src;
		dest++;
		src++;
	}
	return (tmp);
}
