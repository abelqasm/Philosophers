/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:59:27 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/27 14:25:18 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

int	ft_check_death(t_philo *philo, size_t last_meal, size_t index)
{
	if (ft_mls() - last_meal > philo->death)
	{
		printf("%zu %zu has died.\n", ft_mls(), index + 1);
		return (0);
	}
	return (1);
}

int	ft_manager(t_philo *philo)
{
	size_t	i;

	i = 0;
	while (philo->end)
	{
		philo->end = ft_check_death(philo, philo->last_meal[i], i);
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
