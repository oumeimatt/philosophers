/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 12:28:47 by oel-yous          #+#    #+#             */
/*   Updated: 2021/09/14 11:27:58 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(int time_to)
{
	long long	time;

	time = get_time();
	usleep((time_to - 10) * 1000);
	while (get_time() - time < time_to)
		;
}

void	ft_think(t_philo *philosopher)
{
	ft_display("is thinking", philosopher);
}

void	ft_sleep(t_philo *philosopher)
{
	ft_display("is sleeping", philosopher);
	ft_usleep(philosopher->args->time_to_sleep);
}

void	ft_eat(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->args->forks[philosopher->left_fork]);
	ft_display("has taken left fork", philosopher);
	pthread_mutex_lock(&philosopher->args->forks[philosopher->right_fork]);
	ft_display("has taken right fork", philosopher);
	pthread_mutex_lock(&philosopher->eat);
	ft_display("is eating", philosopher);
	philosopher->last_meal = get_time();
	philosopher->eat_counter++;
	ft_usleep(philosopher->args->time_to_eat);
	pthread_mutex_unlock(&philosopher->eat);
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
	return (NULL);
}
