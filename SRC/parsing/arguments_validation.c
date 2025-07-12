/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:34:03 by yitani            #+#    #+#             */
/*   Updated: 2025/07/12 18:48:13 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	*validate_args(int argc, char **argv, t_rules *rules, int *val)
{
	int	count;

	count = 0;
	if (argc != 6)
	{
		ft_putendl_fd("Error : enter 5 arguments", 2);
		exit(1);
	}
	while (count < 5)
	{
		val[count] = ft_atoi(argv[count]);
		if (!val[count])
		{
			ft_putendl_fd("Error : enter numerical non zero arguments", 2);
			exit(1);
		}
		count++;
	}
	return(val);
}

void	initialize_vars(int argc, char **argv, t_rules *rules)
{
	int	val[5];
	
	validate_args(argc, argv, rules, val);
	rules->number_of_philosophers = val[0];
	rules->time_to_die = val[1];
	rules->time_to_eat = val[2];
	rules->time_to_sleep = val[3];
	rules->must_eat = val[4];
	rules->start_time = gettimeofday();
}