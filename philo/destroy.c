/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:10:43 by oel-yous          #+#    #+#             */
/*   Updated: 2021/09/14 11:10:58 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_philo *philosopher)
{
	int		i;

	pthread_mutex_destroy(&philosopher->args->write);
	i = 0;
	while (i < philosopher->args->nbr_of_philos)
	{
		pthread_mutex_destroy(&philosopher->args->forks[i]);
		pthread_mutex_destroy(&philosopher[i].eat);
		i++;
	}
}
