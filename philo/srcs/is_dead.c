/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aribesni <aribesni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 20:29:16 by aribesni          #+#    #+#             */
/*   Updated: 2022/01/12 16:39:50 by aribesni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_count_meals(t_philo *philo)
{
	int	done;
	int	i;

	if (philo->nb_meal != -1 && philo->total_meals > 0)
	{
		done = 1;
		i = 0;
		while (i < philo->nb_philo)
		{
			if (philo[i].nb_meal < philo->total_meals)
				done = 0;
			i++;
		}
		if (done == 1)
		{
			i = 0;
			while (i < philo[i].nb_philo)
			{
				philo[i].stop = 1;
				i++;
			}
			return (1);
		}
	}
	return (0);
}

static void	ft_philo_died(t_philo *philo, int i)
{
	philo->arg->dead = 1;
	pthread_mutex_lock(&philo->print_status);
	printf("%ldms Philo %d died\n", ft_get_time() - philo->start,
		philo[i].philo_id + 1);
	i = 0;
	while (i < philo[i].nb_philo)
	{
		philo[i].stop = 1;
		i++;
	}
	pthread_mutex_unlock(&philo->print_status);
}

void	*ft_is_dead(void *args)
{
	int			i;
	long int	time;
	t_philo		*philo;

	i = 0;
	philo = (t_philo *)args;
	while (philo[i].stop == 0)
	{
		i = 0;
		while (i < philo->nb_philo)
		{
			time = ft_get_time();
			if (time - philo[i].prev_meal > philo[i].life)
			{
				ft_philo_died(philo, i);
				pthread_mutex_unlock(&philo->print_status);
				return (NULL);
			}
			i++;
		}
		if (ft_count_meals(philo) || philo->stop)
			return (NULL);
	}
	return (NULL);
}
