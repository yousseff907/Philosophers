/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:34:03 by yitani            #+#    #+#             */
/*   Updated: 2025/07/14 11:32:24 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	*valid_args(int argc, char **argv, t_rules *rules, long long *val)
{
	int	count;

	count = 0;
	if (argc != 6)
	{
		ft_putendl_fd("Error : enter 5 arguments", 2);
		exit(1);
	}
	while (count < 5)
	{
		val[count] = ft_atoi(argv[count]);
		if (!val[count])
		{
			ft_putendl_fd("Error : enter numerical non zero arguments", 2);
			exit(1);
		}
		count++;
	}
	return (val);
}

static void	initialize_join_threads(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		pthread_create(rules->philosophers[i]->thread, NULL,\
			philos_routine(), rules->philosophers[i]);
		i++;
	}
	i = 0;
	while (i < rules->number_of_philosophers)
	{
		pthread_join(rules->philosophers[i]->thread, NULL);
		i++;
	}
}

static void	allocate_philosophers(t_philosopher **philos, int nb_philo)
{
	int	i;

	i = 0;
	philos = malloc(sizeof(t_philosopher *) * nb_philo);
	if (!philos)
		cleanup_and_exit();
	while (i < nb_philo)
	{
		philos[i] = malloc(sizeof(t_philosopher));
		if (!philos[i])
			cleanup_and_exit();
		i++;
	}
}

static void	initialize_mutexes(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
    	pthread_mutex_init(&rules->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&rules->print_lock, NULL);
	pthread_mutex_init(&rules->death_lock, NULL);
}

static void	init_philos_content(t_rules *rules)
{
	int	i;

	i = 0;
	while(i < rules->number_of_philosophers)
	{
		rules->philosophers[i]->id = i;
		rules->philosophers[i]->left_fork = rules->forks[i];
	}
}

void	initialize_vars(int argc, char **argv, t_rules *rules)
{
	long long		val[5];
	struct timeval	tv;

	rules = malloc(sizeof(t_rules));
	if (!rules)
		cleanup_and_exit(rules, 1);
	valid_args(argc, argv, rules, val);
	rules->number_of_philosophers = val[0];
	rules->time_to_die = val[1];
	rules->time_to_eat = val[2];
	rules->time_to_sleep = val[3];
	rules->must_eat = val[4];
	gettimeofday(&tv, NULL);
	rules->start_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	initialize_mutexes(rules);
	allocate_philosophers(rules->philosophers, val[0]);
	initialize_join_threads(rules);
}
