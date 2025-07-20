/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:34:12 by yitani            #+#    #+#             */
/*   Updated: 2025/07/20 23:15:53 by yitani           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H

# define PHILO_H

// Libraries

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <string.h>
# include <pthread.h>

// Data structures

typedef struct s_rules	t_rules;

typedef struct s_philosopher
{
	int				id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	long long		last_meal_time;
	int				meals_eaten;
	t_rules			*rules;
}	t_philosopher;

typedef struct s_rules
{
	int				number_of_philosophers;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat;
	int				someone_died;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	pthread_mutex_t	death_lock;
	t_philosopher	**philosophers;
}	t_rules;

// General helpers functions

void	ft_putendl_fd(char *s, int fd);
int		ft_atoi(const char *str);
int		get_curr_time(void);

// Memory allocations and mutexes / threads initialization

t_rules	*allocate_rules(void);
void	initialize_threads(t_rules *rules);
void	allocate_philosophers(t_rules *rules, int nb_philo);
void	initialize_mutexes(t_rules *rules);
void	allocate_forks(t_rules *rules);

// Validation and parsing

void	initialize_vars(int argc, char **argv, t_rules *rules);

// Philosophers routine and behavior

void	*philosopher_routine(void *arg);
void	*single_philosopher_routine(void *arg);
void	print_status(t_philosopher *philo, char *status);
void	someone_died(t_philosopher *philo);
void	release_forks(t_philosopher *philo);
void	even_philo_takes_forks(t_philosopher *philo);
void	odd_philo_takes_forks(t_philosopher *philo);

// Simulation helpers

void	kill_simulation(t_rules *rules);
int		simulation_is_over(t_rules *rules);
void	update_mealtime_run_monitor(t_philosopher *philo);
void	my_usleep(t_rules *rules, int duration);
void	philo_is_sleeping(t_philosopher *philo);

// Simulation monitoring

void	run_monitor(t_rules *rules);

// memory cleanup

void	cleanup_and_exit(t_rules *rules, int exit_code);

#endif