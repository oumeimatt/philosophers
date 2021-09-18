/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:11:57 by oel-yous          #+#    #+#             */
/*   Updated: 2021/09/14 11:29:43 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	end_of_simulation(t_philo *philosopher)
{
	int	i;

	i = 0;
	while (i < philosopher->args->nbr_of_philos)
	{
		if (get_time() - philosopher[i].last_meal
			>= philosopher->args->time_to_die)
		{
			pthread_mutex_lock(&philosopher[i].eat);
			ft_display("died", &philosopher[i]);
			pthread_mutex_unlock(&philosopher[i].eat);
			philosopher->args->end = 1;
			return ;
		}
		i++;
	}
}

void	optional_end_of_simulation(t_philo *philosopher, int *j)
{
	while (*j < philosopher->args->nbr_of_philos)
	{
		if (philosopher[*j].eat_counter >= philosopher->args->n_times_must_eat)
			philosopher[*j].counter = 1;
		(*j)++;
	}
}

void	supervisor(t_philo *philosopher)
{
	int	j;
	int	i;

	j = 0;
	while (1)
	{
		end_of_simulation(philosopher);
		optional_end_of_simulation(philosopher, &j);
		i = 0;
		while (i < philosopher->args->nbr_of_philos)
		{
			if (philosopher[i].counter == 0)
			{
				j = 0;
				break ;
			}
			i++;
		}
		if (j != 0 || philosopher->args->end == 1)
			break ;
	}
}
