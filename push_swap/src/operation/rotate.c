/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:36:49 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/21 19:59:44 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	_rotate(t_stack *stack, char *msg)
{
	t_node	*tmp;

	if (stack->len < 2)
		return ;
	if (msg)
		ft_printf("%s\n", msg);
	tmp = stack->head;
	stack->head = tmp->next;
	tmp->next->prev = NULL;
	stack->tail->next = tmp;
	tmp->prev = stack->tail;
	stack->tail = tmp;
	tmp->next = NULL;
}

void	_rev_rotate(t_stack *stack, char *msg)
{
	t_node	*tmp;

	if (stack->len < 2)
		return ;
	if (msg)
		ft_printf("%s\n", msg);
	tmp = stack->tail;
	stack->tail = tmp->prev;
	stack->tail->next = NULL;
	stack->head->prev = tmp;
	tmp->next = stack->head;
	tmp->prev = NULL;
	stack->head = tmp;
}

void	_rr(t_stack *stack_a, t_stack *stack_b)
{
	_rotate(stack_a, NULL);
	_rotate(stack_b, NULL);
	ft_printf("rr\n");
}

void	_rrr(t_stack *stack_a, t_stack *stack_b)
{
	_rev_rotate(stack_a, NULL);
	_rev_rotate(stack_b, NULL);
	ft_printf("rrr\n");
}