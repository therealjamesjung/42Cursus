/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:01:08 by jaekjung          #+#    #+#             */
/*   Updated: 2022/08/03 00:39:35 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	_sort(stack_a, stack_b);
	_free_stack(stack_a);
	_free_stack(stack_b);
	return (0);
}
