/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:00:45 by jaekjung          #+#    #+#             */
/*   Updated: 2022/08/03 00:42:14 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*_create_node(int n)
{
	t_node	*new_node;

	new_node = (t_node *)malloc(sizeof(t_node));
	new_node->next = NULL;
	new_node->prev = NULL;
	new_node->data = n;
	return (new_node);
}

t_stack	*_init_stack(void)
{
	t_stack	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->head = NULL;
	stack->tail = NULL;
	stack->len = 0;
	stack->min = INT_MAX;
	stack->max = INT_MIN;
	return (stack);
}

void	_free_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*to_free;

	tmp = stack->head;
	while (tmp)
	{
		to_free = tmp;
		free(to_free);
		to_free = 0;
		tmp = tmp->next;
	}
	free(stack);
}

void	_set_min_max(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp)
	{
		if (tmp->data < stack->min)
			stack->min = tmp->data;
		if (tmp->data > stack->max)
			stack->max = tmp->data;
		tmp = tmp->next;
	}
}
