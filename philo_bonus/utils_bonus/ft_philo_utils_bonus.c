/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 01:01:49 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/29 17:47:34 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

size_t	ft_mls(void)
{
	struct timeval	time;
	size_t			mls;

	gettimeofday(&time, NULL);
	mls = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (mls);
}

void	ft_sleep_thread(size_t sleep)
{
	size_t	init;

	init = ft_mls();
	while (ft_mls() - init < sleep)
		usleep(400);
}

void	ft_print(char *str, size_t time, size_t index, t_philo *philo)
{
	sem_wait(philo->print);
	if (philo->end)
		printf(str, time, index);
	sem_post(philo->print);
}

void	ft_take_fork(t_philo *philo, size_t index)
{
	sem_wait(philo->forks);
	ft_print("%zu %zu has taken a fork.\n", ft_mls(), index + 1, philo);
	sem_wait(philo->forks);
	ft_print("%zu %zu has taken a fork.\n", ft_mls(), index + 1, philo);
	philo->last_meal[index] = ft_mls();
	if (philo->argc == 6)
		philo->meal[index]++;
}

void	ft_put_fork(t_philo *philo)
{
	sem_post(philo->forks);
	sem_post(philo->forks);
}
