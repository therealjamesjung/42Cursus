/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_x.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 17:01:06 by jaekjung          #+#    #+#             */
/*   Updated: 2022/05/07 15:46:13 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_x(va_list *ap, int mode)
{
	char				hex[9];
	unsigned int		ptr;
	int					index;
	int					len;

	ptr = va_arg(*ap, unsigned int);
	index = 8;
	len = 0;
	hex[8] = '\0';
	while (--index >= 0)
	{
		if (mode)
			hex[index] = "0123456789abcdef"[ptr % 16];
		else
			hex[index] = "0123456789ABCDEF"[ptr % 16];
		ptr /= 16;
		len++;
		if (!ptr)
			break;
	}
	if (index < 0)
		index = 0;
	return (write(1, hex + index, 8 - index)); 
}