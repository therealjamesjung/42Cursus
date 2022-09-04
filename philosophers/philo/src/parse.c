/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaekjung <jaekjung@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/03 15:41:06 by jaekjung          #+#    #+#             */
/*   Updated: 2022/09/04 18:43:29 by jaekjung         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

int	_validate_table(t_table *table)
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

int	_parse(int argc, char **argv, t_table *table)
{
	if (argc != 5 && argc != 6)
		return (0);
	table->chair_cnt = ft_atoi(argv[1]);
	table->death_time = ft_atoi(argv[2]);
	table->eat_time = ft_atoi(argv[3]);
	table->sleep_time = ft_atoi(argv[4]);
	table->necessary_eats = 0;
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

int	_init_table(t_table *table)
{
	int	i;

	table->philo = (t_philo *)malloc(sizeof(t_philo) * table->chair_cnt);
	table->fork = malloc(sizeof(pthread_mutex_t) * table->chair_cnt);
	table->m_log = malloc(sizeof(pthread_mutex_t));
	table->start = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(table->m_log, NULL);
	pthread_mutex_init(table->start, NULL);
	table->start_timestamp = _gettime();
	table->death_flag = 0;
	table->full_cnt = 0;
	i = -1;
	while (++i < table->chair_cnt)
	{
		table->philo[i].id = i;
		table->philo[i].eat_cnt = 0;
		table->philo[i].last_eat = 0;
		table->philo[i].m_eats = malloc(sizeof(pthread_mutex_t));
		pthread_mutex_init(table->philo[i].m_eats, NULL);
		pthread_mutex_init(&(table->fork[i]), NULL);
		table->philo[i].left_fork = &(table->fork[i]);
		table->philo[i].right_fork = &(table->fork[(i + 1) % table->chair_cnt]);
		table->philo[i].table = table;
	}
	return (1);
}

int	_init(int argc, char **argv, t_table *table)
{
	if (!_parse(argc, argv, table))
		return (0);
	if (!_init_table(table))
		return (0);
	return (1);
}
