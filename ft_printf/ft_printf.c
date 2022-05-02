/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:00:09 by jaekjung          #+#    #+#             */
/*   Updated: 2022/05/02 12:08:31 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int _parse(char format)
{
	if (format == 'c');
	else if (format == 's');
	else if (format == 'p');
	else if (format == 'd' || format == 'i');
	else if (format == 'u');
	else if (format == 'x' || format == 'X');
	else if (format == '%');
}

int ft_printf(const char *format, ...)
{
	va_list	ap;
	int		index;
	int		len;

	va_start(ap, format);
	index = -1;
	len = 0;
	while (++index)
	{
		if (!format[index])
			break;
		else if (format[index] == '%')
			len += _parse(format[index]); // Parse string
		else
			len += 1; // put c
	}
	va_end(ap);
	return (0);
}

int main()
{
	int	a = printf("asd\n");

	printf("%d", a);
	return (0);
}