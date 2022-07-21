/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:01:08 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/21 20:20:57 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	_parse_error()
{
	ft_printf("Error\n");
	system("leaks push_swap");
	exit(1);
}

t_node  *_create_node(int n)
{
    t_node  *new_node;

    new_node = (t_node *)malloc(sizeof(t_node));
    new_node->next = NULL;
	new_node->prev = NULL;
    new_node->data = n;
    return (new_node);
}

t_stack	*_init_stack()
{
	t_stack	*stack;

    stack = (t_stack *)malloc(sizeof(t_stack));
    stack->head = NULL;
    stack->tail = NULL;
    stack->len = 0;
	return (stack);
}

int	_atoi(const char *str)
{
	long long	result;
	int			is_positive;

	is_positive = 1;
	result = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			is_positive = -1;
		str++;
	}
	while (*str != 0 && '0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
		if (result - 1 > INT_MAX)
			_parse_error();
	}
	return ((int) result * is_positive);
}

void	_is_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '+' && str[i] != '-')
			_parse_error();
		if ((str[i] == '+' || str[i] == '-') && i != 0)
			_parse_error();
		if ((str[i] == '+' || str[i] == '-') && !ft_isdigit(str[i + 1]))
			_parse_error();
	}
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
			_push(stack, new_node);
			free(arr[j]);
			arr[j] = NULL;
		}
		free(arr);
		arr = NULL;
	}
}

void print_stack(t_stack *stack)
{
	t_node *tmp;

	tmp = stack->head;
	while (tmp)
	{
		ft_printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	// tmp = stack->tail;
	// ft_printf("-----Forward-----\n");
	// while (tmp)
	// {
	// 	ft_printf("%d ", tmp->data);
	// 	tmp = tmp->prev;
	// }
	// ft_printf("-----Backward-----\n");
}

void _free_stack(t_stack *stack)
{
	t_node	*tmp;
	t_node	*to_free;
	
	tmp = stack->head;
	while (tmp)
	{
		to_free = tmp;
		free(to_free);
		to_free = 0;
		tmp = tmp->next;
	}
	free(stack);
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

int main(int argc, char **argv)
{
    t_stack  *stack_a;
    t_stack  *stack_b;

	(void) argc;
    stack_a = _init_stack();
	_parse_argv(argv, stack_a);
	_check_duplicates(stack_a);
	stack_b = _init_stack();
	ft_printf("Before\n\n");
	print_stack(stack_a);
	ft_printf("\n\n");
	_sort(stack_a, stack_b);
	ft_printf("\n\nAfter\n\n");
	print_stack(stack_a);
	// free(stack_a);
	// free(stack_b);
	// system("leaks push_swap");
    return (0);
}