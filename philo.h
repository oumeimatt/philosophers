/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:37:35 by oel-yous          #+#    #+#             */
/*   Updated: 2021/09/12 16:09:00 by oel-yous         ###   ########.fr       */
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

typedef	struct s_philo
{
	int				philo_id;
	int				left_fork;
	int				right_fork;
	int				last_meal;
	int				eat_counter;
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
	pthread_mutex_t	*forks;
	t_philo			*philosopher;
	pthread_mutex_t	write;
	pthread_t		*thread;
}				t_args;
void	*routine();
long long	get_time();
void	ft_putnbr_fd(int n, int fd);
void    ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *s, int fd);
int		ft_isdigit(int c);
long	ft_atoi(char *str);

# endif