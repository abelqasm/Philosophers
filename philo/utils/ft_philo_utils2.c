/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:59:27 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/29 21:08:47 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_check_death(t_philo *philo, size_t last_meal, size_t index)
{
	if (ft_mls() - last_meal >= philo->death)
	{
		ft_print("%zu %zu has died.\n", index + 1, philo);
		return (0);
	}
	return (1);
}

int	ft_check_meal(t_philo *philo)
{
	size_t	i;

	i = 0;
	while (i < philo->n_philo)
	{
		if (!(philo->meal[i] == philo->n_meal))
			return (1);
		i++;
	}
	return (0);
}

int	ft_manager(t_philo *philo)
{
	size_t	i;

	i = 0;
	if (!philo->end)
	{
		printf("%d %d has taken a fork.\n", 0, 1);
		ft_sleep_thread(philo->death);
		printf("%zu %d has died.\n", philo->death, 1);
	}
	while (philo->end)
	{
		if (!(philo->meal[i] == philo->n_meal))
			philo->end = ft_check_death(philo, philo->last_meal[i], i);
		else
			philo->end = ft_check_meal(philo);
		i = (i + 1) % philo->n_philo;
	}
	i = -1;
	while (++i < philo->n_philo)
	{
		if (pthread_join(philo->threads[i], NULL))
			return (0);
	}
	return (1);
}

void	ft_destroy(t_philo *philo, int index, int *error)
{
	size_t	i;

	i = -1;
	if (index == 0)
		printf("Error while processing.\n");
	if (error != NULL)
		*error = 0;
	while (++i < philo->n_philo)
		pthread_mutex_destroy(&philo->fork[i]);
}
