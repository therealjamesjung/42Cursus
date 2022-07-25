/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 17:37:22 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/25 22:57:50 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	_pa(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("pa\n");
	_push(stack_a, _pop(stack_b));
}

void	_pb(t_stack *stack_a, t_stack *stack_b)
{
	ft_printf("pb\n");
	_push(stack_b, _pop(stack_a));
}
