/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:41:09 by oel-yous          #+#    #+#             */
/*   Updated: 2021/09/14 11:31:36 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_isdigit(int c)
{
	if (c >= 48 && c <= 57)
		return (1);
	return (0);
}

long	ft_atoi(char *str)
{
	int					signe;
	unsigned long long	r;

	while (*str >= 9 && *str <= 32)
		str++;
	signe = 1;
	if (*str == '-')
	{
		signe = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	r = 0;
	while (*str >= 48 && *str <= 57)
	{
		r = r * 10 + *str - '0';
		if ((unsigned long long )r > 9223372036854775808U)
			return (0);
		str++;
	}
	r = r * signe;
	return (r);
}

void	ft_display(char *msg, t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->args->write);
	printf("%lld : philosopher %d %s \n",
		get_time() - philosopher->args->curr_time, philosopher->philo_id, msg);
	if (msg[0] != 'd')
		pthread_mutex_unlock(&philosopher->args->write);
}

long long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((((long long)tv.tv_sec) * 1000) + (tv.tv_usec / 1000));
}
