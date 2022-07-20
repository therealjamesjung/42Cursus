/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 16:44:21 by jaekjung          #+#    #+#             */
/*   Updated: 2022/02/07 17:30:05 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	while (n > 0)
	{
		if ((unsigned char)c == *(const unsigned char *)s)
			return ((void *)s);
		s++;
		n--;
	}
	return (0);
}
