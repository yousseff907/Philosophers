/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_thr_mut_alloc.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:53:45 by yitani            #+#    #+#             */
/*   Updated: 2025/07/19 14:47:27 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_rules	*allocate_rules(void)
{
	t_rules	*rules;

	rules = malloc(sizeof(t_rules));
	if (!rules)
		cleanup_and_exit(rules, 1);
	return (rules);
}

void	initialize_threads(t_rules *rules)
{
	int	i;

	i = 0;
	if (rules->number_of_philosophers > 1)
	{
		while (i < rules->number_of_philosophers)
		{
			pthread_create(rules->philosophers[i]->thread, NULL,
				philosopher_routine, rules->philosophers[i]);
			i++;
		}
	}
	else
	{
		pthread_create(rules->philosophers[i]->thread, NULL,
			single_philosopher_routine, rules->philosophers[i]);
	}
}

void	allocate_philosophers(t_rules *rules, int nb_philo)
{
	int	i;

	i = 0;
	rules->philosophers = malloc(sizeof(t_philosopher *) * nb_philo);
	if (!rules->philosophers)
		cleanup_and_exit(rules, 1);
	while (i < nb_philo)
	{
		rules->philosophers[i] = malloc(sizeof(t_philosopher));
		if (!rules->philosophers[i])
			cleanup_and_exit(rules, 1);
		i++;
	}
}

void	initialize_mutexes(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		if (pthread_mutex_init(&rules->forks[i], NULL) != 0)
			cleanup_and_exit(rules, 1);
		i++;
	}
	if (pthread_mutex_init(&rules->print_lock, NULL) != 0)
		cleanup_and_exit(rules, 1);
	if (pthread_mutex_init(&rules->death_lock, NULL) != 0)
		cleanup_and_exit(rules, 1);
}
