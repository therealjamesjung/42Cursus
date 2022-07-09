/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:43:25 by jaekjung          #+#    #+#             */
/*   Updated: 2022/02/02 19:48:59 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		a[10];
	int			index;

	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else if (n == 2147483647)
		write(fd, "2147483647", 10);
	else if (n == 0)
		write(fd, "0", 1);
	else if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (n == -2147483648 || n == 2147483647 || n == 0)
		return ;
	index = 9;
	while (n)
	{
		a[index--] = n % 10 + '0';
		n /= 10;
	}
	while (++index <= 9)
		write(fd, &a[index], 1);
}
