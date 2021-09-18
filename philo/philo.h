/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:37:35 by oel-yous          #+#    #+#             */
/*   Updated: 2021/09/14 11:25:12 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <pthread.h> 
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>

typedef struct s_philo
{
	int				philo_id;
	int				left_fork;
	int				right_fork;
	long long		last_meal;
	int				eat_counter;
	int				counter;
	pthread_mutex_t	eat;
	struct s_args	*args;
}				t_philo;

typedef struct s_args
{
	int				nbr_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				n_times_must_eat;
	long long		curr_time;
	int				end;
	pthread_mutex_t	*forks;
	t_philo			*philosopher;
	pthread_mutex_t	write;
	pthread_t		*thread;
}				t_args;

int			ft_isdigit(int c);
long		ft_atoi(char *str);
void		ft_display(char *msg, t_philo *philosopher);
long long	get_time(void);

t_args		*init_args_struct(char **argv);
t_philo		*init_philosophers(t_args *args);
void		init_threads(t_philo *philosopher);
t_args		*parse_args(int argc, char **argv);

void		ft_usleep(int time_to);
void		ft_think(t_philo *philosopher);
void		ft_sleep(t_philo *philosopher);
void		ft_eat(t_philo *philosopher);
void		*routine(void *arg);

void		end_of_simulation(t_philo *philosopher);
void		optional_end_of_simulation(t_philo *philosopher, int *j);
void		supervisor(t_philo *philosopher);

void		destroy_mutex(t_philo *philosopher);

#endif
