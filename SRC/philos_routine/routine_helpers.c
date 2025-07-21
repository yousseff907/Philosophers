/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_helpers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 15:53:05 by yitani            #+#    #+#             */
/*   Updated: 2025/07/21 18:55:14 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	print_status(t_philosopher *philo, char *status)
{
	long long	time_stamp;

	pthread_mutex_lock(&philo->rules->print_lock);
	if (!simulation_is_over(philo->rules))
	{
		time_stamp = get_curr_time() - philo->rules->start_time;
		printf("%lld %d %s\n", time_stamp, philo->id + 1, status);
	}
	pthread_mutex_unlock(&philo->rules->print_lock);
}

void	release_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	even_philo_takes_forks(t_philosopher *philo)
{
	int	right;
	int	left;

	right = pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken a fork");
	left = pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	if (right != 0 || left != 0)
		release_forks(philo);
}

void	odd_philo_takes_forks(t_philosopher *philo)
{
	int	right;
	int	left;

	left = pthread_mutex_lock(philo->left_fork);
	print_status(philo, "has taken a fork");
	right = pthread_mutex_lock(philo->right_fork);
	print_status(philo, "has taken a fork");
	if (right != 0 || left != 0)
		release_forks(philo);
}

void	someone_died(t_philosopher *philo)
{
	long long	time_stamp;

	time_stamp = get_curr_time() - philo->rules->start_time;
	pthread_mutex_lock(&philo->rules->print_lock);
	printf("%lld %d died\n", time_stamp, philo->id + 1);
	pthread_mutex_unlock(&philo->rules->print_lock);
	kill_simulation(philo->rules);
}
