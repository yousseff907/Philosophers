/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 22:18:55 by yitani            #+#    #+#             */
/*   Updated: 2025/07/20 00:59:08 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

int	simulation_is_over(t_rules *rules)
{
	int	dead;

	pthread_mutex_lock(&rules->death_lock);
	dead = rules->someone_died;
	pthread_mutex_unlock(&rules->death_lock);
	return (dead);
}

void	update_mealtime(t_philosopher *philo)
{
	philo->last_meal_time = get_curr_time();
	philo->meals_eaten += 1;
}

void	my_usleep(t_rules *rules, int duration)
{
	long long	start_time;
	long long	curr_time;

	start_time = get_curr_time();
	while (!simulation_is_over(rules))
	{
		curr_time = get_curr_time();
		if (curr_time - start_time >= duration)
			break ;
		usleep(1000);
	}
}
