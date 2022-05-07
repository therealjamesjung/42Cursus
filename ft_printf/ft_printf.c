/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:00:09 by jaekjung          #+#    #+#             */
/*   Updated: 2022/05/07 15:05:48 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int _parse(const char format, va_list *ap)
{
	if (format == 'c')
		return (print_c(ap));
	else if (format == 's')
		return (print_s(ap));
	else if (format == 'd' || format == 'i')
		return (print_i(ap));
	else if (format == 'u')
		return (print_u(ap));
	else if (format == '%')
		return (write(1, "%", 1));
	else if (format == 'p')
		return (print_p(ap));
	else if (format == 'x' || format == 'X')
		return (print_x(ap, format == 'x'));
	return (0);
	
}

int ft_printf(const char *format, ...)
{
	va_list	ap;
	int		index;
	int		len;

	va_start(ap, format);
	index = -1;
	len = 0;
	while (format[++index])
	{
		if (format[index] == '%')
			len += _parse(format[++index], &ap);
		else
			len += write(1, &format[index], 1);
	}
	va_end(ap);
	return (len);
}