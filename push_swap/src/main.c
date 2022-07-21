/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:01:08 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/20 19:10:26 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node  *_create_node(int n)
{
    t_node  *new_node;

    new_node = (t_node *)malloc(sizeof(new_node));
    new_node->next = NULL;
    new_node->data = n;
    
    return (new_node);
}

void    _init_stack(t_stack *stack_a, t_stack *stack_b)
{
    stack_a = (t_stack *)malloc(sizeof(t_stack));
    stack_b = (t_stack *)malloc(sizeof(t_stack));

    stack_a->head = NULL;
    stack_a->tail = NULL;
    stack_a->len = 0;
    stack_b->head = NULL;
    stack_b->tail = NULL;
    stack_b->len = 0;
}

int main(int argc, char **argv)
{
    t_stack  *stack_a;
    t_stack  *stack_b;

    if (argc != 2)
    {
        ft_printf("Error\nArguments count must be 2.");
        exit(1);
    }
    _init_stack(stack_a, stack_b);
    return (0);
}