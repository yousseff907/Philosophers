/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:46:20 by yitani            #+#    #+#             */
/*   Updated: 2025/07/19 16:14:24 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*single_philosopher_routine(void *arg)
{
	t_philosopher	*philo;
	int				curr_time;

	philo = (t_philosopher *)arg;
	take_right_fork(philo);
	curr_time = get_curr_time();
	while (curr_time != philo->rules->time_to_die)
	{
		curr_time = get_curr_time();
		if (curr_time == philo->rules->time_to_die)
		{
			pthread_mutex_unlock(philo->right_fork);
			someone_died(philo->rules);
		}
	}
}

// TODO: Implement philosopher behavior
	// - Think, eat, sleep cycle
	// - Handle fork acquisition/release
	// - Check for death conditions

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	return (NULL);
}
