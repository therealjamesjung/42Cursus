/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 18:27:37 by jaekjung          #+#    #+#             */
/*   Updated: 2022/09/05 12:07:59 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	_check_finish(t_philo *philo)
{
	pthread_mutex_lock(philo->table->m_log);
	if (philo->table->death_flag || \
		philo->table->full_cnt == philo->table->chair_cnt)
	{
		pthread_mutex_unlock(philo->table->m_log);
		pthread_mutex_unlock(philo->m_eats);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	pthread_mutex_unlock(philo->table->m_log);
	pthread_mutex_lock(philo->m_eats);
	if (_gettime() - philo->last_eat > philo->table->death_time)
	{
		_log(philo, DEAD);
		pthread_mutex_unlock(philo->m_eats);
		pthread_mutex_unlock(philo->left_fork);
		pthread_mutex_unlock(philo->right_fork);
		return (1);
	}
	pthread_mutex_unlock(philo->m_eats);
	return (0);
}

int	_pick_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	_log(philo, FORK);
	pthread_mutex_lock(philo->right_fork);
	_log(philo, FORK);
	return (1);
}

int	_eat(t_philo *philo)
{
	if (_check_finish(philo) || !_pick_fork(philo))
		return (0);
	_log(philo, EAT);
	pthread_mutex_lock(philo->m_eats);
	pthread_mutex_lock(philo->table->m_log);
	philo->eat_cnt++;
	philo->last_eat = _gettime();
	if (philo->table->necessary_eats && \
		philo->table->necessary_eats == philo->eat_cnt)
		philo->table->full_cnt++;
	pthread_mutex_unlock(philo->m_eats);
	pthread_mutex_unlock(philo->table->m_log);
	_usleep(philo->table->eat_time);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (1);
}

int	_sleep(t_philo *philo)
{
	if (_check_finish(philo))
		return (0);
	_log(philo, SLEEP);
	_usleep(philo->table->sleep_time);
	if (_check_finish(philo))
		return (0);
	_log(philo, THINK);
	return (1);
}

void	*_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(philo->table->start);
	pthread_mutex_unlock(philo->table->start);
	if (philo->id % 2 == 0)
		_usleep(10);
	while (_eat(philo) && _sleep(philo))
		;
	return (0);
}
