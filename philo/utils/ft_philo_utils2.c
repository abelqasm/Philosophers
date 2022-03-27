/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utils2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:59:27 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/26 22:48:20 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	ft_manager(t_philo *philo)
{
	size_t	i;

	i = 0;
	while (philo->ded)
	{
		philo->ded = ft_check_death(philo, philo->last_meal[i], i);
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

void	ft_sleep_thread(size_t sleep)
{
	size_t	init;

	init = ft_mls();
	while (ft_mls() - init < sleep)
		usleep(10);
}

void	ft_destroy(t_philo *philo, int index)
{
	int	i;

	i = 0;
	if (indnex == 0)
		printf("Error while processing.\n");
	while (i < philo->n_philo)
	{
		pthread
	}
}
