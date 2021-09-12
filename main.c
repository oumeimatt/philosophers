/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:19:48 by oel-yous          #+#    #+#             */
/*   Updated: 2021/09/12 16:05:43 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


t_args	*init_args_struct(char **argv)
{
	t_args *args;
	int		i;

	i = 0;	
	args = malloc(sizeof(t_args));
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
		args->n_times_must_eat = -1;
	return (args);
}

t_philo	*init_philosophers(t_args *args)
{
	t_philo *philosopher;
	int		i;
	
	i = 0;
	philosopher = malloc(sizeof(t_philo) * args->nbr_of_philos);
	while (i < args->nbr_of_philos)
	{
		philosopher[i].eat_counter = 0;
		philosopher[i].philo_id = i + 1;
		philosopher[i].left_fork = i  % args->nbr_of_philos;
		philosopher[i].right_fork = (i + 1) % args->nbr_of_philos;
		philosopher[i].args = args;
		i++;
	}
	return (philosopher);
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
	return(init_args_struct(argv));
}

int	main(int argc, char **argv)
{
	t_args			*args;
	int				i = 1;
	t_philo			*philosopher;
	pthread_t		t_id;
	args = parse_args(argc, argv);
	if (!args)
	{
		printf("Invalid Arguments\n");
		return (1);
	}
	philosopher = init_philosophers(args);
	while (i < args->nbr_of_philos)
	{
		pthread_mutex_init(&args->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&args->write, NULL);
	i = 0;
	while (i < args->nbr_of_philos)
	{
		pthread_create(&t_id, NULL, &routine, &philosopher[i]);
		i++;
		usleep(100);
	}
	while (1);
}
