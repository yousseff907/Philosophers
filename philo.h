/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yitani <yitani@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/12 16:34:12 by yitani            #+#    #+#             */
/*   Updated: 2025/07/19 16:32:20 by yitani           ###   ########.fr       */
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

// Validation and parsing

void	initialize_vars(int argc, char **argv, t_rules *rules);

// Philosophers routine and behavior

void	*philosopher_routine(void *arg);
void	*single_philosopher_routine(void *arg);
int		take_right_fork(t_philosopher *philo);
int		take_left_fork(t_philosopher *philo);
int		take_both_forks(t_philosopher *philo);

// memory cleanup

void	cleanup_and_exit(t_rules *rules, int exit_code);

#endif