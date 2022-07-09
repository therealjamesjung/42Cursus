/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:25:37 by jaekjung          #+#    #+#             */
/*   Updated: 2022/02/02 19:36:26 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				index;

	index = -1;
	while (++index < n)
	{
		if (((unsigned char *)(s1))[index] != ((unsigned char *)(s2))[index])
			return (((unsigned char *)(s1))[index] - \
				((unsigned char *)(s2))[index]);
	}
	return (0);
}
