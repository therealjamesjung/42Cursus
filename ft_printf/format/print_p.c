/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_p.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/06 16:27:24 by jaekjung          #+#    #+#             */
/*   Updated: 2022/05/07 16:02:40 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_p(va_list *ap)
{
	char				hex[17];
	unsigned long long 	ptr;
	int					index;
	int					len;

	ptr = va_arg(*ap, unsigned long long);
	index = 16;
	len = 0;
	hex[16] = '\0';
	while (--index >= 0)
	{
		hex[index] = "0123456789abcdef"[ptr % 16];
		ptr /= 16;
		len++;
		if (!ptr)
			break;
	}
	if (index < 0)
		index = 0;
	write(1, "0x", 2);
	return (write(1, hex + index, 16 - index) + 2); 
}