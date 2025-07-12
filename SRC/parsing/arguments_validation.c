/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:34:03 by yitani            #+#    #+#             */
/*   Updated: 2025/07/13 01:44:11 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	*validate_args(int argc, char **argv, t_rules *rules, long long *val)
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

void	join_philosophers(t_philosopher *philos)
{
	int	i;

	i = 0;
	pthread_join(philos[i].id, NULL);
}

void	initialize_vars(int argc, char **argv, t_rules *rules)
{
	long long		val[5];
	struct timeval	tv;
	
	rules = malloc(sizeof(t_rules));
	if (!rules)
		cleanup_and_exit(rules, 1);
	validate_args(argc, argv, rules, val);
	rules->number_of_philosophers = val[0];
	rules->time_to_die = val[1];
	rules->time_to_eat = val[2];
	rules->time_to_sleep = val[3];
	rules->must_eat = val[4];
	gettimeofday(&tv, NULL);
	rules->start_time = (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
	rules->philosophers = malloc(sizeof(t_philosopher) * rules->number_of_philosophers);
	if (!rules->philosophers)
		cleanup_and_exit(rules, 1);
}
