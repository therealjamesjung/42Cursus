/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:36:21 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/31 04:15:12 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	_swap(t_stack *stack, char *msg)
{
	int	tmp;

	if (stack->len < 2)
		return ;
	if (msg)
		ft_printf("%s\n", msg);
	tmp = stack->head->data;
	stack->head->data = stack->head->next->data;
	stack->head->next->data = tmp;
}

void	_ss(t_stack *stack_a, t_stack *stack_b, char *msg)
{
	_swap(stack_a, msg);
	_swap(stack_b, msg);
}
