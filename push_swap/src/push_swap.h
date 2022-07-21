/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:01:17 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/21 20:13:45 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <limits.h>
# include "../lib/libft/libft.h"
# include "../lib/ft_printf/ft_printf.h"

typedef struct s_node
{
    struct s_node   *next;
    struct s_node   *prev;
    int             data;
}   t_node;

typedef struct s_stack
{
    t_node  *head;
    t_node  *tail;
    int     len;
}   t_stack;

void	_push(t_stack *stack, t_node *node);
t_node	*_pop(t_stack *stack);
void	_swap(t_stack *stack, char *msg);
void    _pa(t_stack *stack_a, t_stack *stack_b);
void    _pb(t_stack *stack_a, t_stack *stack_b);
void	_rotate(t_stack *stack, char *msg);
void	_rev_rotate(t_stack *stack, char *msg);
void	_sort(t_stack *stack_a, t_stack *stack_b);
void    _rr(t_stack *stack_a, t_stack *stack_b);
void    _rrr(t_stack *stack_a, t_stack *stack_b);
void print_stack(t_stack *stack);

#endif