/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 22:56:02 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/25 23:40:21 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	_sum(int a, int b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	return (a + b);
}

void	_sort_three(t_stack *stack)
{
	int	head;
	int	middle;
	int	tail;

	head = stack->head->data;
	middle = stack->head->next->data;
	tail = stack->tail->data;
	if (head > middle && middle > tail && head > tail)
	{
		_swap(stack, "sa");
		_rev_rotate(stack, "rra");
	}
	else if (head > middle && tail > middle && head > tail)
		_rotate(stack, "ra");
	else if (middle > head && middle > tail && tail > head)
	{
		_swap(stack, "sa");
		_rotate(stack, "ra");
	}
	else if (head > middle && tail > middle && tail > head)
		_swap(stack, "sa");
	else if (middle > head && middle > tail && head > tail)
		_rev_rotate(stack, "rra");
}

int	_iter_forward(t_stack *stack, int n)
{
	int		index;
	t_node	*tmp;

	index = 0;
	if (n > stack->tail->data && stack->head->data < stack->tail->data)
		return (0);
	tmp = stack->head;
	while (tmp && tmp->data < n && tmp->data >= stack->head->data)
	{
		tmp = tmp->next;
		index++;
	}
	return (index);
}

int	_iter_backward(t_stack *stack, int n)
{
	int		index;
	t_node	*tmp;

	index = 0;
	if (stack->tail->data > stack->head->data)
		return (0);
	tmp = stack->tail;
	while (tmp && tmp->data > n && tmp->data <= stack->tail->data)
	{
		tmp = tmp->prev;
		index--;
	}
	return (index);
}
