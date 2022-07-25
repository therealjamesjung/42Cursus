/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 23:30:48 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/25 23:42:33 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	_set_location_synced(t_stack *stack_a, t_stack *stack_b, \
							int a_rot, int b_rot)
{
	while (a_rot && b_rot)
	{
		if (a_rot > 0 && b_rot > 0)
		{
			_rr(stack_a, stack_b);
			a_rot--;
			b_rot--;
		}
		else if (a_rot < 0 && b_rot < 0)
		{
			_rrr(stack_a, stack_b);
			a_rot++;
			b_rot++;
		}
		else
			break ;
	}
}

void	_set_location_a(t_stack *stack_a, int a_rot)
{
	while (a_rot)
	{
		if (a_rot > 0)
		{
			_rotate(stack_a, "ra");
			a_rot--;
		}
		else
		{
			_rev_rotate(stack_a, "rra");
			a_rot++;
		}
	}
}

void	_set_location_b(t_stack *stack_b, int b_rot)
{
	while (b_rot)
	{
		if (b_rot > 0)
		{
			_rotate(stack_b, "rb");
			b_rot--;
		}
		else
		{
			_rev_rotate(stack_b, "rrb");
			b_rot++;
		}
	}
}
