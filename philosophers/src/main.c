/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/29 21:20:08 by jaekjung          #+#    #+#             */
/*   Updated: 2022/09/02 17:44:19 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int _validate_table(t_table *table)
{
    if (table->chair_cnt < 1)
		return (0);
	if (table->death_time < 0)
		return (0);
	if (table->eat_time < 0)
		return (0);
	if (table->sleep_time < 0)
		return (0);
	return (1);
}

int _parse(int argc, char **argv, t_table *table)
{
    if (argc != 5 && argc != 6)
		return (0);
	table->chair_cnt = ft_atoi(argv[1]);
	table->death_time = ft_atoi(argv[2]);
	table->eat_time = ft_atoi(argv[3]);
	table->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
	{
		table->necessary_eats = ft_atoi(argv[5]);
		if (table->necessary_eats < 0)
			return (0);
	}
	if (!_validate_table(table))
		return (0);
    return (1);
}

void _init_philo(t_philo *philo, int id)
{
    philo->eat_cnt = 0;
    philo->id = id;
    philo->last_eat = 0;
}

long long	_gettime(void)
{
	struct timeval  time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

int _init_mutex(t_table *table)
{
    int i;
    
    i = -1;
    table->philo = (t_philo *)malloc(sizeof(t_philo) * table->chair_cnt);
    table->fork = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * table->chair_cnt);
    table->log = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t));
    pthread_mutex_init(table->log, NULL);
    while (++i < table->chair_cnt)
    {
        if (pthread_mutex_init(&(table->fork[i]), NULL) != 0)
            return (0);
        table->philo[i].eat_cnt = 0;
        table->philo[i].last_eat = _gettime();
        table->philo[i].id = i;
        table->philo[i].left_fork = &(table->fork[i % table->chair_cnt]);
        table->philo[i].right_fork = &(table->fork[(i + 1) % table->chair_cnt]);
        table->philo[i].log = table->log;
        table->philo[i].table = table;
    }
    return (1);
}

int _init(int argc, char **argv, t_table *table)
{
    if (!_parse(argc, argv, table))
        return (0);
    if (!_init_mutex(table))
        return (0);
    return (1);
}


void _sleep(long long time)
{
    long long finish_time;

    finish_time = time + _gettime();
    while (finish_time > (long long) _gettime())
        usleep(100);
}

void _log(t_status status, t_philo *philo)
{
    pthread_mutex_lock(philo->log);
    if (status == WAIT)
        printf("%lld %d has taken a fork\n", _gettime(), philo->id);
    else if (status == EAT)
        printf("%lld %d is eating\n", _gettime(), philo->id);
    else if (status == SLEEP)
        printf("%lld %d is sleeping\n", _gettime(), philo->id);
    else if (status == THINK)
        printf("%lld %d is thinking\n", _gettime(), philo->id);
    else if (status == DEAD)
        printf("%lld %d is dead\n", _gettime(), philo->id);
    pthread_mutex_unlock(philo->log);
}

void *_routine(void *data)
{
    t_philo *philo;
    philo = (t_philo *)data;
    while (1)
    {
        pthread_mutex_lock(philo->left_fork);
        _log(WAIT, philo);
        pthread_mutex_lock(philo->right_fork);
        _log(EAT, philo);
        philo->last_eat = _gettime();
        _sleep(philo->table->eat_time);
        pthread_mutex_unlock(philo->right_fork);
        pthread_mutex_unlock(philo->left_fork);
        _log(SLEEP, philo);
        _sleep(philo->table->sleep_time);
    }
    return (0);
}
void _run(t_table *table)
{
    int i;
    pthread_t *thread;

    thread = (pthread_t *)malloc(sizeof(pthread_t) * table->chair_cnt);
    i = -1;
    while (++i < table->chair_cnt)
    {
        pthread_create(&(thread[i]), NULL, _routine, &(table->philo[i]));
        usleep(10);
    }
    i = -1;
    while (++i < table->chair_cnt)
        pthread_join(thread[i], NULL);
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
        if (_gettime() - table->philo[i].last_eat > table->death_time)
        {
            _log(DEAD, &(table->philo[i]));
            exit(0);
        }
        i++;
    }
    return (0);
}

int main(int argc, char **argv)
{
    t_table *table;
    pthread_t *monitor;

    table = (t_table *)malloc(sizeof(t_table));
    if (!table)
        return (-1);
    if (!_init(argc, argv, table))
    {
        printf("Parse Error");
        return (-1);
    }
    monitor = (pthread_t *)malloc(sizeof(pthread_t));
    pthread_create(monitor, NULL, _monitor, table);
    _run(table);
    for (int i=0; i<table->chair_cnt; i++)
        pthread_mutex_destroy(&(table->fork[i]));
    return (0);
}