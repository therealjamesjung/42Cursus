/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:15:55 by jaekjung          #+#    #+#             */
/*   Updated: 2022/02/02 14:41:54 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*tmp;
	int		cnt;

	cnt = 0;
	tmp = lst;
	if (!lst)
		return (0);
	while (tmp)
	{
		cnt++;
		tmp = tmp->next;
	}
	return (cnt);
}
