/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_monitoring.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:31:16 by yitani            #+#    #+#             */
/*   Updated: 2025/07/21 14:41:49 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static int	all_have_eaten(t_rules *rules)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < rules->number_of_philosophers)
	{
		if (rules->philosophers[i]->meals_eaten == rules->must_eat)
			count++;
		i++;
	}
	return (count == rules->number_of_philosophers);
}

void	run_monitor(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		if (get_curr_time() - rules->philosophers[i]->last_meal_time >= rules->time_to_die)
			someone_died(rules->philosophers[i]);
		i++;
	}
	if (rules->must_eat != -1)
		if (all_have_eaten(rules))
			kill_simulation(rules);
}
