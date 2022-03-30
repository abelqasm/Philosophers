/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill_philo_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 01:00:06 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/30 17:06:43 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	ft_fill_meal(t_philo *philo, int argc, char **argv)
{
	if (argc == 6)
	{
		if (!ft_atoi(argv[5]))
			return (0);
		philo->n_meal = ft_atoi(argv[5]);
	}
	else
		philo->n_meal = 1;
	philo->meal = 0;
	return (1);
}

void	ft_create_sem(t_philo *philo)
{
	sem_unlink("forks");
	sem_unlink("print");
	philo->print = sem_open("print", O_CREAT, 0644, 1);
	if (philo->print == SEM_FAILED)
	{
		printf("Error while create semaphore.\n");
		exit(1);
	}
	philo->forks = sem_open("forks", O_CREAT, 0644, philo->n_philo);
	if (philo->forks == SEM_FAILED)
	{
		printf("Error while create semaphore.\n");
		exit(1);
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
	if (!ft_fill_meal(philo, argc, argv))
		return (0);
	philo->end = 1;
	ft_create_sem(philo);
	return (1);
}
