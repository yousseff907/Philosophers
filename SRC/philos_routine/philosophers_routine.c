/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_routine.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 15:46:20 by yitani            #+#    #+#             */
/*   Updated: 2025/07/19 14:47:55 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*single_philosopher_routine(void *arg)
{
	
}

void	*philosopher_routine(void *arg)
{
	t_rules	*rules;

	rules = (t_rules *)arg;
	if (rules->number_of_philosophers == 1)
		handle_single_philosopher();
	// TODO: Implement philosopher behavior
	// - Think, eat, sleep cycle
	// - Handle fork acquisition/release
	// - Check for death conditions

	return (NULL);
}
