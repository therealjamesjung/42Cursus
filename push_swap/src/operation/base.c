/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   base.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:35:55 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/21 19:57:38 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	_push(t_stack *stack, t_node *node)
{
	if (!node)
		return ;
	node->next = stack->head;
	node->prev = NULL;
	if (!stack->len)
		stack->tail = node;
	else
		stack->head->prev = node;
	stack->head = node;
	stack->len++;
}

t_node	*_pop(t_stack *stack)
{
	t_node	*node;
	
	if (!stack->len)
		return (NULL);
	node = stack->head;
	if (stack->tail == node)
		stack->tail = NULL;
	stack->head = node->next;
	if (node->next)
		node->next->prev = NULL;
	node->next = NULL;
	node->prev = NULL;
	stack->len--;
	return (node);
}
