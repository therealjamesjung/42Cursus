/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:26:21 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/31 03:52:49 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	_find_location(t_stack *stack, int n)
{
	int		index;
	t_node	*tmp;

	index = 0;
	if (n > stack->head->data)
	{
		if (n > stack->tail->data && stack->head->data < stack->tail->data)
			return (0);
		tmp = stack->head;
		while (tmp && tmp->data < n && tmp->data >= stack->head->data)
		{
			tmp = tmp->next;
			index++;
		}
	}
	else
	{
		if (stack->tail->data > stack->head->data)
			return (0);
		tmp = stack->tail;
		while (tmp && tmp->data > n && tmp->data <= stack->tail->data)
		{
			tmp = tmp->prev;
			index--;
		}
	}
	return (index);
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
	while (a_rot && b_rot)
	{
		if (a_rot > 0 && b_rot > 0)
		{
			_rr(stack_a, stack_b, "rr");
			a_rot--;
			b_rot--;
		}
		else if (a_rot < 0 && b_rot < 0)
		{
			_rrr(stack_a, stack_b, "rrr");
			a_rot++;
			b_rot++;
		}
		else
			break ;
	}
	while (a_rot)
	{
		if (a_rot > 0)
		{
			_rotate(stack_a, "ra");
			a_rot--;
		}
		else
		{
			_rev_rotate(stack_a, "rra");
			a_rot++;
		}
	}
	while (b_rot)
	{
		if (b_rot > 0)
		{
			_rotate(stack_b, "rb");
			b_rot--;
		}
		else
		{
			_rev_rotate(stack_b, "rrb");
			b_rot++;
		}
	}
}

void	_insertion_sort(t_stack *stack_a, t_stack *stack_b)
{
	int	a_rotation;
	int	b_rotation;

	while (stack_a->len > 3)
		_pb(stack_a, stack_b, "pb");
	_sort_three(stack_a);
	while (stack_b->len)
	{
		a_rotation = 0;
		b_rotation = 0;
		_count_rotation(stack_a, stack_b, &a_rotation, &b_rotation);
		_set_location(stack_a, stack_b, a_rotation, b_rotation);
		_pa(stack_a, stack_b, "pa");
	}
	while (stack_a->tail->data < stack_a->head->data)
		_rev_rotate(stack_a, "rra");
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
		_insertion_sort(stack_a, stack_b);
}
