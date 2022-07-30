/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:37:22 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/31 03:51:39 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	_pa(t_stack *stack_a, t_stack *stack_b, char *msg)
{
	if (msg)
		ft_printf("%s\n", msg);
	_push(stack_a, _pop(stack_b));
}

void	_pb(t_stack *stack_a, t_stack *stack_b, char *msg)
{
	if (msg)
		ft_printf("%s\n", msg);
	_push(stack_b, _pop(stack_a));
}
