/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:46:20 by yitani            #+#    #+#             */
/*   Updated: 2025/07/21 00:38:26 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*single_philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	usleep(philo->rules->time_to_die * 1);
	print_status(philo, "is thinking");
	usleep(philo->rules->time_to_die * 999);
	pthread_mutex_unlock(philo->left_fork);
	someone_died(philo);
	return (NULL);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2 == 0)
		my_usleep(philo->rules, 1);
	while (!simulation_is_over(philo->rules))
	{
		print_status(philo, "is thinking");
		if (philo->id % 2 == 1)
			odd_philo_takes_forks(philo);
		else if (philo->id % 2 == 0)
			even_philo_takes_forks(philo);
		update_mealtime_run_monitor(philo);
		release_forks(philo);
		philo_is_sleeping(philo);
	}
	return (NULL);
}
