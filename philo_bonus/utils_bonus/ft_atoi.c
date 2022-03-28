/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelqasm <abelqasm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 18:08:38 by abelqasm          #+#    #+#             */
/*   Updated: 2022/03/27 14:25:06 by abelqasm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

static int	check_num(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (0);
		i++;
	}
	return (1);
}

static long	check(unsigned long nb, int signe)
{
	if (nb <= 9223372036854775807)
		return (nb * signe);
	if (signe > 0)
		return (-1);
	return (0);
}

int	ft_atoi(const char *str)
{
	unsigned long	nb;
	int				signe;
	int				i;

	nb = 0;
	signe = 1;
	i = 0;
	while ((str[i] == ' ') || (str[i] == '\f') || (str[i] == '\v')
		|| (str[i] == '\t') || (str[i] == '\r') || (str[i] == '\n'))
		i++;
	if (!check_num(str))
		return (0);
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	nb = check(nb, signe);
	return (nb);
}
