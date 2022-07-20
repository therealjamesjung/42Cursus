/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:01:08 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/20 17:14:34 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node  *_init_node(int n)
{
    t_node  *new_node;

    new_node = (t_node *)malloc(sizeof(new_node));
    new_node->next = NULL;
    new_node->data = n;
    
    return (new_node);
}

int main()
{
    // t_node  *stack_a;
    // t_node  *stack_b;

    // if (argc != 2)

    ft_printf("asdf");
    return (0);
}