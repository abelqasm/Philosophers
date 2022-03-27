/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 02:54:00 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/27 03:41:51 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_routine(t_philo	*philo, size_t index)
{
	while (philo->end && philo->error)
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

int	ft_create_philo(t_philo *philo)
{
	size_t	i;

	i = 0;
	philo->last_meal = malloc(sizeof(size_t) * philo->n_philo);
	while (i < philo->n_philo)
	{
		philo->pids[i] = fork();
		i++;
	}
	if (!philo->last_meal)
		return (0);
	if (!ft_create_forks(philo, philo->n_philo))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
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
	if (!ft_create_philo(philo))
		return (0);
	return (0);
}
