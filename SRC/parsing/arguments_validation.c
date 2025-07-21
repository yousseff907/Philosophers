/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:34:03 by yitani            #+#    #+#             */
/*   Updated: 2025/07/21 17:06:38 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static void	valid_args(int argc, char **argv, t_rules *rules, int *val)
{
	int	count;

	count = 0;
	if (argc < 5 || argc > 6)
		return (printf("Error : enter 5 arguments"), free(rules), exit(1));
	if (argc == 5)
		rules->must_eat = -1;
	else
		rules->must_eat = 0;
	while (count < argc - 1)
	{
		val[count] = ft_atoi(argv[count + 1]);
		if (val[count] <= 0)
		{
			return (printf("Error : enter 5 arguments"), free(rules), exit(1));
		}
		count++;
	}
}

static void	init_philos_content(t_rules *rules)
{
	int	i;
	int	philocnt;

	philocnt = rules->number_of_philosophers;
	i = 0;
	while (i < rules->number_of_philosophers)
	{
		rules->philosophers[i]->id = i;
		rules->philosophers[i]->left_fork = &rules->forks[i];
		rules->philosophers[i]->right_fork = &rules->forks[(i + 1) % philocnt];
		rules->philosophers[i]->last_meal_time = rules->start_time;
		rules->philosophers[i]->meals_eaten = 0;
		rules->philosophers[i]->rules = rules;
		i++;
	}
}

void	create_monitor_thread(t_rules *rules)
{
	if (pthread_create(&rules->monitor_thread, NULL, run_monitor, rules) != 0)
	{
		ft_putendl_fd("Error: Failed to create monitor thread", 2);
		cleanup_and_exit(rules, 1);
	}
}

void	initialize_vars(int argc, char **argv, t_rules *rules)
{
	int	val[5];
	int	count;

	count = 0;
	while (count < 5)
	{
		val[count] = 0;
		count++;
	}
	valid_args(argc, argv, rules, val);
	rules->number_of_philosophers = val[0];
	rules->time_to_die = val[1];
	rules->time_to_eat = val[2];
	rules->time_to_sleep = val[3];
	rules->someone_died = 0;
	if (rules->must_eat != -1)
		rules->must_eat = val[4];
	rules->start_time = get_curr_time();
	allocate_forks(rules);
	initialize_mutexes(rules);
	allocate_philosophers(rules, val[0]);
	init_philos_content(rules);
	initialize_threads(rules);
	create_monitor_thread(rules);
}
