/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 01:01:49 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/27 18:17:21 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

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
		usleep(60);
}

int	ft_print(char *str, size_t time, size_t index, t_philo *philo)
{
	if (philo->error == 0)
		return (1);
	if (pthread_mutex_lock(&philo->print))
		return (0);
	if (philo->end)
		printf(str, time - philo->mls, index);
	if (pthread_mutex_unlock(&philo->print))
		return (0);
	return (1);
}

int	ft_take_fork(t_philo *philo, size_t index)
{
	if (philo->error == 0)
		return (1);
	if (pthread_mutex_lock(&philo->fork[index]))
		return (0);
	if (pthread_mutex_lock(&philo->fork[(index + 1) % philo->n_philo]))
		return (0);
	if (!ft_print("%zu %zu has taken a fork.\n", ft_mls(), index + 1, philo))
		return (0);
	if (!ft_print("%zu %zu has taken a fork.\n", ft_mls(), index + 1, philo))
		return (0);
	philo->last_meal[index] = ft_mls();
	if (philo->argc == 6)
		philo->meal[index]++;
	return (1);
}

int	ft_put_fork(t_philo *philo, size_t index)
{
	if (philo->error == 0)
		return (1);
	if (pthread_mutex_unlock(&philo->fork[index]))
		return (0);
	if (pthread_mutex_unlock(&philo->fork[(index + 1) % philo->n_philo]))
		return (0);
	return (1);
}
