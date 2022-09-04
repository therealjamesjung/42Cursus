/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:36:35 by jaekjung          #+#    #+#             */
/*   Updated: 2022/09/04 19:21:17 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void	_log(t_philo *philo, t_status status)
{
	long long	start_timestamp;

	pthread_mutex_lock(philo->table->m_log);
	start_timestamp = philo->table->start_timestamp;
	if (philo->table->full_cnt == philo->table->chair_cnt \
		|| philo->table->death_flag)
	{
		pthread_mutex_unlock(philo->table->m_log);
		return ;
	}
	if (status == FORK)
		printf("%lld %d has taken a fork\n", \
			_gettime() - start_timestamp, philo->id);
	else if (status == EAT)
		printf("%lld %d is eating\n", _gettime() - start_timestamp, philo->id);
	else if (status == SLEEP)
		printf("%lld %d is sleeping\n", _gettime() - start_timestamp, philo->id);
	else if (status == THINK)
		printf("%lld %d is thinking\n", _gettime() - start_timestamp, philo->id);
	else if (status == DEAD)
	{
		printf("%lld %d died\n", _gettime() - start_timestamp, philo->id);
		philo->table->death_flag = 1;
	}
	pthread_mutex_unlock(philo->table->m_log);
}

void	_run(t_table *table)
{
	int			i;
	pthread_t	*thread;
	pthread_t	*monitor;

	thread = (pthread_t *)malloc(sizeof(pthread_t) * table->chair_cnt);
	monitor = (pthread_t *)malloc(sizeof(pthread_t));
	i = -1;
	pthread_mutex_lock(table->start);
	while (++i < table->chair_cnt)
	{
		table->philo[i].last_eat = _gettime();
		pthread_create(&(thread[i]), NULL, _routine, &(table->philo[i]));
	}
	pthread_create(monitor, NULL, _monitor, table);
	pthread_mutex_unlock(table->start);
	i = -1;
	while (++i < table->chair_cnt)
		pthread_join(thread[i], NULL);
	pthread_join(*monitor, NULL);
	free(thread);
	free(monitor);
}

void	_free_table(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->chair_cnt)
	{
		pthread_mutex_destroy(table->philo[i].m_eats);
		free(table->philo[i].m_eats);
	}
	pthread_mutex_destroy(table->start);
	pthread_mutex_destroy(table->m_log);
	pthread_mutex_destroy(table->fork);
	free(table->start);
	free(table->m_log);
	free(table->fork);
	free(table->philo);
	free(table);
}

int	main(int argc, char **argv)
{
	t_table	*table;

	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		return (-1);
	if (!_init(argc, argv, table))
	{
		printf("Parse Error");
		return (-1);
	}
	_run(table);
	_free_table(table);
	return (0);
}
