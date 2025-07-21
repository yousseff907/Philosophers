/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_monitoring.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:31:16 by yitani            #+#    #+#             */
/*   Updated: 2025/07/21 17:19:18 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static int	all_have_eaten(t_rules *rules)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	pthread_mutex_lock(&rules->death_lock);
	while (i < rules->number_of_philosophers)
	{
		if (rules->philosophers[i]->meals_eaten == rules->must_eat)
			count++;
		i++;
	}
	pthread_mutex_unlock(&rules->death_lock);
	return (count == rules->number_of_philosophers);
}

static int	philosopher_is_dead(t_rules *rules)
{
	int	i;
	long long	meal_time;

	i = 0;
	pthread_mutex_lock(&rules->death_lock);
	meal_time = get_curr_time() - rules->philosophers[i]->last_meal_time;
	pthread_mutex_unlock(&rules->death_lock);
	while (i < rules->number_of_philosophers)
	{
		if (meal_time >= rules->time_to_die)
		{
			someone_died(rules->philosophers[i]);
			return (1);
		}
		i++;
	}
	return (0);
}

void	*run_monitor(void *arg)
{
	t_rules	*rules;

	rules = (t_rules *)arg;
	while (!simulation_is_over(rules))
	{
		if (philosopher_is_dead(rules))
			break ;
		if (rules->must_eat != -1)
		{
			if (all_have_eaten(rules))
			{
				kill_simulation(rules);
				break ;
			}
		}
		usleep(100);
	}
	return (NULL);
}
