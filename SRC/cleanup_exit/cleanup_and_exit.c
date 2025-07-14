/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_and_exit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 01:23:17 by yitani            #+#    #+#             */
/*   Updated: 2025/07/14 09:25:36 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutexes(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		pthread_mutex_destroy(&rules->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&rules->print_lock);
	pthread_mutex_destroy(&rules->death_lock);
}

void	free_philosophers(t_rules *rules)
{
	if (rules->philosophers)
		free(rules->philosophers);
}

void	free_forks(t_rules *rules)
{
	if (rules->forks)
		free(rules->forks);
}

void	free_rules(t_rules *rules)
{
    destroy_mutexes(rules);
    free_philosophers(rules);
    free_forks(rules);
    free(rules);
}

void	cleanup_and_exit(t_rules *rules, int exit_code)
{
	destroy_mutexes(rules);
	free_philosophers(rules);
	free_forks(rules);
	free(rules);
	exit(exit_code);
}
