/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oel-yous <oel-yous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/07 11:41:09 by oel-yous          #+#    #+#             */
/*   Updated: 2021/09/07 14:33:08 by oel-yous         ###   ########.fr       */
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

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void	ft_putendl_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		ft_putchar_fd(s[i], fd);
		i++;
	}
	ft_putchar_fd('\n', fd);
}

void    ft_putstr_fd(char *str, int fd)
{
	int     i;

	i = 0;
	while(str[i] !='\0')
	{
		ft_putchar_fd(str[i], fd);
		i++;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	nbr;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		nbr = -n;
	}
	else
		nbr = n;
	if (nbr >= 10)
	{
		ft_putnbr_fd(nbr / 10, fd);
		ft_putnbr_fd(nbr % 10, fd);
	}
	else
		ft_putchar_fd(nbr + '0', fd);
}