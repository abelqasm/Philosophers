/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 02:54:17 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/27 02:12:52 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_mutex_t	*fork;
	pthread_mutex_t	print;
	pthread_t		*threads;
	size_t			n_philo;
	size_t			death;
	size_t			sleep;
	size_t			eat;
	size_t			philo;
	size_t			meal;
	size_t			ded;
	size_t			*last_meal;
	int				error;
}	t_philo;
int		ft_atoi(const char *str);
int		ft_fill_philo(t_philo *philo, int argc, char **argv);
int		ft_check_death(t_philo *philo, size_t last_meal, size_t index);
int		ft_manager(t_philo *philo);
int		ft_create_forks(t_philo *philo, int n_philo);
int		ft_take_fork(t_philo *philo, size_t index);
int		ft_put_fork(t_philo *philo, size_t index);
int		ft_print(char *str, size_t time, size_t index, t_philo *philo);
void	ft_sleep_thread(size_t sleep);
void	ft_destroy(t_philo *philo, int index, int *error);
size_t	ft_mls(void);

#endif