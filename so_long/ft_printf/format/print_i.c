/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_i.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/02 17:03:10 by jaekjung          #+#    #+#             */
/*   Updated: 2022/05/07 16:16:42 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

int	print_i(va_list *ap)
{
	int		n;
	char	*s;

	n = va_arg(*ap, int);
	s = _itoa((long) n);
	if (!s)
		return (write(1, "(null)", 6));
	n = write(1, s, ft_strlen(s));
	free(s);
	s = NULL;
	return (n);
}

int	print_u(va_list *ap)
{
	unsigned int	n;
	char			*s;

	n = (unsigned int)va_arg(*ap, int);
	s = _itoa((long) n);
	if (!s)
		return (write(1, "(null)", 6));
	n = write(1, s, ft_strlen(s));
	free(s);
	s = NULL;
	return (n);
}
