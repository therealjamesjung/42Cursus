/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:20:31 by jaekjung          #+#    #+#             */
/*   Updated: 2022/09/02 15:29:06 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_philo
{
    int             id;
    int             eat_cnt;
    long long       last_eat;
    pthread_mutex_t *left_fork;
    pthread_mutex_t *right_fork;
    pthread_mutex_t *log;
    struct s_table  *table;
} t_philo;

typedef struct s_table
{
    int             chair_cnt;
    int             death_time;
    int             eat_time;
    int             sleep_time;
    int             necessary_eats;
    pthread_mutex_t *fork;
    pthread_mutex_t *log;
    struct s_philo  *philo;

} t_table;

typedef enum e_status
{
	WAIT,
	EAT,
	SLEEP,
	THINK,
	DEAD
}	t_status;

int	ft_atoi(const char *str);

#endif