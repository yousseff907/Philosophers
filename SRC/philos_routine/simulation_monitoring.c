/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_monitoring.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:31:16 by yitani            #+#    #+#             */
/*   Updated: 2025/07/20 16:11:55 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	run_monitor(t_rules *rules)
{
	int	i;

	i = 0;
	while (i < rules->number_of_philosophers)
	{
		if (rules->philosophers[i]->last_meal_time >= rules->time_to_die)
			someone_died(rules->philosophers[i]);
		if (rules->must_eat != -1)
			if (rules->philosophers[i]->meals_eaten >= rules->must_eat)
				kill_simulation(rules);
	}
}