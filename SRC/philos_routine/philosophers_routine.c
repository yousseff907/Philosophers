/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:46:20 by yitani            #+#    #+#             */
/*   Updated: 2025/07/21 20:10:29 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	*single_philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	my_usleep(philo->rules, 1);
	print_status(philo, "is thinking");
	my_usleep(philo->rules, philo->rules->time_to_die - 1);
	pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}

int	test_ft(t_philosopher *philo)
{
	int	optimal_thinking_time;
	
	optimal_thinking_time = philo->rules->time_to_eat * 2 / philo->rules->number_of_philosophers;
	if (optimal_thinking_time < 1) 
   		optimal_thinking_time = 1;
	return (optimal_thinking_time);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2 == 1)
	{
		my_usleep(philo->rules, 1);
		print_status(philo, "is thinking");
	}
	while (!simulation_is_over(philo->rules))
	{
		if (philo->id % 2 == 1)
			odd_philo_takes_forks(philo);
		else if (philo->id % 2 == 0)
			even_philo_takes_forks(philo);
		update_mealtime(philo);
		release_forks(philo);
		philo_is_sleeping(philo);
		if (philo->rules->number_of_philosophers % 2 == 1)
		{
			my_usleep(philo->rules, 1);
			print_status(philo, "is thinking");
		}
	}
	return (NULL);
}
