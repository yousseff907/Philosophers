/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:46:20 by yitani            #+#    #+#             */
/*   Updated: 2025/07/20 01:10:52 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*single_philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	pthread_mutex_lock(philo->left_fork);
	my_usleep(philo->rules, philo->rules->time_to_die);
	print_status(philo, "is thinking");
	pthread_mutex_unlock(philo->left_fork);
	someone_died(philo->rules);
	return (NULL);
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
