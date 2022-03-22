/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 02:54:00 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/22 20:33:20 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	
	philo = (t_philo *)arg;
	pthread_mutex_lock(philo->mutex);
	printf("threads created : %zu\n", philo->death);
	pthread_mutex_unlock(philo->mutex);
	return (NULL);
}

int	ft_create_thread(t_philo *philo, int n_philo)
{
	int	i;

	i = 0;
	philo->death = 50;
	philo->mutex = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(philo->mutex, NULL);
	philo->threads = (pthread_t *)malloc(sizeof(pthread_t) * n_philo);
	while (i < n_philo)
	{
		if (pthread_create(&philo->threads[i], NULL, routine, philo) != 0)
			return (0);
		i++;
	}
	i = 0;
	while (i < n_philo)
	{
		if (pthread_join(philo->threads[i], NULL) != 0)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_philo philo;
	
	if (argc != 5 && argc != 6)
	{
		printf("Incorrect number of arguments.\n");
		return (0);
	}
	if (!ft_fill_philo(&philo, argc, argv))
	{
		printf("Incorrect arguments.\n");
		return (0);
	}
	ft_create_thread(&philo, 3);
	return (0);
}
