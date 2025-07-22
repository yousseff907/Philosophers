/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup_and_return.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/13 01:23:17 by yitani            #+#    #+#             */
/*   Updated: 2025/07/21 15:41:23 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	destroy_mutexes(t_rules *rules)
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

static void	free_philosophers(t_rules *rules)
{
	int	i;

	i = 0;
	if (rules->philosophers)
	{
		while (i < rules->number_of_philosophers)
		{
			free(rules->philosophers[i]);
			i++;
		}
	}
	free(rules->philosophers);
}

static void	free_forks(t_rules *rules)
{
	if (rules->forks)
		free(rules->forks);
}

int	cleanup_and_return(t_rules *rules, int exit_code)
{
	destroy_mutexes(rules);
	free_philosophers(rules);
	free_forks(rules);
	free(rules);
	return (exit_code);
}
