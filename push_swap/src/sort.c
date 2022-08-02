/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:26:21 by jaekjung          #+#    #+#             */
/*   Updated: 2022/08/03 00:42:02 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	_find_location(t_stack *stack, int n)
{
	if (n >= stack->head->data)
		return (_iter_forward(stack, n));
	else
		return (_iter_backward(stack, n));
}

void	_count_rotation(t_stack *stack_a, t_stack *stack_b, int *a, int *b)
{
	t_node	*tmp;
	int		a_location;
	int		b_location;

	tmp = stack_b->head;
	b_location = 0;
	while (tmp)
	{
		a_location = _find_location(stack_a, tmp->data);
		if (b_location >= (stack_b->len + 1) / 2)
			b_location = b_location - stack_b->len;
		if (b_location == 0 || _sum(*a, *b) > _sum(a_location, b_location))
		{
			*a = a_location;
			*b = b_location;
		}
		tmp = tmp->next;
		b_location++;
	}
}

void	_set_location(t_stack *stack_a, t_stack *stack_b, int a_rot, int b_rot)
{
	_set_location_synced(stack_a, stack_b, &a_rot, &b_rot);
	_set_location_a(stack_a, &a_rot);
	_set_location_b(stack_b, &b_rot);
}

void	_greedy_insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	a_rotation;
	int	b_rotation;

	_divide(stack_a, stack_b);
	while (stack_a->len > 3)
		_pb(stack_a, stack_b, "pb");
	if (stack_a->len == 2)
	{
		if (stack_a->head->data > stack_a->head->next->data)
			_swap(stack_a, "sa");
	}
	else if (stack_a->len == 3)
		_sort_three(stack_a);
	while (stack_b->len)
	{
		a_rotation = 0;
		b_rotation = 0;
		_count_rotation(stack_a, stack_b, &a_rotation, &b_rotation);
		_set_location(stack_a, stack_b, a_rotation, b_rotation);
		_pa(stack_a, stack_b, "pa");
	}
	_rearrange(stack_a);
}

void	_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len == 2)
	{
		if (stack_a->head->data > stack_a->head->next->data)
			_swap(stack_a, "sa");
	}
	else if (stack_a->len == 3)
		_sort_three(stack_a);
	else
		_greedy_insertion_sort(stack_a, stack_b);
}
