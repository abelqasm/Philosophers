/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_utils2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/26 21:59:27 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/28 03:41:58 by abelqasm         ###   ########.fr       */
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

void	ft_supervisor(t_philo *philo)
{
	size_t	i;
	int		proc_end;

	i = 0;
	while (i < philo->n_philo)
	{
		waitpid(-1, &proc_end, 0);
		if (proc_end == 1)
		{
			i = -1;
			while (++i < philo->n_philo)
				kill(philo->pids[i], SIGKILL);
			break ;
		}
		i++;
	}
}
