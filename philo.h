/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 02:54:17 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/22 20:29:57 by abelqasm         ###   ########.fr       */
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
	pthread_mutex_t	*mutex;
	pthread_t		*threads;
	size_t			n_philo;
	size_t			death;
	size_t			sleep;
	size_t			eat;
	size_t			meal;
}	t_philo;
int	ft_printf(const char *str, ...);
int	ft_atoi(const char *str);
int	ft_fill_philo(t_philo *philo, int argc, char **argv);

#endif