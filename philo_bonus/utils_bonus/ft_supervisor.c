/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supervisor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:59:27 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/30 17:00:49 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_close_sem(t_philo *philo)
{
	sem_close(philo->print);
	sem_close(philo->forks);
	sem_unlink("forks");
	sem_unlink("print");
}

void	ft_supervisor(t_philo *philo)
{
	size_t	i;
	int		proc_end;

	i = 0;
	while (i < philo->n_philo)
	{
		waitpid(-1, &proc_end, 0);
		if (!proc_end)
		{
			i = -1;
			while (++i < philo->n_philo)
				kill(philo->pids[i], SIGKILL);
			break ;
		}
		i++;
	}
	ft_close_sem(philo);
}
