/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:28:47 by oel-yous          #+#    #+#             */
/*   Updated: 2021/09/12 16:03:01 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	ft_display(char *msg, t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->args->write);
	printf("%lld : philosopher %d %s \n", get_time() - philosopher->args->curr_time, philosopher->philo_id, msg);
	pthread_mutex_unlock(&philosopher->args->write);
}

long long	get_time()
{
    struct timeval tv;

    gettimeofday(&tv,NULL);
    return ((((long long)tv.tv_sec) * 1000) + (tv.tv_usec / 1000));
}

void    ft_think(t_philo *philosopher)
{
	ft_display("is thinking", philosopher);
}

void	ft_sleep(t_philo *philosopher)
{
	ft_display("is sleeping", philosopher);
	usleep(philosopher->args->time_to_sleep * 1000); 
}

void	ft_eat(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->args->forks[philosopher->left_fork]);
	ft_display("has taken left fork", philosopher);
	pthread_mutex_lock(&philosopher->args->forks[philosopher->right_fork]);
	ft_display("has taken right fork", philosopher);
	ft_display("is eating", philosopher);
	philosopher->eat_counter++;
	usleep(philosopher->args->time_to_eat * 1000);
	pthread_mutex_unlock(&philosopher->args->forks[philosopher->left_fork]);
	pthread_mutex_unlock(&philosopher->args->forks[philosopher->right_fork]);
}

void	*routine(void *arg)
{
	t_philo	*philosopher;
	philosopher = (t_philo *)arg;
	while (1)
	{
		ft_think(philosopher);
		ft_eat(philosopher);
		ft_sleep(philosopher);
		usleep(100);
	}
	// free(arg);
	return (NULL);
}

