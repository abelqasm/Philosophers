/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_philo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 01:00:06 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/27 19:47:23 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_fill_meal(t_philo *philo)
{
	size_t	i;

	i = 0;
	philo->meal = malloc(sizeof(size_t) * philo->n_philo);
	while (i < philo->n_philo)
	{
		philo->meal[i] = 0;
		i++;
	}
}

int	ft_fill_philo(t_philo *philo, int argc, char **argv)
{
	if (!ft_atoi(argv[1]))
		return (0);
	philo->n_philo = ft_atoi(argv[1]);
	if (!ft_atoi(argv[2]))
		return (0);
	philo->death = ft_atoi(argv[2]);
	if (!ft_atoi(argv[3]))
		return (0);
	philo->eat = ft_atoi(argv[3]);
	if (!ft_atoi(argv[4]))
		return (0);
	philo->sleep = ft_atoi(argv[4]);
	if (argc == 6)
	{
		if (!ft_atoi(argv[5]))
			return (0);
		philo->n_meal = ft_atoi(argv[5]);
	}
	else
		philo->n_meal = 1;
	ft_fill_meal(philo);
	if (philo->n_philo == 1)
		philo->end = 0;
	return (1);
}

int	ft_create_forks(t_philo *philo, int n_philo)
{
	int	i;

	i = -1;
	philo->fork = malloc(sizeof(pthread_mutex_t) * n_philo);
	while (++i < n_philo)
	{
		if (pthread_mutex_init(&philo->fork[i], NULL))
			return (0);
	}
	if (pthread_mutex_init(&philo->print, NULL))
		return (0);
	return (1);
}
