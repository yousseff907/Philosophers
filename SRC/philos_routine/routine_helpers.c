/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:53:05 by yitani            #+#    #+#             */
/*   Updated: 2025/07/19 22:00:14 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_status(t_philosopher *philo, char *status)
{
	long long	time_stamp;
	
	pthread_mutex_lock(&philo->rules->print_lock);
	if (!philo->rules->someone_died)
	{
		time_stamp = get_curr_time() - philo->rules->start_time;
		printf("%lld %d %s", time_stamp, philo->id + 1, status);
	}
	pthread_mutex_unlock(&philo->rules->print_lock);
}

void	someone_died(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->rules->death_lock);
	philo->rules->someone_died = 1;
	cleanup_and_exit(philo->rules, 0);
}
