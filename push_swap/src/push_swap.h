/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:01:17 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/31 15:56:41 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"
# include "../lib/gnl/get_next_line.h"

typedef struct s_node
{
	struct s_node	*next;
	struct s_node	*prev;
	int				data;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
	int		len;
	int		min;
	int		max;
}	t_stack;

void	_push(t_stack *stack, t_node *node);
void	_push_back(t_stack *stack, t_node *node);
t_node	*_pop(t_stack *stack);
void	_swap(t_stack *stack, char *msg);
void	_ss(t_stack *stack_a, t_stack *stack_b, char *msg);
void	_pa(t_stack *stack_a, t_stack *stack_b, char *msg);
void	_pb(t_stack *stack_a, t_stack *stack_b, char *msg);
void	_rotate(t_stack *stack, char *msg);
void	_rev_rotate(t_stack *stack, char *msg);
void	_sort(t_stack *stack_a, t_stack *stack_b);
void	_rr(t_stack *stack_a, t_stack *stack_b, char *msg);
void	_rrr(t_stack *stack_a, t_stack *stack_b, char *msg);
int		_sum(int a, int b);
void	_sort_three(t_stack *stack);
t_node	*_create_node(int n);
t_stack	*_init_stack(void);
void	_free_stack(t_stack *stack);
void	_parse_error(void);
int		_atoi(const char *str);
void	_is_digit(char *str);
void	_parse_argv(char **argv, t_stack *stack);
void	_check_duplicates(t_stack *stack);
int		_iter_backward(t_stack *stack, int n);
int		_iter_forward(t_stack *stack, int n);
void	_set_location_synced(t_stack *stack_a, \
		t_stack *stack_b, int *a_rot, int *b_rot);
void	_set_location_a(t_stack *stack_a, int *a_rot);
void	_set_location_b(t_stack *stack_b, int *b_rot);
void	_divide(t_stack *stack_a, t_stack *stack_b);
#endif