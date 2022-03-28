/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 02:54:17 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/28 00:52:26 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>
# include <semaphore.h>

typedef struct s_philo
{
	pid_t			*pids;
	sem_t			*forks;
	sem_t			*print;
	size_t			n_philo;
	size_t			death;
	size_t			sleep;
	size_t			eat;
	size_t			n_meal;
	size_t			*meal;
	size_t			philo;
	size_t			argc;
	size_t			*last_meal;
}	t_philo;
int		ft_atoi(const char *str);
int		ft_fill_philo(t_philo *philo, int argc, char **argv);
void	ft_take_fork(t_philo *philo, size_t index);
void	ft_put_fork(t_philo *philo);
void	ft_print(char *str, size_t time, size_t index, t_philo *philo);
void	ft_sleep_thread(size_t sleep);
size_t	ft_mls(void);

#endif