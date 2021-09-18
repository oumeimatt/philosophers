/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/06 12:19:48 by oel-yous          #+#    #+#             */
/*   Updated: 2021/09/14 11:11:13 by oel-yous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args			*args;
	t_philo			*philosopher;

	args = parse_args(argc, argv);
	if (!args)
	{
		printf("Invalid arguments\n");
		return (1);
	}
	philosopher = init_philosophers(args);
	init_threads(philosopher);
	supervisor(philosopher);
	destroy_mutex(philosopher);
	return (0);
}
