/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:36:35 by jaekjung          #+#    #+#             */
/*   Updated: 2022/09/04 17:27:12 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

void _log(t_philo *philo, t_status status)
{
    pthread_mutex_lock(philo->table->m_log);
	if (philo->table->full_cnt == philo->table->chair_cnt || philo->table->death_flag)
	{
	    pthread_mutex_unlock(philo->table->m_log);
		return ;
	}
	if (status == FORK)
        printf("%lld %d has taken a fork\n", _gettime() - philo->table->start_timestamp, philo->id);
    else if (status == EAT)
        printf("%lld %d is eating\n", _gettime() - philo->table->start_timestamp, philo->id);
    else if (status == SLEEP)
        printf("%lld %d is sleeping\n", _gettime() - philo->table->start_timestamp, philo->id);
    else if (status == THINK)
        printf("%lld %d is thinking\n", _gettime() - philo->table->start_timestamp, philo->id);
	else if (status == DEAD)
	{
		printf("%lld %d died\n", _gettime() - philo->table->start_timestamp, philo->id);
		philo->table->death_flag = 1;
	}
    pthread_mutex_unlock(philo->table->m_log);
}

int _check_finish(t_philo *philo)
{
	pthread_mutex_lock(philo->table->m_log);
	if (philo->table->death_flag || philo->table->full_cnt == philo->table->chair_cnt)
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

int _choose_fork(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	// if (_check_finish(philo))
	// {
	// 	pthread_mutex_unlock(philo->left_fork);
	// 	return (0);
	// }
	_log(philo, FORK);
	pthread_mutex_lock(philo->right_fork);
	// if (_check_finish(philo))
	// {
	// 	pthread_mutex_unlock(philo->left_fork);
	// 	pthread_mutex_unlock(philo->right_fork);
	// 	return (0);
	// }	
	_log(philo, FORK);
	return (1);
}

int _eat(t_philo *philo)
{
	if (_check_finish(philo) || !_choose_fork(philo))
		return (0);
	pthread_mutex_lock(philo->m_eats);
	philo->eat_cnt++;
	philo->last_eat = _gettime();
	pthread_mutex_unlock(philo->m_eats);
	pthread_mutex_lock(philo->table->m_log);
	if (philo->table->necessary_eats && philo->table->necessary_eats == philo->eat_cnt)
		philo->table->full_cnt++;
	pthread_mutex_unlock(philo->table->m_log);
	if (_check_finish(philo))
		return (0);
	_log(philo, EAT);
	_usleep(philo->table->eat_time);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
	return (1);
}

int _sleep(t_philo *philo)
{
	if (_check_finish(philo))
		return (0);
	_log(philo, SLEEP);
	_usleep(philo->table->sleep_time);
	return (1);
}

int _think(t_philo *philo)
{
	if (_check_finish(philo))
		return (0);
	_log(philo, THINK);
	return (1);
}

void *_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	pthread_mutex_lock(philo->table->start);
	pthread_mutex_unlock(philo->table->start);
	if (philo->id % 2 == 0)
		_usleep(10);
	while (1)
	{
		// printf("%d running\n", philo->id);
		if (!_eat(philo))
			break ; 
		if (!_sleep(philo))
			break ;
		if (!_think(philo))
			break ;
	}
	return (0);
}

void *_monitor(void *data)
{
	int i;
    t_table *table;

    table = (t_table *)data;
    i = 0;
    while (1)
    {
        if (i == table->chair_cnt)
            i = 0;
		pthread_mutex_lock(table->philo[i].m_eats);
        if (_gettime() - table->philo[i].last_eat > table->death_time)
		{
			pthread_mutex_unlock(table->philo[i].left_fork);
			pthread_mutex_unlock(table->philo[i].right_fork);
			pthread_mutex_unlock(table->philo[i].m_eats);
            _log(&(table->philo[i]), DEAD);
			return (0);
		}
		pthread_mutex_unlock(table->philo[i].m_eats);
		pthread_mutex_lock(table->m_log);
        if (table->necessary_eats && table->full_cnt == table->necessary_eats)
            table->death_flag = 1;
		if (table->death_flag)
		{
			pthread_mutex_unlock(table->m_log);
			return (0);
		}
		pthread_mutex_unlock(table->m_log);
        i++;
    }
    return (0);
}

void _run(t_table *table)
{
    int i;
    pthread_t *thread;
	pthread_t *monitor;

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
}

int main(int argc, char **argv)
{
	 t_table *table;

    table = (t_table *)malloc(sizeof(t_table));
    if (!table)
        return (-1);
    if (!_init(argc, argv, table))
    {
        printf("Parse Error");
        return (-1);
    }
	_run(table);
	return (0);
}