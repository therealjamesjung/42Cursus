/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 20:00:53 by jaekjung          #+#    #+#             */
/*   Updated: 2022/05/07 16:14:18 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
size_t	ft_strlen(const char *str);
int		print_s(va_list *ap);
int		print_c(va_list *ap);
int		print_i(va_list *ap);
int		print_u(va_list *ap);
int		print_p(va_list *ap);
int		print_x(va_list *ap, int mode);
char	*_itoa(long n);

#endif