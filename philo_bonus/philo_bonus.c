/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 02:54:00 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/29 17:54:33 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	*ft_manage(void *arg)
{
	t_philo	*philo;

	philo = arg;
	while (1)
	{
		if (ft_mls() - philo->last_meal[philo->philo] >= philo->death)
		{
			ft_print("%zu %zu has died.\n", ft_mls(), philo->philo + 1, philo);
			philo->end = 0;
			exit(0);
		}
		if (philo->meal[philo->philo] == philo->n_meal)
			exit(1);
	}
	return (NULL);
}

void	ft_philo(t_philo *philo)
{
	pthread_t	thread;

	philo->last_meal[philo->philo] = ft_mls();
	printf("1\n");
	pthread_create(&thread, NULL, ft_manage, philo);
	while (1)
	{
		ft_take_fork(philo, philo->philo);
		ft_print("%zu %zu is eating.\n", ft_mls(), philo->philo + 1, philo);
		ft_sleep_thread(philo->eat);
		ft_put_fork(philo);
		ft_print("%zu %zu is sleeping.\n", ft_mls(), philo->philo + 1, philo);
		ft_sleep_thread(philo->sleep);
		ft_print("%zu %zu is thinking.\n", ft_mls(), philo->philo + 1, philo);
	}
}

int	ft_create_philo(t_philo *philo)
{
	philo->philo = 0;
	philo->last_meal = malloc(sizeof(size_t) * philo->n_philo);
	if (!philo->last_meal)
		return (0);
	philo->pids = malloc(sizeof(pid_t) * philo->n_philo);
	if (!philo->pids)
		return (0);
	if (!philo->last_meal)
		return (0);
	while (philo->philo < philo->n_philo)
	{
		philo->pids[philo->philo] = fork();
		if (philo->pids[philo->philo] == 0)
			ft_philo(philo);
		philo->philo++;
		usleep(100);
	}
	ft_supervisor(philo);
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (0);
	philo->argc = argc;
	if (argc != 5 && argc != 6)
	{
		printf("Incorrect number of arguments.\n");
		return (0);
	}
	if (!ft_fill_philo(philo, argc, argv))
	{
		printf("Incorrect arguments.\n");
		return (0);
	}
	if (!ft_create_philo(philo))
		return (0);
	return (0);
}
