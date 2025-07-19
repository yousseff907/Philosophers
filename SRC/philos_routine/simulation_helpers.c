/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation_helpers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 22:18:55 by yitani            #+#    #+#             */
/*   Updated: 2025/07/19 22:20:58 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

void	kill_simulation(t_rules *rules)
{
	pthread_mutex_lock(&rules->death_lock);
	rules->someone_died = 1;
	pthread_mutex_unlock(&rules->death_lock);
}
