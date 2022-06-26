/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 14:20:15 by jaekjung          #+#    #+#             */
/*   Updated: 2022/06/25 19:11:58 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdio.h> // TODO remove
# include <signal.h>
# include <stdlib.h>
# include <unistd.h>
# include "./ft_printf/ft_printf.h"

typedef struct sig_info
{
    unsigned char   *str;
    pid_t           server_pid;
} t_info;

void    _pid(int is_server);
int	ft_atoi(const char *str);

#endif