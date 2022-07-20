/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 17:01:17 by jaekjung          #+#    #+#             */
/*   Updated: 2022/07/20 17:14:16 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include "./lib/libft/libft.h"
# include "./lib/ft_printf/ft_printf.h"

typedef struct s_node
{
    struct s_node   *next;
    int             data;
}   t_node;

#endif