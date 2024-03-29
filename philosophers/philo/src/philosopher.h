/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:20:31 by jaekjung          #+#    #+#             */
/*   Updated: 2022/09/04 18:47:14 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_philo
{
	int				id;
	int				eat_cnt;
	long long		last_eat;
	pthread_mutex_t	*m_eats;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	struct s_table	*table;
}	t_philo;

typedef struct s_table
{
	int				chair_cnt;
	int				death_time;
	int				eat_time;
	int				sleep_time;
	int				necessary_eats;
	long long		start_timestamp;
	int				death_flag;
	int				full_cnt;
	pthread_mutex_t	*m_log;
	pthread_mutex_t	*start;
	struct s_philo	*philo;
	pthread_mutex_t	*fork;
}	t_table;

typedef enum e_status
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DEAD
}	t_status;

int			ft_atoi(const char *str);
long long	_gettime(void);
void		_usleep(long long time);
int			_init(int argc, char **argv, t_table *table);
void		*_routine(void *data);
void		_log(t_philo *philo, t_status status);
int			_check_finish(t_philo *philo);
void		*_monitor(void *data);

#endif