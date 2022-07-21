/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:26:21 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/21 21:02:11 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	_sum(int a, int b)
{
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
	ft_printf("HMT: %d %d %d\n", head, middle, tail);
	if (head < middle && middle < tail && head < tail)
	{
		_swap(stack, "sa");
		_rev_rotate(stack, "rra");
	}
	else if (head < middle && tail < middle && head < tail)
		_rotate(stack, "ra");
	else if (middle < head && middle < tail && tail < head)
	{
		_swap(stack, "sa");
		_rotate(stack, "ra");
	}
	else if (head < middle && tail < middle && tail < head)
		_swap(stack, "sa");
	else if (middle < head && middle < tail && head < tail)
		_rev_rotate(stack, "rra");
}

int	_find_location(t_stack *stack, int n)
{
	int		index;
	t_node	*tmp;

	if (stack->head->data < n)
	{
		tmp = stack->head;
		index = 0;
		while (tmp)
		{
			if (tmp->data > n)
				return (index);
			if (tmp->data < n && tmp->next && tmp->data > tmp->next->data)
				return (index);
			tmp = tmp->next;
			index++;
		}
	}
	else
	{
		tmp = stack->tail;
		index = stack->len;
		while (tmp)
		{
			if (tmp->data < n)
				return ((stack->len - index) * -1);
			if (tmp->data > n && tmp->prev && tmp->data < tmp->prev->data)
				return ((stack->len - index) * -1);
			tmp = tmp->prev;
			index--;
		}
	}
	return (0);
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
			b_location = (stack_b->len - b_location) * -1;
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
			_rrr(stack_a, stack_b);
			a_rot--;
			b_rot--;
		}
		else if (a_rot < 0 && b_rot < 0)
		{
			_rr(stack_a, stack_b);
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
	int b_rotation;

	while (stack_a->len > 3)
		_pb(stack_a, stack_b);
	_sort_three(stack_a);
	while (stack_b->len)
	{
		a_rotation = 0;
		b_rotation = 0;
		ft_printf("Count Rotation\n");
		_count_rotation(stack_a, stack_b, &a_rotation, &b_rotation);
		ft_printf("a: %d b: %d\n", a_rotation, b_rotation);
		_set_location(stack_a, stack_b, a_rotation, b_rotation);
		_pa(stack_a, stack_b);
		ft_printf("A:\n");
		print_stack(stack_a);
		ft_printf("\nB:\n");
		print_stack(stack_b);
		ft_printf("\n");
	}
}

void	_sort(t_stack *stack_a, t_stack *stack_b)
{
	if (stack_a->len == 2)
	{
		if (stack_a->head->data < stack_a->head->next->data)
			_swap(stack_a, "sa");
	}
	else if (stack_a->len == 3)
		_sort_three(stack_a);
	else
		_insertion_sort(stack_a, stack_b);
}