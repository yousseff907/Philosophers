/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_validation.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:34:03 by yitani            #+#    #+#             */
/*   Updated: 2025/07/22 18:29:23 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../philo.h"

static char	*error_message(void)
{
	char	*error;

	error = "Error: enter 4-5 positive numerical arguments.\n\
First argument: number_of_philosophers.\n\
Second argument: time_to_die.\n\
Third argument: time_to_eat.\n\
Fourth argument: time_to_sleep.\n\
Fifth argument(optional): \
[number_of_times_each_philosopher_must_eat].\n";
	return (error);
}

static int	valid_args(int argc, char **argv, t_rules *rules, int *val)
{
	int	count;

	count = 0;
	if (argc < 5 || argc > 6)
		return (printf("%s", error_message()), free(rules), (1));
	if (argc - 1 == 4)
		rules->must_eat = -1;
	else
		rules->must_eat = 0;
	while (count < argc - 1)
	{
		val[count] = ft_atoi(argv[count + 1]);
		if (val[count] <= 0)
			return (printf("%s", error_message()), free(rules), (1));
		count++;
	}
	return (0);
}

static void	init_philos_content(t_rules *rules)
{
	int	i;
	int	philos;

	philos = rules->number_of_philosophers;
	i = 0;
	while (i < philos)
	{
		rules->philosophers[i]->id = i;
		rules->philosophers[i]->left_fork = &rules->forks[i];
		rules->philosophers[i]->right_fork = &rules->forks[(i + 1) % philos];
		rules->philosophers[i]->last_meal_time = rules->start_time;
		rules->philosophers[i]->meals_eaten = 0;
		rules->philosophers[i]->rules = rules;
		i++;
	}
}

int	initialize_vars(int argc, char **argv, t_rules *rules)
{
	int	val[5];
	int	count;

	count = 0;
	while (count < 5)
	{
		val[count] = 0;
		count++;
	}
	if (valid_args(argc, argv, rules, val) != 0)
		return (1);
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
	return (0);
}
