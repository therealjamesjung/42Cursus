/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:01:08 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/30 17:39:54 by jaekjung         ###   ########.fr       */
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
	ft_printf("Error\n");
	exit(1);
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
	_sort(stack_a, stack_b);
	_free_stack(stack_a);
	_free_stack(stack_b);
	return (0);
}
