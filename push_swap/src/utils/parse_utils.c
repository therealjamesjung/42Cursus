/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:02:04 by jaekjung          #+#    #+#             */
/*   Updated: 2022/08/03 00:35:55 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	_parse_error(void)
{
	ft_printf("Error\n");
	exit(1);
}

void	_parse_argv(char **argv, t_stack *stack)
{
	char		**arr;
	int			i;
	int			j;
	t_node		*new_node;

	i = 0;
	while (argv[++i])
	{
		arr = ft_split(argv[i], ' ');
		j = -1;
		while (arr[++j])
		{
			_is_digit(arr[j]);
			new_node = _create_node(_atoi(arr[j]));
			_push_back(stack, new_node);
			free(arr[j]);
			arr[j] = NULL;
		}
		free(arr);
		arr = NULL;
	}
}

void	_check_duplicates(t_stack *stack)
{
	t_node	*i;
	t_node	*j;

	i = stack->head;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->data == j->data)
			{
				_free_stack(stack);
				_parse_error();
			}
			j = j->next;
		}
		i = i->next;
	}
}

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
