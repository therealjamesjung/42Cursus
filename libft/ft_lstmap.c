/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 23:46:32 by jaekjung          #+#    #+#             */
/*   Updated: 2022/02/02 14:30:03 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*append;

	if (!lst)
		return (0);
	result = 0;
	while (lst)
	{
		append = ft_lstnew((*f)(lst->content));
		if (!append)
		{
			ft_lstclear(&result, del);
			return (0);
		}
		ft_lstadd_back(&result, append);
		lst = lst->next;
	}
	return (result);
}
