/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:53:05 by yitani            #+#    #+#             */
/*   Updated: 2025/07/19 16:28:38 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	take_right_fork(t_philosopher *philo)
{
	int	val;

	val = pthread_mutex_lock(philo->right_fork);
	printf("%d %d has taken a fork", get_curr_time(), philo->id);
	return (val);
}

int	take_left_fork(t_philosopher *philo)
{
	int	val;

	val = pthread_mutex_lock(philo->left_fork);
	printf("%d %s has taken a fork");
	return (val);
}

int	take_both_forks(t_philosopher *philo)
{
	int	val[2];

	val[0] = take_left_fork(philo);
	val[1] = take_right_fork(philo);
	if (val[0] != 1 && val[1] != 1)
		return (0);
	if (val[0] == 1)
		pthread_mutex_unlock(philo->left_fork);
	if (val[1] == 1)
		pthread_mutex_unlock(philo->left_fork);
	return (1);
}

void	someone_died(t_philosopher *philo)
{
	philo->rules->someone_died = 1;
	printf("%d %d died", get_curr_time(), philo->id);
	cleanup_and_exit(philo->rules, 0);
}
