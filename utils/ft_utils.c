/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:08:38 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/22 20:50:43 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

static long	check(unsigned long nb, int signe)
{
	if (nb <= 9223372036854775807)
		return (nb * signe);
	if (signe > 0)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	nb;
	int				signe;
	int				i;

	nb = 0;
	signe = 1;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\f') || (str[i] == '\v')
		|| (str[i] == '\t') || (str[i] == '\r') || (str[i] == '\n'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			signe = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	nb = check(nb, signe);
	return (nb);
}

int	ft_fill_philo(t_philo *philo, int argc, char **argv)
{
	if (ft_atoi(argv[1]) < 0)
		return (0);
	philo->n_philo = ft_atoi(argv[1]);
	if (ft_atoi(argv[2]) < 0)
		return (0);
	philo->death = ft_atoi(argv[2]);
	if (ft_atoi(argv[3]) < 0)
		return (0);
	philo->eat = ft_atoi(argv[3]);
	if (ft_atoi(argv[4]) < 0)
		return (0);
	philo->sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		if (!ft_atoi(argv[5]))
			return (0);
		philo->meal = ft_atoi(argv[5]);
	}
	return (1);
}
