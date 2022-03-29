/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_supervisor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:59:27 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/29 19:19:31 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

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
}
