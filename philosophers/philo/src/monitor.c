/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:30:56 by jaekjung          #+#    #+#             */
/*   Updated: 2022/09/04 19:17:18 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	_check_death(t_table *table, int i)
{
	pthread_mutex_lock(table->philo[i].m_eats);
	if (_gettime() - table->philo[i].last_eat > table->death_time)
	{
		pthread_mutex_unlock(table->philo[i].m_eats);
		pthread_mutex_unlock(table->philo[i].left_fork);
		pthread_mutex_unlock(table->philo[i].right_fork);
		_log(&(table->philo[i]), DEAD);
		return (1);
	}
	pthread_mutex_unlock(table->philo[i].m_eats);
	return (0);
}

int	_check_necessary_eats(t_table *table)
{
	pthread_mutex_lock(table->m_log);
	if (table->necessary_eats && table->full_cnt == table->necessary_eats)
		table->death_flag = 1;
	if (table->death_flag)
	{
		pthread_mutex_unlock(table->m_log);
		return (1);
	}
	pthread_mutex_unlock(table->m_log);
	return (0);
}

void	*_monitor(void *data)
{
	int		i;
	t_table	*table;

	table = (t_table *)data;
	i = 0;
	while (1)
	{
		if (i == table->chair_cnt)
			i = 0;
		if (_check_death(table, i))
			return (0);
		if (_check_necessary_eats(table))
			return (0);
		i++;
	}
	return (0);
}
