/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:02:04 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/25 23:21:12 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	_parse_error(void)
{
	ft_printf("Error\n");
	system("leaks push_swap");
	exit(1);
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
