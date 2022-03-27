/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 02:54:00 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/27 13:49:02 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *arg)
{
	t_philo	*philo;
	size_t	index;

	philo = arg;
	index = philo->philo;
	philo->last_meal[index] = ft_mls();
	while (philo->end && philo->error && (philo->meal[index] < philo->n_meal))
	{
		if (!ft_take_fork(philo, index))
			ft_destroy(philo, 0, &philo->error);
		if (!ft_print("%zu %zu is eating.\n", ft_mls(), index + 1, philo))
			ft_destroy(philo, 0, &philo->error);
		if (philo->error)
			ft_sleep_thread(philo->eat);
		if (!ft_put_fork(philo, index))
			ft_destroy(philo, 0, &philo->error);
		if (!ft_print("%zu %zu is sleeping.\n", ft_mls(), index + 1, philo))
			ft_destroy(philo, 0, &philo->error);
		if (philo->error)
			ft_sleep_thread(philo->sleep);
		if (!ft_print("%zu %zu is thinking.\n", ft_mls(), index + 1, philo))
			ft_destroy(philo, 0, &philo->error);
	}
	return (NULL);
}

int	ft_create_thread(t_philo *philo)
{
	philo->philo = 0;
	philo->error = 1;
	philo->threads = malloc(sizeof(pthread_t) * philo->n_philo);
	if (!philo->threads)
		return (0);
	philo->last_meal = malloc(sizeof(size_t) * philo->n_philo);
	if (!philo->last_meal)
		return (0);
	if (!ft_create_forks(philo, philo->n_philo))
		return (0);
	while (philo->philo < philo->n_philo)
	{
		if (pthread_create(&philo->threads[philo->philo], NULL,
				ft_routine, philo) != 0)
			return (0);
		usleep(100);
		philo->philo++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	philo->argc = argc;
	if (!philo)
		return (0);
	philo->end = 1;
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
	if (!ft_create_thread(philo))
		return (0);
	if (!ft_manager(philo))
		return (0);
	ft_destroy(philo, 1, NULL);
	return (0);
}
