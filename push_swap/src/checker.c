/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 17:43:10 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/31 04:16:13 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	_operate(char *operation, t_stack *stack_a, t_stack *stack_b)
{
	if (ft_strncmp(operation, "sa\n", 3) == 0)
		_swap(stack_a, NULL);
	else if (ft_strncmp(operation, "sb\n", 3) == 0)
		_swap(stack_b, NULL);
	else if (ft_strncmp(operation, "ss\n", 3) == 0)
		_ss(stack_a, stack_b, NULL);
	else if (ft_strncmp(operation, "pa\n", 3) == 0)
		_pa(stack_a, stack_b, NULL);
	else if (ft_strncmp(operation, "pb\n", 3) == 0)
		_pb(stack_a, stack_b, NULL);
	else if (ft_strncmp(operation, "ra\n", 3) == 0)
		_rotate(stack_a, NULL);
	else if (ft_strncmp(operation, "rb\n", 3) == 0)
		_rotate(stack_b, NULL);
	else if (ft_strncmp(operation, "rr\n", 3) == 0)
		_rr(stack_a, stack_b, NULL);
	else if (ft_strncmp(operation, "rra\n", 4) == 0)
		_rev_rotate(stack_a, NULL);
	else if (ft_strncmp(operation, "rrb\n", 4) == 0)
		_rev_rotate(stack_b, NULL);
	else if (ft_strncmp(operation, "rrr\n", 4) == 0)
		_rrr(stack_a, stack_b, NULL);
	else
		return (0);
	return (1);
}

void	_parse_operation(t_stack *stack_a, t_stack *stack_b)
{
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!_operate(line, stack_a, stack_b))
		{
			ft_printf("Error\n");
			_free_stack(stack_a);
			_free_stack(stack_b);
			exit(1);
		}
		free(line);
		line = 0;
		line = get_next_line(0);
	}
	free(line);
	line = 0;
}

int	_is_sorted(t_stack *stack)
{
	t_node	*tmp;

	tmp = stack->head;
	while (tmp && tmp->next)
	{
		if (tmp->data > tmp->next->data)
			return (0);
		tmp = tmp->next;
	}
	return (1);
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
	stack_b = _init_stack();
	_parse_operation(stack_a, stack_b);
	if (_is_sorted(stack_a))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	_free_stack(stack_a);
	_free_stack(stack_b);
	return (0);
}
