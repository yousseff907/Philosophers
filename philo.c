/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:34:09 by yitani            #+#    #+#             */
/*   Updated: 2025/07/21 09:38:38 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_rules	*rules;
	int		i;

	i = 0;
	rules = allocate_rules();
	initialize_vars(argc, argv, rules);
	while (i < rules->number_of_philosophers)
	{
		pthread_join(rules->philosophers[i]->thread, NULL);
		i++;
	}
	run_monitor(rules);
	return (0);
}
