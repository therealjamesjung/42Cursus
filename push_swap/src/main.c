/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:01:08 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/31 16:57:09 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_validate_sorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return ;
		tmp = tmp->next;
	}
	_free_stack(stack);
	exit(1);
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	if (argc == 1)
		return (0);
	stack_a = _init_stack();
	_parse_argv(argv, stack_a);
	_check_duplicates(stack_a);
	_validate_sorted(stack_a);
	stack_b = _init_stack();
	_set_min_max(stack_a);
	_set_min_max(stack_b);
	_sort(stack_a, stack_b);
	_free_stack(stack_a);
	_free_stack(stack_b);
	return (0);
}
