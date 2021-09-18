/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/14 11:06:22 by oel-yous          #+#    #+#             */
/*   Updated: 2021/09/14 11:23:23 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_args	*init_args_struct(char **argv)
{
	t_args	*args;
	int		i;

	i = 0;
	args = malloc(sizeof(t_args));
	args->end = 0;
	args->nbr_of_philos = ft_atoi(argv[1]);
	args->time_to_die = ft_atoi(argv[2]);
	args->time_to_eat = ft_atoi(argv[3]);
	args->time_to_sleep = ft_atoi(argv[4]);
	args->thread = malloc(sizeof(pthread_t) * args->nbr_of_philos);
	args->forks = malloc(sizeof(pthread_mutex_t) * args->nbr_of_philos);
	args->curr_time = get_time();
	if (argv[5] != NULL)
		args->n_times_must_eat = ft_atoi(argv[5]);
	else
		args->n_times_must_eat = 100000000;
	return (args);
}

t_philo	*init_philosophers(t_args *args)
{
	t_philo	*philosopher;
	int		i;

	i = 0;
	philosopher = malloc(sizeof(t_philo) * args->nbr_of_philos);
	while (i < args->nbr_of_philos)
	{
		pthread_mutex_init(&philosopher[i].eat, NULL);
		philosopher[i].eat_counter = 0;
		philosopher[i].counter = 0;
		philosopher[i].last_meal = get_time();
		philosopher[i].philo_id = i + 1;
		philosopher[i].left_fork = i;
		philosopher[i].right_fork = (i + 1) % args->nbr_of_philos;
		philosopher[i].args = args;
		i++;
	}
	return (philosopher);
}

void	init_threads(t_philo *philosopher)
{
	int		i;

	pthread_mutex_init(&philosopher->args->write, NULL);
	i = 0;
	while (i < philosopher->args->nbr_of_philos)
	{
		pthread_mutex_init(&philosopher->args->forks[i], NULL);
		i++;
	}
	i = 0;
	while (i < philosopher->args->nbr_of_philos)
	{
		pthread_create(&philosopher->args->thread[i], NULL,
			&routine, &philosopher[i]);
		i++;
		usleep(100);
	}
}

t_args	*parse_args(int argc, char **argv)
{
	int		i;
	int		j;

	if (argc < 5 || argc > 6 || ft_atoi(argv[1]) == 0)
		return (NULL);
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isdigit(argv[i][j]))
				return (NULL);
			j++;
		}
		i++;
	}
	return (init_args_struct(argv));
}
